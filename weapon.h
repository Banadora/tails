#ifndef WEAPON_H
#define WEAPON_H

#include "animation.h"

#include <QObject>
#include <QGraphicsPixmapItem>

//damage done by weapons
#define STAFF_DMG 55
#define CLAWS_DMG 5


class xWeapon : public QObject, public QGraphicsPixmapItem {

    QString name;
    int dmg;

    xAnimation *anim;

public:
    xWeapon(QString nName);
    ~xWeapon();

    QString getName();

    int getDmg();

    xAnimation *getAttackAnim();
    void setAttackAnim(QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame);

    void changeWeapon(QString nName);

};

#endif // WEAPON_H
