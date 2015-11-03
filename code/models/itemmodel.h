#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include "data/item.h"
#include <QList>
#include <QAbstractItemModel>
#include <QTimer>

const int NUMBER_OF_COLS = 4;

class ItemModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ItemModel(QObject *parent = 0);

    void addItem(Item *item);
    void editItem(Item *item);
    void removeItem(QModelIndexList rows);


    // Implemented inherited methods
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<Item> *itemList;
    QTimer *nextAuctionTimer;
    QTimer *generalTimer;

signals:
    void updateNextAuctionTimer(QString timeLeft);
    void notifyAuctionSoonEnding(int auctionLocationInList);
    void warnUserWithSound(bool doAlert);

public slots:
    void updateNextAuction();
    void updateGeneralTimer();
    void updateAuctionSoonEnding(int auctionLocationInList);

};

#endif // ITEMMODEL_H
