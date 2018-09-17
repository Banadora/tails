#ifndef HERO_H
#define HERO_H

#include "character.h"

class xHero : public xCharacter {

    int hp;

public:
    xHero(QString heroName);

    int getHP();
    void setHP(int nHP);

    void getDamaged(int dmg);
};

#endif // HERO_H
