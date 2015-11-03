#ifndef NEWITEM_H
#define NEWITEM_H

#include "data/item.h"
#include <QDialog>

namespace Ui {
class NewItem;
}

class NewItem : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewItem(QWidget *parent = 0);
    ~NewItem();

public slots:
    void reactToRarityChange(bool checked);
    
private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();
    void enableOrDisableAddButton(QString lineText);

private:
    Ui::NewItem *ui;
    Item::Rarity selectedRarity;

signals:
    void itemReadyForInsertion(Item &item);
};

#endif // NEWITEM_H
