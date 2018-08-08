#ifndef GAME_H
#define GAME_H

#include "maplayout.h"
#include "bloc.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


class xGame : public QGraphicsView {

public:
    xGame(int viewWidth, int viewHeight);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xBloc *bloc;
};

#endif // GAME_H
