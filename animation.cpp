#include "animation.h"
#include "game.h"


extern xGame *game;

xAnimation::xAnimation(QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame) :
    name(nName),
    type(nType),
    timespan(nTimespan),
    startFrame(nStartFrame),
    stopFrame(nStopFrame)
{
    timeLine = new QTimeLine(timespan, this);
    timeLine->setFrameRange(startFrame, stopFrame);

    animView.setPixmap(QPixmap(":/img/anim_" + name + ".png"));
    animView.setZValue(9);
    animView.setVisible(false);

    //connect anim's timeline to the type of anim + connect delete on finished timeline
    if (type == "attack") { connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(attackAnim(int))); }
    connect(timeLine, SIGNAL(finished()), this, SLOT(stopAnim()));
}

QGraphicsPixmapItem* xAnimation::getAnimView() { return &animView; }

void xAnimation::startAnim() {
    game->hero->setIsAttacking(true);
    hit = false;
    animView.setVisible(false);
    timeLine->start();
}

void xAnimation::attackAnim(int frame) {
    animView.setVisible(true);
    if (game->hero->getDirection() == "back")
    {
        animView.setRotation(-115 + frame); //-90 (-115 to -80)
        animView.setPos(game->hero->getView()->pos().x() + PixelsX/2 - 6, game->hero->getView()->pos().y() + PixelsY/2);
    }
    else if (game->hero->getDirection() == "front")
    {
        animView.setRotation(65 + frame);//90 (65 to 100)
        animView.setPos(game->hero->getView()->pos().x() + PixelsX/2 + 6, game->hero->getView()->pos().y() + PixelsY/2);
    }
    else if (game->hero->getDirection() == "right")
    {
        animView.setRotation(-25 + frame); //0 (-25 to 10)
        animView.setPos(game->hero->getView()->pos().x() + PixelsX/2, game->hero->getView()->pos().y() + PixelsY/2 - 6);
    }
    else if (game->hero->getDirection() == "left")
    {
        animView.setRotation(155 + frame); //180 (155 to 190)
        animView.setPos(game->hero->getView()->pos().x() + PixelsX/2, game->hero->getView()->pos().y() + PixelsY/2 + 6);
    }

    //check if anim is hitting an enemy, if already hit during animation, don't check anymore
    if (hit == false) { hit = game->hero->checkAttack(); }
}

void xAnimation::stopAnim()
{
    if (type == "attack") { game->hero->setIsAttacking(false); }
    delete this;
}
