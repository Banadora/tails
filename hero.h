#ifndef HERO_H
#define HERO_H

#include "character.h"

class xHero : public xCharacter {

    Q_OBJECT

    int hp;

public:
    xHero(QObject *parent=nullptr, QString heroName="heroname");

    int getHP();
    void setHP(int nHP);

    void getDamaged(int dmg);
};

#endif // HERO_H
