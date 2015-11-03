#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "models/itemmodel.h"
#include "control/itemmodelcontrol.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_exitButton_clicked();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_stopAlertButton_clicked();

private:
    Ui::MainWindow *ui;
    ItemModel *items;
    ItemModelControl *itemModelControl;
    QSystemTrayIcon *systemTrayIcon;
    bool stopAlertUser;
    int alertLabelColor;
    QTimer *alertTimer;

signals:
    void itemReadyForDeletion(QModelIndexList selectedRows);

public slots:
    void updateNextAuctionTimer(QString timeLeft);
    void playSound();
    void alertUser(bool doAlert = true);
    void changeAlertLabel();
};

#endif // MAINWINDOW_H
