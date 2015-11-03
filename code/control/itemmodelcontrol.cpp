#include "itemmodelcontrol.h"

#include <QDebug>

ItemModelControl::ItemModelControl(QObject *parent, ItemModel *itemModel) :
    QObject(parent)
{
    model = itemModel;
}

void ItemModelControl::addNewItem(Item &item)
{
    model->addItem(&item);
    //model->updateModel();
}

void ItemModelControl::deleteItems(QModelIndexList rows)
{
    model->removeItem(rows);
}
