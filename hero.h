#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "weapon.h"

//#include <QTimer>

class xHero : public xCharacter {

    Q_OBJECT


    QString direction;
    bool hit;

public:
    xHero(QObject *parent=nullptr, QString heroName="hero", int nHP=100, QString nDirection="front", QString="staff");

    void setDirection(QString nDirection);
    QString getDirection();

    void attack();
    bool checkAttack();


};

#endif // HERO_H
