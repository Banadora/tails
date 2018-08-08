#ifndef GAME_H
#define GAME_H

#include "bloc.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


class xGame : public QGraphicsView {

public:
    xGame(int viewWidth, int viewHeight);

    QGraphicsScene *scene;
    xBloc *bloc;
};

#endif // GAME_H
