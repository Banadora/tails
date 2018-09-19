#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QDebug>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName) :
    xCharacter(parent, heroName),
    hp(100)
{
    animView = new QGraphicsPixmapItem;
    animView->setPixmap(QPixmap(":/img/staff0.png"));
    animView->setZValue(14);

    stopAnimTimer = new QTimer;
    connect(stopAnimTimer, SIGNAL(timeout()), this, SLOT(stopAnim()));
}

int xHero::getHP() { return hp; }
void xHero::setHP(int nHP) { hp = nHP; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}

void xHero::attack() {
    //play anim
    attackAnim();

    //check if anim collides with an enemy
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
                if (e->getHP() <= 0) { delete e; }
            }
        }
    }
}

void xHero::attackAnim() {
    if (getView()->getViewName().contains("back"))
    {
        animView->setRotation(-90);
        animView->setPos(getView()->pos().x() + PixelsX/2 - 6, getView()->pos().y());
    }
    else if (getView()->getViewName().contains("front"))
    {
        animView->setRotation(90);
        animView->setPos(getView()->pos().x() + PixelsX/2 + 6, getView()->pos().y() + PixelsY);
    }
    else if (getView()->getViewName().contains("right"))
    {
        animView->setRotation(0);
        animView->setPos(getView()->pos().x() + PixelsX, getView()->pos().y() + PixelsY/2 - 6);
    }
    else if (getView()->getViewName().contains("left"))
    {
        animView->setRotation(180);
        animView->setPos(getView()->pos().x(), getView()->pos().y() + PixelsY/2 + 6);
    }

    game->scene->addItem(animView);
    stopAnimTimer->start(400);
}


void xHero::stopAnim() {
    game->scene->removeItem(animView);
    stopAnimTimer->stop();
}
