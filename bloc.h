#ifndef BLOC_H
#define BLOC_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


class xBloc : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    QString name;
    int width;
    int height;
    int x;
    int y;

public:
    xBloc(QString blocName);
    void keyPressEvent(QKeyEvent *event);

    void setX (int nX);
    void setY (int nY);
    int getX();
    int getY();
};

#endif // BLOC_H
