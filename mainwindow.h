#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>


namespace Ui {
class xMainWindow;
}

class xMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit xMainWindow(QWidget *parent = nullptr);
    ~xMainWindow();


private slots:


private:
    Ui::xMainWindow *ui;
    //xGame *game;
};

#endif // MAINWINDOW_H
