#include "character.h"
#include "block.h"
#include "game.h"

extern xGame *game;

void xCharacter::Character()
{

}

void xCharacter :: moveNorth(){

    xBlock *topleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x(), pos().y()-PixelsMove), QTransform()));
    xBlock *topright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1, pos().y()-PixelsMove), QTransform()));
    if (    (topleft->isObstacle() == false) && (topright->isObstacle() == false)    )  {
        setPos(pos().x(), pos().y()-PixelsMove); }


}
