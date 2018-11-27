#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "enemy.h"
#include "block.h"
#include "maplayout.h"

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

#define nbBlocksX 12    //number of X-axis blocks in the view
#define nbBlocksY 12    //number of Y-axis blocks in the view
#define PixelsX 32      //blocks width in pixels
#define PixelsY 32      //blocks height in pixels
#define PixelsMove 16   //move distance in pixels
#define StartingMap "plains" //name.json will be opened at start


class xGame : public QGraphicsView {

    Q_OBJECT

public:
    xGame(int viewWidth, int viewHeight);

    void placeBlock(int xpos, int ypos, QString blockName, bool isObs);
    void placeEnemy(int xpos, int ypos, QString name, int hp, QString weapon);

    void clearEnemies();

    QGraphicsScene *scene;
    xMapLayout *mapLayout;
    xHero *hero;
    xBlock *block;
    xBlock *activeBlocks[nbBlocksX][nbBlocksY];
    xEnemy *enemy;
};

#endif // GAME_H
