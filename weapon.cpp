#include "weapon.h"

#include <QDebug>


xWeapon::xWeapon(QString nName) :
    name(nName)
{

}

QString xWeapon::getName() { return name; }

int xWeapon::getDmg() { return dmg; }

void xWeapon::changeWeapon(QString nName) {
    name = nName;

    if (name == "none") { dmg = 0; }
    else if (name == "staff") { dmg = STAFF_DMG; }
    else if (name == "claws") { dmg = CLAWS_DMG; }
    else { dmg = 0; }

    qDebug() << "Weapon : " + getName();
}
