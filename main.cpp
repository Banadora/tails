#include "mainwindow.h"
#include <QApplication>

////////// launch mainwindow
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    xMainWindow w;
    w.show();

    return a.exec();
}
