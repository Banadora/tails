#include "weapon.h"

#include <QDebug>


xWeapon::xWeapon(QString nName) :
    name(nName)
{

}

xWeapon::~xWeapon()
{
    delete anim;
}

QString xWeapon::getName() { return name; }

int xWeapon::getDmg() { return dmg; }

xAnimation *xWeapon::getAttackAnim() { return anim; }

void xWeapon::setAttackAnim(QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame)
{
    anim = new xAnimation(nName, nType, nTimespan, nStartFrame, nStopFrame);
}

void xWeapon::changeWeapon(QString nName) {
    name = nName;

    if (name == "none") { dmg = 0; }
    else if (name == "staff") { dmg = STAFF_DMG; }
    else if (name == "claws") { dmg = CLAWS_DMG; }
    else { dmg = 0; }

    qDebug() << "Weapon : " + getName();
}
