#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setWindowIcon(QIcon("container.png"));

    w.showMaximized();

    return a.exec();
}
