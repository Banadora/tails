#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "animation.h"

//#include <QTimer>

class xHero : public xCharacter {

    Q_OBJECT


    QString direction;
    bool hit;

    xAnimation *anim;

public:
    xHero(QObject *parent=nullptr, QString heroName="hero", int nHP=100, QString nDirection="front", QString nWeapon="staff");

    void setDirection(QString nDirection);
    QString getDirection();

    void attack();
    bool checkAttack();

    xAnimation *getAnim();
};

#endif // HERO_H
