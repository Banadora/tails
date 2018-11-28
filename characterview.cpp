#include "characterview.h"
#include "block.h"
#include "enemy.h"
#include "game.h"

#include <QDebug>


extern xGame *game;


xCharacterView::xCharacterView()
{ }

xCharacterView::xCharacterView(QObject *parent, QString viewName) :
    p(parent),
    name(viewName)
{
    setPixmap(QPixmap(":/img/" + viewName));
}

QObject* xCharacterView::getParent() { return p; }

QString xCharacterView::getViewName() { return name; }

void xCharacterView::setViewName(QString nName)
{
    name = nName;
    setPixmap(QPixmap(":/img/" + name));
}

//move char on scene, return true if OK, false if the char didn't move (eg:obstacle)
bool xCharacterView::move(double nPosX, double nPosY) {

    QPointF oldPos(pos().x(), pos().y());
    QPointF newPos(nPosX, nPosY);

    //moving
    setPos(newPos);

    //check is new pos is on obstacle, if true get back to old pos
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            if (dynamic_cast<xBlock*>(colliding_items[i])->getIsObstacle()) { setPos(oldPos); return false;}
        }
        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) { setPos(oldPos); return false; }
    }

    return true;
}
