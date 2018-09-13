#include "hero.h"
#include "game.h"


extern xGame *game;


xHero::xHero(QString heroName) :
    xCharacter(heroName),
    hp(100)
{ }

int xHero::getHP() { return hp; }

void xHero::setHP(int nHP) { hp = nHP; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}
