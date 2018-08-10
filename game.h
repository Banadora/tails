#ifndef GAME_H
#define GAME_H

#include "maplayout.h"
#include "block.h"
#include "blockhero.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#define PixelsX 32      //blocks width in pixels
#define PixelsY 32      //blocks height in pixels



class xGame : public QGraphicsView {

    Q_OBJECT

public:
    xGame(int viewWidth, int viewHeight);

    void paintMap(int nLvl);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xBlockHero *heroBlock;
    xBlock *block;
    xBlock *activeBlocks[12][12];
};

#endif // GAME_H
