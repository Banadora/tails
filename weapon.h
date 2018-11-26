#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QGraphicsPixmapItem>


#define STAFF_DMG 55
#define CLAWS_DMG 5


class xWeapon : public QObject, public QGraphicsPixmapItem {

    QString name;
    int dmg;

public:
    xWeapon(QString nName);

    QString getName();

    void changeWeapon(QString nName);

};

#endif // WEAPON_H
