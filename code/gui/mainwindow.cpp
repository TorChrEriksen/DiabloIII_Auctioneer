#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newitem.h"

#include <QMessageBox>
#include <phonon/phonon>
#include <QPalette>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    systemTrayIcon = new QSystemTrayIcon(QIcon(":/resources/images/icon2.png"));
    systemTrayIcon->setToolTip("Diablo III Auctioneer");
    systemTrayIcon->show();

    items = new ItemModel(0);

    ui->tableView->horizontalHeader()->setDefaultSectionSize(120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setModel(items);
    ui->tableView->show();

    //ui->alertLabel->setPixmap(QPixmap::fromImage(QImage(":/resources/images/splash_sized.png")).scaled(335, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->alertLabel->setStyleSheet("QLabel { background-color : grey; }");

    itemModelControl = new ItemModelControl(this, items);

    connect(this, SIGNAL(itemReadyForDeletion(QModelIndexList)), itemModelControl, SLOT(deleteItems(QModelIndexList)));
    connect(items, SIGNAL(updateNextAuctionTimer(QString)), this, SLOT(updateNextAuctionTimer(QString)));
    connect(items, SIGNAL(warnUserWithSound(bool)), this, SLOT(playSound()));
    connect(items, SIGNAL(warnUserWithSound(bool)), this, SLOT(alertUser(bool)));


    alertTimer = new QTimer(this);
    stopAlertUser = false;
    ui->stopAlertButton->setEnabled(false);
    alertLabelColor = 1;
    connect(alertTimer, SIGNAL(timeout()), this, SLOT(changeAlertLabel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,
                                   "Exit?",
                                   "Do you really want to quit?",
                                   QMessageBox::Yes | QMessageBox::No,
                                   QMessageBox::No);
    if (result == QMessageBox::Yes)
        this->close();
}

void MainWindow::on_addButton_clicked()
{
    NewItem *newItemForm = new NewItem();
    connect(newItemForm, SIGNAL(itemReadyForInsertion(Item &)), itemModelControl, SLOT(addNewItem(Item &)));
    newItemForm->show();
}

void MainWindow::on_editButton_clicked()
{
    QMessageBox::information(this,
                             "Oh no!!!",
                             "Not yet implemented, Im so sowwy!!! If you want to change the time remaining for an auction, you have to delete and add it again. :<");
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    emit itemReadyForDeletion(selectedRows);
}

void MainWindow::updateNextAuctionTimer(QString timeLeft)
{
    ui->nextAuctionTimer->setText(timeLeft);
}

void MainWindow::playSound()
{
    systemTrayIcon->showMessage("Auction Ending!", "You have an auction ending soon!", QSystemTrayIcon::Information, 2000);
    int soundChoice = qrand() % ((1+1)-0)+0;
    switch (soundChoice)
    {
    case 0:
    {
        Phonon::MediaObject *media = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource(":/resources/music/LTTP_Heart.ogx"));
        media->play();
        break;
    }
    case 1:
    {
        Phonon::MediaObject *media = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource(":/resources/music/LTTP_Fanfare.wav"));
        media->play();
        break;
    }
    default:
        qDebug() << "FML " << soundChoice;
    }
}

void MainWindow::alertUser(bool doAlert)
{
    if(doAlert)
    {
        if( alertLabelColor == 0 )
            alertLabelColor = 1;
        ui->stopAlertButton->setEnabled(true);
        alertTimer->start(500);
    }
    else
    {
        alertLabelColor = 0;
        alertTimer->stop();
        stopAlertUser = false;
        ui->alertLabel->setStyleSheet("QLabel { background-color : grey; }");
    }
}

void MainWindow::changeAlertLabel()
{
    switch (alertLabelColor)
    {
    case 1:
        ui->alertLabel->setStyleSheet("QLabel { background-color : red; }");
        alertLabelColor = 2;
        break;
    case 2:
        ui->alertLabel->setStyleSheet("QLabel { background-color : blue; }");
        alertLabelColor = 3;
        break;
    case 3:
        ui->alertLabel->setStyleSheet("QLabel { background-color : yellow; }");
        alertLabelColor = 1;
        break;
    default:
        ui->alertLabel->setStyleSheet("QLabel { background-color : grey; }");
        break;
    }
}

void MainWindow::on_stopAlertButton_clicked()
{
    ui->stopAlertButton->setEnabled(false);
    stopAlertUser = true;
    alertUser(false);
}
