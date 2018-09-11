#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

xGame *game; //game can be called as extern in objects created in game itself

xMainWindow::xMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xMainWindow)
{
    ui->setupUi(this);

    game = new xGame(ui->view->width()-2, ui->view->height()-2);
    ui->view->setScene(game->scene);
    game->mapLayout->loadMap(StartingMap);
}

xMainWindow::~xMainWindow() {
    delete ui;
}
