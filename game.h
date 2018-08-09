#ifndef GAME_H
#define GAME_H

#include "maplayout.h"
#include "block.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>



class xGame : public QGraphicsView {

    Q_OBJECT

public:
    xGame(int viewWidth, int viewHeight);

    void paintMap(int nLvl);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xBlock *heroBlock;
    xBlock *block;
    xBlock *activeBlocks[12][12];
};

#endif // GAME_H
