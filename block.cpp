#include "block.h"
#include "game.h"


extern xGame *game;

////////// init
xBlock::xBlock()
{ }

xBlock::xBlock(QString blockName, bool isObs) :
    name(blockName),
    isObstacle(isObs)
{
    setPixmap(QPixmap(":/img/" + name));
}

void xBlock::setName(QString nName) { name = nName;}
QString xBlock::getName() { return name; }

bool xBlock::getIsObstacle() { return isObstacle; }
