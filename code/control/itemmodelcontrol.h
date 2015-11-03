#ifndef ITEMMODELCONTROL_H
#define ITEMMODELCONTROL_H

#include "data/item.h"
#include "models/itemmodel.h"
#include <QObject>

class ItemModelControl : public QObject
{
    Q_OBJECT
public:
    explicit ItemModelControl(QObject *parent = 0, ItemModel *itemModel = 0);
    
signals:
    
public slots:
    void addNewItem(Item &item);
    void deleteItems(QModelIndexList rows);

private:
    ItemModel *model;
};

#endif // ITEMMODELCONTROL_H
