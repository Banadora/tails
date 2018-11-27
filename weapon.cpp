#include "weapon.h"

#include <QDebug>


xWeapon::xWeapon(QObject *parent, QString nName) :
    p(parent),
    name(nName)
{

}

QObject *xWeapon::getParent() { return p; }

QString xWeapon::getName() { return name; }

int xWeapon::getDmg() { return dmg; }

xAnimation *xWeapon::getAttackAnim() { return anim; }

void xWeapon::setAttackAnim(QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame)
{
    anim = new xAnimation(this, nName, nType, nTimespan, nStartFrame, nStopFrame);
}

void xWeapon::changeWeapon(QString nName) {
    name = nName;

    if (name == "none") { dmg = 0; }
    else if (name == "staff") { dmg = STAFF_DMG; }
    else if (name == "claws") { dmg = CLAWS_DMG; }
    else { dmg = 0; }

    qDebug() << "Weapon : " + getName();
}
