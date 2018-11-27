#include "animation.h"
#include "game.h"

#include <QDebug>


extern xGame *game;

xAnimation::xAnimation(QObject *parent, QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame) :
    p(parent),
    name(nName),
    type(nType),
    timespan(nTimespan),
    startFrame(nStartFrame),
    stopFrame(nStopFrame)
{
    timeLine = new QTimeLine(timespan, this);
    timeLine->setFrameRange(startFrame, stopFrame);

    animView.setPixmap(QPixmap(":/anim/" + name + ".png"));
    animView.setZValue(9);
    animView.setVisible(false);
    game->scene->addItem(&animView);

    //connect anim's timeline to the type of anim + connect delete on finished timeline
    if (type == "attack") { connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(attackAnim(int))); }
    connect(timeLine, SIGNAL(finished()), this, SLOT(stopAnim()));

    startAnim(); //auto-launch anim
}

QObject* xAnimation::getParent() { return p; }

QGraphicsPixmapItem* xAnimation::getAnimView() { return &animView; }

void xAnimation::startAnim() {
    hit = false;
    timeLine->start();
}

void xAnimation::attackAnim(int frame) {

    //create a pointer to grand-parent xCharacter (xCharacter << xWeapon << xAnimation)
    xWeapon *w = dynamic_cast<xWeapon *>(p);
    xCharacter *c = dynamic_cast<xCharacter *>(w->getParent());

    c->setIsAttacking(true);
    animView.setVisible(true);

    if (c->getDirection() == "back")
    {
        animView.setRotation(-115 + frame); //-90 (-115 to -80)
        animView.setPos(c->getView()->pos().x() + PixelsX/2 - 6, c->getView()->pos().y() + PixelsY/2);
        c->getView()->setViewName("hero_back_" + w->getName());
    }
    else if (c->getDirection() == "front")
    {
        animView.setRotation(65 + frame);//90 (65 to 100)
        animView.setPos(c->getView()->pos().x() + PixelsX/2 + 6, c->getView()->pos().y() + PixelsY/2);
        c->getView()->setViewName("hero_front_" + w->getName());
    }
    else if (c->getDirection() == "right")
    {
        animView.setRotation(-25 + frame); //0 (-25 to 10)
        animView.setPos(c->getView()->pos().x() + PixelsX/2, c->getView()->pos().y() + PixelsY/2 - 6);
        c->getView()->setViewName("hero_right_" + w->getName());
    }
    else if (c->getDirection() == "left")
    {
        animView.setRotation(155 + frame); //180 (155 to 190)
        animView.setPos(c->getView()->pos().x() + PixelsX/2, c->getView()->pos().y() + PixelsY/2 + 6);
        c->getView()->setViewName("hero_left_" + w->getName());
    }

    //check if anim is hitting an enemy, if already hit during animation, don't check anymore
    if (hit == false) { hit = c->checkAttack(); }
}

void xAnimation::stopAnim()
{
    //create a pointer to grand-parent xCharacter (xCharacter << xWeapon << xAnimation)
    xWeapon *w = dynamic_cast<xWeapon *>(p);
    xCharacter *c = dynamic_cast<xCharacter *>(w->getParent());

    if (type == "attack") { c->setIsAttacking(false); }

    delete this;
}
