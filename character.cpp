#include "character.h"
#include "block.h"
#include "game.h"

extern xGame *game;


xCharacter::xCharacter(QObject *parent, QString nName, int nHP, QString nWeapon) :
    name(nName),
    hp(nHP),
    weapon(nWeapon),
    view(this, nName),
    isAttacking(false)
{ }

void xCharacter::setViewPos(int nX, int nY) { view.setPos(nX, nY); }

xCharacterView* xCharacter::getView() { return &view; }

bool xCharacter::moveView(QString direction) {
    bool moved = getView()->move(direction);

    return moved;
}

void xCharacter::setName(QString nName) { name = nName; }
QString xCharacter::getName() { return name; }

int xCharacter::getHP() { return hp; }
void xCharacter::setHP(int nHP) { hp = nHP; }

xWeapon* xCharacter::getWeapon() { return &weapon; }

void xCharacter::takeDmg(int dmg) { hp -= dmg; }

void xCharacter::setIsAttacking(bool nIsAttacking) { isAttacking = nIsAttacking; }
bool xCharacter::getIsAttacking() { return isAttacking; }


