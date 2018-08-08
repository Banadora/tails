#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"


xMainWindow::xMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xMainWindow)
{
    ui->setupUi(this);

    xGame game(ui->view->width()-2, ui->view->height()-2);
    ui->view->setScene(game.scene);

    game.mapLayout->setLayout(1);
    ui->debugz->setText(game.mapLayout->getBlocName(6,3));
}

xMainWindow::~xMainWindow() {
    delete ui;
}
