#include "itemmodel.h"
#include <QBrush>
#include <QDebug>
#include <phonon/phonon>

ItemModel::ItemModel(QObject *parent) : QAbstractItemModel(parent)
{
    itemList = new QList<Item>();
    nextAuctionTimer    = new QTimer(this);
    generalTimer        = new QTimer(this);
    connect(nextAuctionTimer, SIGNAL(timeout()), this, SLOT(updateNextAuction()));
    connect(generalTimer, SIGNAL(timeout()), this, SLOT(updateGeneralTimer()));
    connect(this, SIGNAL(notifyAuctionSoonEnding(int)), this, SLOT(updateAuctionSoonEnding(int)));
    nextAuctionTimer->start(1000);
    generalTimer->start(5000);
}

void ItemModel::updateNextAuction()
{
    if(!itemList->empty())
    {
        int numberOfRows = itemList->size();
        for (int i = 0; i < numberOfRows; i++)
        {
            if ((*itemList)[i].updateAndGetRemainingTime() <= 0 ) // Auction ended, move or delete it!
            {
                beginRemoveRows(QModelIndex(), i, i);
                itemList->removeAt(i);
                endRemoveRows();
                numberOfRows--; // Deleted an item, number of rows decreased
                if( numberOfRows == 0 )
                    break;
                else
                    continue;
            }

            else if ((*itemList)[i].updateAndGetRemainingTime() < 300000) // 300000 = 5 mins in ms's.
            {
                (*itemList)[i].setEndingSoonStatus(true);
                if(!(*itemList)[i].isUserWarned())
                {
                    emit warnUserWithSound(true);
                    (*itemList)[i].setUserWarned(true);
                }
                emit notifyAuctionSoonEnding(i);
            }

            else if ((*itemList)[i].updateAndGetRemainingTime() < 1800000) // 1800000 = 30 mins in ms's.)
            {
                if(!(*itemList)[i].isUserWarned30Min())
                {
                    emit warnUserWithSound(true);
                    (*itemList)[i].setUserWarned30Min(true);
                }
                emit notifyAuctionSoonEnding(i);
            }

            else if ((*itemList)[i].updateAndGetRemainingTime() < 3600000) // 3600000 = 60 mins in ms's.)
            {
                if(!(*itemList)[i].isUserWarned60Min())
                {
                    emit warnUserWithSound(true);
                    (*itemList)[i].setUserWarned60Min(true);
                }
                emit notifyAuctionSoonEnding(i);
            }

            else
                break;
        }
        if(!itemList->empty())
            emit updateNextAuctionTimer(itemList->first().getTimeLeft(true));
    }
}

void ItemModel::updateGeneralTimer()
{
    for (int i = 0; i < itemList->size(); i++)
    {
        QModelIndex cellWithTimer = createIndex(i, 3);
        emit dataChanged(cellWithTimer, cellWithTimer);
    }
}

void ItemModel::updateAuctionSoonEnding(int auctionLocationInList)
{
    QModelIndex cellWithTimer = createIndex(auctionLocationInList, 3);
    emit dataChanged(cellWithTimer, cellWithTimer);
}

void ItemModel::addItem(Item *item)
{
    if(itemList->isEmpty())
    {
        beginInsertRows(QModelIndex(), itemList->size(), itemList->size());
        itemList->append(*item);
        endInsertRows();
    }
    else
    {
        for (int i = 0; i < itemList->size(); i++)
        {
            if ((*itemList)[i].updateAndGetRemainingTime() > item->updateAndGetRemainingTime())
            {
                beginInsertRows(QModelIndex(), i, i);
                itemList->insert(i, *item);
                endInsertRows();
                break;
            }
            else if (i == (itemList->size() - 1))
            {
                beginInsertRows(QModelIndex(), itemList->size(), itemList->size());
                itemList->append(*item);
                endInsertRows();
                break;
            }
        }
    }
}

void ItemModel::removeItem(QModelIndexList rows)
{
    if (!rows.isEmpty())
    {
        // Lets sort the selected rows
        qSort(rows.begin(), rows.end());

        // And lets start to remove the rows, starting with the last row.
        int rowToRemove;
        for (int i = (rows.size() - 1); i >= 0; i--)
        {
            rowToRemove = rows.at(i).row();
            beginRemoveRows(QModelIndex(), rowToRemove, rowToRemove);
            itemList->removeAt(rowToRemove);
            endRemoveRows();
        }
    }
}

void ItemModel::editItem(Item *item)
{
}

QModelIndex ItemModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex ItemModel::parent(const QModelIndex &child) const
{
    // correct or infinite recursion?
    return QModelIndex();
}

int ItemModel::rowCount(const QModelIndex &parent) const
{
    return itemList->size();
}

int ItemModel::columnCount(const QModelIndex &parent) const
{
    return NUMBER_OF_COLS;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (itemList->size() > index.row())
        {
            if (index.column() == 0)
                return (*itemList)[index.row()].getName();
            else if (index.column() == 1)
                return (*itemList)[index.row()].getShortDescription();
            else if (index.column() == 2)
                return (*itemList)[index.row()].getDetailedDescription();
            else if (index.column() == 3)
                return(*itemList)[index.row()].getTimeLeft();
            else
                return QVariant::Invalid;
        }
    }

    if (role == Qt::BackgroundRole)
    {
        if (itemList->size() > index.row())
        {
            if (index.isValid())
            {
                switch ( (*itemList)[index.row()].getItemRarity() )
                {
                case Item::Rarity_Normal:
                    return QBrush(QColor(211, 211, 211));
                case Item::Rarity_Magic:
                    return QBrush(QColor(0, 191, 255));
                case Item::Rarity_Rare:
                    return QBrush(QColor(255, 215, 0));
                case Item::Rarity_Set:
                    return QBrush(QColor(50, 205, 50));
                case Item::Rarity_Legendary:
                    //return QBrush(Qt::red);
                    return QBrush(QColor(205, 133, 63));
                default:
                    break;
                }
            }
            else
                return QVariant::Invalid;
        }
    }
    return QVariant::Invalid;
}

QVariant ItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("Itemname");
            case 1:
                return QString("Short Description");
            case 2:
                return QString("Detailed Description");
            case 3:
                return QString("Time Remaining");
            }
        }
    }
    return QVariant();
}

bool ItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        if (itemList->size() > index.row())
        {
            if (index.isValid())
            {
                switch (index.column())
                {
                case 0:
                    (*itemList)[index.row()].setName(value.toString());
                    break;
                case 1:
                    (*itemList)[index.row()].setShortDescription(value.toString());
                    break;
                case 2:
                    (*itemList)[index.row()].setDetailedDescription(value.toString());
                    break;
                case 3:
                    (*itemList)[index.row()].setTimeLeft(value.toString());
                    break;
                default:
                    break;
                }
            }
        }
    }
    return true;
}

Qt::ItemFlags ItemModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
