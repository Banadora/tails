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
    void paintMap(int nLvl);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xBloc *heroBloc;
    xBloc *bloc;
};

#endif // GAME_H
