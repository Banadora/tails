#ifndef GAME_H
#define GAME_H

#include "maplayout.h"
#include "character.h"
#include "block.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#define nbBlocksX 12
#define nbBlocksY 12
#define PixelsX 32      //blocks width in pixels
#define PixelsY 32      //blocks height in pixels
#define PixelsMove 16   //move distance in pixels



class xGame : public QGraphicsView {

    Q_OBJECT

public:
    xGame(int viewWidth, int viewHeight);

    void paintMap(int nLvl);
    void clearMap(int nLvl);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xCharacter *hero;
    xBlock *block;
    xBlock *activeBlocks[nbBlocksX][nbBlocksY];
};

#endif // GAME_H
