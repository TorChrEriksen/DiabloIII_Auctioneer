/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 17. Aug 17:20:42 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QTableView *tableView;
    QLabel *nextAuctionLabel;
    QLabel *nextAuctionTimer;
    QLabel *alertLabel;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exitButton;
    QPushButton *stopAlertButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(593, 424);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 571, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        editButton = new QPushButton(layoutWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout->addWidget(editButton, 0, 1, 1, 1);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 0, 2, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setLineWidth(1);
        tableView->setShowGrid(false);

        gridLayout->addWidget(tableView, 1, 0, 1, 5);

        nextAuctionLabel = new QLabel(layoutWidget);
        nextAuctionLabel->setObjectName(QString::fromUtf8("nextAuctionLabel"));
        nextAuctionLabel->setLayoutDirection(Qt::LeftToRight);
        nextAuctionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nextAuctionLabel, 0, 3, 1, 1);

        nextAuctionTimer = new QLabel(layoutWidget);
        nextAuctionTimer->setObjectName(QString::fromUtf8("nextAuctionTimer"));
        nextAuctionTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);"));
        nextAuctionTimer->setFrameShape(QFrame::Panel);
        nextAuctionTimer->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(nextAuctionTimer, 0, 4, 1, 1);

        alertLabel = new QLabel(layoutWidget);
        alertLabel->setObjectName(QString::fromUtf8("alertLabel"));

        gridLayout->addWidget(alertLabel, 2, 0, 3, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 4, 1, 1);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout->addWidget(exitButton, 4, 4, 1, 1);

        stopAlertButton = new QPushButton(layoutWidget);
        stopAlertButton->setObjectName(QString::fromUtf8("stopAlertButton"));

        gridLayout->addWidget(stopAlertButton, 4, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DiabloIII Auctioneer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("MainWindow", "Add a new item to the list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("MainWindow", "Edit ONE SINGLE selected item. Multiple items cannot be edited.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("MainWindow", "Delete the selected item(s) from the list.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        nextAuctionLabel->setText(QApplication::translate("MainWindow", "Next auction in:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nextAuctionTimer->setToolTip(QApplication::translate("MainWindow", "Time untill the next auction ends.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nextAuctionTimer->setText(QString());
        alertLabel->setText(QString());
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        stopAlertButton->setText(QApplication::translate("MainWindow", "Stop Alert", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
