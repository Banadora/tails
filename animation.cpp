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

    animView.setPixmap(QPixmap(":/anim/" + name));
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
QTimeLine* xAnimation::getTimeline() { return timeLine; }

void xAnimation::startAnim() {
    hit = false;
    timeLine->start();
}

void xAnimation::attackAnim(int frame) {

    //create a pointer to grand-parent xCharacter (xCharacter << xWeapon << xAnimation)
    xWeapon *w = new xWeapon(nullptr, "none");
    w = dynamic_cast<xWeapon *>(p);
    xCharacter *c = new xCharacter("");
    c = dynamic_cast<xCharacter *>(w->getParent());

    c->setIsAttacking(true);
    animView.setVisible(true);

    animView.setRotation(c->getAttackAngle() + frame);
    animView.setPos(c->getAttackPos());

    //check if anim is hitting an enemy, if already have hit during animation, don't check anymore
    if (hit == false) { hit = c->checkAttack(); }

    //check if last frame
    if (frame == stopFrame) {
        c->setIsAttacking(false);
        if (c->getName().contains("hero")) {
            //replace "none" in view's name with weapon's name
            c->getView()->setViewName(c->getView()->getViewName().replace("none", c->getWeapon()->getName()));
        }
    }
}

void xAnimation::stopAnim()
{
    //game->scene->removeItem(&animView);
    delete this;
}
