#include "bloc.h"
#include "game.h"


xBloc::xBloc(QString blocName) {
    setPixmap(QPixmap(":/img/" + blocName + ".png"));
}

void xBloc::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
            setPos(x*32, (y-1)*32);
            setY(y-1);
    }
    else if (event->key() == Qt::Key_Down) {
            setPos(x*32, (y+1)*32);
            setY(y+1);
    }
    else if (event->key() == Qt::Key_Left) {
            setPos((x-1)*32, y*32);
            setX(x-1);
    }
    else if (event->key() == Qt::Key_Right) {
            setPos((x+1)*32, y*32);
            setX(x+1);
    }
    else if (event->key() == Qt::Key_Space) {  }
}

void xBloc::setX(int nX) { x = nX; }
void xBloc::setY(int nY) { y = nY; }

int xBloc::getX() { return x; }
int xBloc::getY() { return y; }


