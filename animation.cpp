#include "animation.h"
#include "game.h"


extern xGame *game;

xAnimation::xAnimation(QString nName, int nStartFrame, int nStopFrame) :
    name(nName),
    startFrame(nStartFrame),
    stopFrame(nStopFrame)
{
    animView.setPixmap(QPixmap(":/img/anim_" + name + ".png"));
    animView.setZValue(9);
    animView.setVisible(false);

    timeLine->setFrameRange(startFrame, stopFrame);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(attackAnim(int)));
    connect(timeLine, SIGNAL(finished()), this, SLOT(stopAnim()));
}

void xAnimation::setName(QString nName) { name = nName; }
QString xAnimation::getName() { return name; }

QGraphicsPixmapItem* xAnimation::getAnimView() { return &animView; }

QTimeLine *xAnimation::getTimeLine() { return timeLine; }

void xAnimation::startAnim() {
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
}

void xAnimation::stopAnim()
{
    delete this;
}
