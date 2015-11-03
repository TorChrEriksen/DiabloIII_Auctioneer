#include "newitem.h"
#include "ui_newitem.h"
#include <QMessageBox>

NewItem::NewItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewItem)
{
    ui->setupUi(this);

    selectedRarity = Item::Rarity_Unknown;

    connect(ui->rarityNormal, SIGNAL(toggled(bool)), this, SLOT(reactToRarityChange(bool)));
    connect(ui->rarityMagic, SIGNAL(toggled(bool)), this, SLOT(reactToRarityChange(bool)));
    connect(ui->rarityRare, SIGNAL(toggled(bool)), this, SLOT(reactToRarityChange(bool)));
    connect(ui->raritySet, SIGNAL(toggled(bool)), this, SLOT(reactToRarityChange(bool)));
    connect(ui->rarityLegendary, SIGNAL(toggled(bool)), this, SLOT(reactToRarityChange(bool)));

    connect(ui->itemName, SIGNAL(textChanged(QString)), this, SLOT(enableOrDisableAddButton(QString)));
}

NewItem::~NewItem()
{
    delete ui;
}

void NewItem::on_addButton_clicked()
{
    if( (ui->minutes->value() == 0) && (ui->hours->value() == 0) && (ui->days->value() == 0))
    {
        QMessageBox::warning(this,
                             "Error Adding Item",
                             "You have to specify the time remaining!");
    }
    else
    {
        Item *item = new Item(ui->itemName->text(),
                              ui->descriptionShort->text(),
                              ui->description->toPlainText(),
                              ui->days->value(),
                              ui->hours->value(),
                              ui->minutes->value(),
                              selectedRarity);

        //send signal to itemcontrol.
        emit itemReadyForInsertion(*item);
    }
}

void NewItem::on_cancelButton_clicked()
{
    this->close();
}

void NewItem::enableOrDisableAddButton(QString lineText)
{
    if ( lineText.isEmpty() )
        ui->addButton->setEnabled(false);
    else if( lineText.count(' ') == lineText.length() )
        ui->addButton->setEnabled(false);
    else
        ui->addButton->setEnabled(true);
}

void NewItem::reactToRarityChange(bool checked)
{
    if (ui->rarityNormal->isChecked())
        selectedRarity = Item::Rarity_Normal;
    else if (ui->rarityMagic->isChecked())
        selectedRarity = Item::Rarity_Magic;
    else if (ui->rarityRare->isChecked())
        selectedRarity = Item::Rarity_Rare;
    else if (ui->raritySet->isChecked())
        selectedRarity = Item::Rarity_Set;
    else if (ui->rarityLegendary->isChecked())
        selectedRarity = Item::Rarity_Legendary;
    else
        selectedRarity = Item::Rarity_Unknown;
}

