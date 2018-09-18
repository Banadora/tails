#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName) :
    xCharacter(parent, heroName),
    hp(100)
{ }

int xHero::getHP() { return hp; }

void xHero::setHP(int nHP) { hp = nHP; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}
