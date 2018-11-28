#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "weapon.h"

//#include <QTimer>

class xHero : public xCharacter {

public:
    xHero(QString heroName="hero", int nHP=100, QString nDirection="front", QString="staff");

    bool moveView (QString direction);

    void attack();
    bool checkAttack();
};

#endif // HERO_H
