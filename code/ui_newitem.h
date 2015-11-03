/********************************************************************************
** Form generated from reading UI file 'newitem.ui'
**
** Created: Fri 17. Aug 17:20:42 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWITEM_H
#define UI_NEWITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewItem
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *itemNameLabel;
    QLineEdit *itemName;
    QLabel *timeleftLabel;
    QLabel *descriptionShortLabel;
    QLineEdit *descriptionShort;
    QLabel *descriptionLabel;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout;
    QLabel *daysLabel;
    QSpinBox *days;
    QLabel *hoursLabel;
    QSpinBox *hours;
    QLabel *minutesLabel;
    QSpinBox *minutes;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QGroupBox *radioButtonBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QRadioButton *rarityNormal;
    QRadioButton *rarityMagic;
    QRadioButton *rarityRare;
    QRadioButton *raritySet;
    QRadioButton *rarityLegendary;

    void setupUi(QDialog *NewItem)
    {
        if (NewItem->objectName().isEmpty())
            NewItem->setObjectName(QString::fromUtf8("NewItem"));
        NewItem->setWindowModality(Qt::ApplicationModal);
        NewItem->resize(462, 292);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewItem->setWindowIcon(icon);
        layoutWidget = new QWidget(NewItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 341, 265));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        itemNameLabel = new QLabel(layoutWidget);
        itemNameLabel->setObjectName(QString::fromUtf8("itemNameLabel"));

        gridLayout_2->addWidget(itemNameLabel, 0, 0, 1, 1);

        itemName = new QLineEdit(layoutWidget);
        itemName->setObjectName(QString::fromUtf8("itemName"));

        gridLayout_2->addWidget(itemName, 0, 1, 1, 1);

        timeleftLabel = new QLabel(layoutWidget);
        timeleftLabel->setObjectName(QString::fromUtf8("timeleftLabel"));

        gridLayout_2->addWidget(timeleftLabel, 1, 0, 1, 1);

        descriptionShortLabel = new QLabel(layoutWidget);
        descriptionShortLabel->setObjectName(QString::fromUtf8("descriptionShortLabel"));

        gridLayout_2->addWidget(descriptionShortLabel, 2, 0, 1, 1);

        descriptionShort = new QLineEdit(layoutWidget);
        descriptionShort->setObjectName(QString::fromUtf8("descriptionShort"));

        gridLayout_2->addWidget(descriptionShort, 2, 1, 1, 1);

        descriptionLabel = new QLabel(layoutWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(descriptionLabel, 3, 0, 1, 1);

        description = new QTextEdit(layoutWidget);
        description->setObjectName(QString::fromUtf8("description"));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        description->setFont(font);

        gridLayout_2->addWidget(description, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        daysLabel = new QLabel(layoutWidget);
        daysLabel->setObjectName(QString::fromUtf8("daysLabel"));

        horizontalLayout->addWidget(daysLabel);

        days = new QSpinBox(layoutWidget);
        days->setObjectName(QString::fromUtf8("days"));
        days->setMaximum(1);

        horizontalLayout->addWidget(days);

        hoursLabel = new QLabel(layoutWidget);
        hoursLabel->setObjectName(QString::fromUtf8("hoursLabel"));

        horizontalLayout->addWidget(hoursLabel);

        hours = new QSpinBox(layoutWidget);
        hours->setObjectName(QString::fromUtf8("hours"));
        hours->setMaximum(23);

        horizontalLayout->addWidget(hours);

        minutesLabel = new QLabel(layoutWidget);
        minutesLabel->setObjectName(QString::fromUtf8("minutesLabel"));

        horizontalLayout->addWidget(minutesLabel);

        minutes = new QSpinBox(layoutWidget);
        minutes->setObjectName(QString::fromUtf8("minutes"));
        minutes->setMaximum(59);

        horizontalLayout->addWidget(minutes);


        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(NewItem);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(370, 210, 77, 70));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(layoutWidget_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setEnabled(false);

        verticalLayout_2->addWidget(addButton);

        cancelButton = new QPushButton(layoutWidget_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);

        radioButtonBox = new QGroupBox(NewItem);
        radioButtonBox->setObjectName(QString::fromUtf8("radioButtonBox"));
        radioButtonBox->setGeometry(QRect(360, 10, 91, 141));
        QFont font1;
        font1.setStrikeOut(false);
        radioButtonBox->setFont(font1);
        layoutWidget1 = new QWidget(radioButtonBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 76, 111));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rarityNormal = new QRadioButton(layoutWidget1);
        rarityNormal->setObjectName(QString::fromUtf8("rarityNormal"));

        verticalLayout->addWidget(rarityNormal);

        rarityMagic = new QRadioButton(layoutWidget1);
        rarityMagic->setObjectName(QString::fromUtf8("rarityMagic"));

        verticalLayout->addWidget(rarityMagic);

        rarityRare = new QRadioButton(layoutWidget1);
        rarityRare->setObjectName(QString::fromUtf8("rarityRare"));

        verticalLayout->addWidget(rarityRare);

        raritySet = new QRadioButton(layoutWidget1);
        raritySet->setObjectName(QString::fromUtf8("raritySet"));

        verticalLayout->addWidget(raritySet);

        rarityLegendary = new QRadioButton(layoutWidget1);
        rarityLegendary->setObjectName(QString::fromUtf8("rarityLegendary"));

        verticalLayout->addWidget(rarityLegendary);


        retranslateUi(NewItem);

        QMetaObject::connectSlotsByName(NewItem);
    } // setupUi

    void retranslateUi(QDialog *NewItem)
    {
        NewItem->setWindowTitle(QApplication::translate("NewItem", "Add New Item", 0, QApplication::UnicodeUTF8));
        itemNameLabel->setText(QApplication::translate("NewItem", "Item Name", 0, QApplication::UnicodeUTF8));
        timeleftLabel->setText(QApplication::translate("NewItem", "Time Left", 0, QApplication::UnicodeUTF8));
        descriptionShortLabel->setText(QApplication::translate("NewItem", "Short Description", 0, QApplication::UnicodeUTF8));
        descriptionLabel->setText(QApplication::translate("NewItem", "Description", 0, QApplication::UnicodeUTF8));
        daysLabel->setText(QApplication::translate("NewItem", "Days", 0, QApplication::UnicodeUTF8));
        hoursLabel->setText(QApplication::translate("NewItem", "Hours", 0, QApplication::UnicodeUTF8));
        minutesLabel->setText(QApplication::translate("NewItem", "Minutes", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("NewItem", "Add", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("NewItem", "Close", 0, QApplication::UnicodeUTF8));
        radioButtonBox->setTitle(QApplication::translate("NewItem", "Rarity", 0, QApplication::UnicodeUTF8));
        rarityNormal->setText(QApplication::translate("NewItem", "Normal", 0, QApplication::UnicodeUTF8));
        rarityMagic->setText(QApplication::translate("NewItem", "Magic", 0, QApplication::UnicodeUTF8));
        rarityRare->setText(QApplication::translate("NewItem", "Rare", 0, QApplication::UnicodeUTF8));
        raritySet->setText(QApplication::translate("NewItem", "Set", 0, QApplication::UnicodeUTF8));
        rarityLegendary->setText(QApplication::translate("NewItem", "Legendary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewItem: public Ui_NewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWITEM_H
