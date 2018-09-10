#include "character.h"
#include "block.h"
#include "game.h"

extern xGame *game;

xCharacter::xCharacter()
{ }

void xCharacter::setViewPos(int nX, int nY)
{
    view.setPos(nX, nY);
}

xCharacterView* xCharacter::getView()
{
    return &view;
}

void xCharacter::move(QString direction)
{
    view.move(direction);
}
