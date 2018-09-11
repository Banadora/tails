#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "block.h"
#include "maplayout.h"

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

#define nbBlocksX 12
#define nbBlocksY 12
#define PixelsX 32      //blocks width in pixels
#define PixelsY 32      //blocks height in pixels
#define PixelsMove 16   //move distance in pixels
#define StartingMap "garden"



class xGame : public QGraphicsView {

    Q_OBJECT

public:
    xGame(int viewWidth, int viewHeight);

    void placeBlock(int xpos, int ypos, QString blockName, bool isObs);

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xCharacter *hero;
    xBlock *block;
    xBlock *activeBlocks[nbBlocksX][nbBlocksY];
};

#endif // GAME_H
