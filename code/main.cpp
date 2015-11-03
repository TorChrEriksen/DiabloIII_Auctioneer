#include <QtGui/QApplication>
#include <QPlastiqueStyle>
#include <QCleanlooksStyle>
#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new QPlastiqueStyle);
    MainWindow w;
    w.show();
    
    return a.exec();
}
