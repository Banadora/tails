#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QDebug>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName, QString nDirection, QString nWeapon) :
    xCharacter(parent, heroName),
    hp(100),
    weapon(nWeapon),
    direction(nDirection)
{
    getView()->setViewName(heroName + "_" + direction + "_" + weapon);

    animView = new QGraphicsPixmapItem;
    animView->setPixmap(QPixmap(":/img/staff0.png"));
    animView->setZValue(9);
    animView->setVisible(false);

    stopAnimTimer = new QTimer;
    connect(stopAnimTimer, SIGNAL(timeout()), this, SLOT(stopAnim()));
}

int xHero::getHP() { return hp; }
void xHero::setHP(int nHP) { hp = nHP; }

QString xHero::getWeapon() { return weapon; }

void xHero::setDirection(QString nDirection) { direction = nDirection; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}

void xHero::attack() {
    //create timeline
    QTimeLine *timeLine = new QTimeLine(120, this);
    timeLine->setFrameRange(0, 35);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(attackAnim(int)));
    //play anim and change hero's view to no weapon during anim
    game->hero->getView()->setViewName(game->hero->getName() + "_" + direction + "_" + "none");
    game->scene->addItem(animView);
    hit = false;
    timeLine->start();
    stopAnimTimer->start(250);
}

bool xHero::checkAttack()
{
    //check if anim collides with an enemy, return true if enemy took a shot
    xCharacterView *ev = new xCharacterView(nullptr, ""); //pointer to enemies' views

    QList<QGraphicsItem *> colliding_items = animView->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) {
            ev = qgraphicsitem_cast<xCharacterView *>(colliding_items[i]);
            //qDebug() << ev->getViewName() << ev->getParent();
            if (ev->getViewName().contains("hero") == false) { //delete character objects (with associated views)
                xEnemy *e = dynamic_cast<xEnemy *>(ev->getParent());
                e->getDamaged(50);
                qDebug() << "enemy's HP : " << e->getHP();
                //if enemy has no life, delete it
                if (e->getHP() <= 0) { delete e->getAnimView(); delete e; }
                return true;
            }
        }
    }
    return false;
}

void xHero::attackAnim(int frame) {
    animView->setVisible(false);
    if (getView()->getViewName().contains("back"))
    {
        animView->setRotation(-115 + frame); //-90 (-115 to -80)
        animView->setPos(getView()->pos().x() + PixelsX/2 - 6, getView()->pos().y() + PixelsY/2);
    }
    else if (getView()->getViewName().contains("front"))
    {
        animView->setRotation(65 + frame);//90 (65 to 100)
        animView->setPos(getView()->pos().x() + PixelsX/2 + 6, getView()->pos().y() + PixelsY/2);
    }
    else if (getView()->getViewName().contains("right"))
    {
        animView->setRotation(-25 + frame); //0 (-25 to 10)
        animView->setPos(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 - 6);
    }
    else if (getView()->getViewName().contains("left"))
    {
        animView->setRotation(155 + frame); //180 (155 to 190)
        animView->setPos(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 + 6);
    }

    //add anim to scene then check if hitting an enemy, if already hitted during animation, don't check anymore
    animView->setVisible(true);
    if (hit == false) { hit = checkAttack(); }
}

QGraphicsPixmapItem* xHero::getAnimView() { return animView; }


void xHero::stopAnim() {
    game->hero->getView()->setViewName(game->hero->getName() + "_" + direction + "_" + game->hero->getWeapon());
    game->scene->removeItem(animView);
    stopAnimTimer->stop();
}
