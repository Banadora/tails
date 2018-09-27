#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QDebug>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName) :
    xCharacter(parent, heroName),
    hp(100)
{
    animView = new QGraphicsPixmapItem;

    stopAnimTimer = new QTimer;
    connect(stopAnimTimer, SIGNAL(timeout()), this, SLOT(stopAnim()));
}

int xHero::getHP() { return hp; }
void xHero::setHP(int nHP) { hp = nHP; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}

void xHero::attack() {
    //create timeline
    QTimeLine *timeLine = new QTimeLine(80, this);
    timeLine->setFrameRange(0, 35);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(attackAnim(int)));
    //play anim
    hit = false;
    timeLine->start();
    stopAnimTimer->start(100);
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
    //delete old anim, make new anim
    delete animView;
    animView = new QGraphicsPixmapItem;
    animView->setPixmap(QPixmap(":/img/staff0.png"));
    animView->setZValue(9);


    animView->setVisible(true);
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
    game->scene->addItem(animView);
    if (hit == false) { hit = checkAttack(); }
}

QGraphicsPixmapItem* xHero::getAnimView() { return animView; }


void xHero::stopAnim() {
    game->scene->removeItem(animView);
    stopAnimTimer->stop();
}
