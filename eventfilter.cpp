#include "eventfilter.h"
#include "game.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QKeyEvent>
#include <QList>
#include <QDebug>

extern xGame *game;

xEventFilter::xEventFilter(QObject *parent, xMainWindow *nW) :
    QObject(parent),
    w(nW)
{
    qDebug() << w;
}

bool xEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    /*QList<QWidget *> apps = QApplication::topLevelWidgets();
    xMainWindow *mw = dynamic_cast<xMainWindow*>(apps[0]);
    w = mw;*/

    if (event->type() != QEvent::KeyPress)
        return QObject::eventFilter(obj, event);

    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

    switch(keyEvent->key()) {
        //selection movements
        case Qt::Key_Z:         { game->hero->moveView("north"); break; }
        case Qt::Key_Up:        { game->hero->moveView("north"); break; }
        case Qt::Key_S:         { game->hero->moveView("south"); break; }
        case Qt::Key_Down:      { game->hero->moveView("south"); break; }
        case Qt::Key_Q:         { game->hero->moveView("west"); break; }
        case Qt::Key_Left:      { game->hero->moveView("west"); break; }
        case Qt::Key_D:         { game->hero->moveView("east"); break; }
        case Qt::Key_Right:     { game->hero->moveView("east"); break; }

        case Qt::Key_Space:     { game->hero->attack(); break; }

    }

    return true;
}
