#include "character.h"
#include "block.h"
#include "game.h"

extern xGame *game;


xCharacter::xCharacter(QObject *parent, QString nName) :
    name(nName),
    view(this, nName)
{ }

void xCharacter::setViewPos(int nX, int nY) { view.setPos(nX, nY); }

xCharacterView* xCharacter::getView() { return &view; }

void xCharacter::setName(QString nName) { name = nName; }
QString xCharacter::getName() { return name; }
