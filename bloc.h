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
    bool obstacle;

public:
    xBloc(QString blocName);
    void keyPressEvent(QKeyEvent *event);

    void setName (QString nName);
    QString getName();

    void setX (int nX);
    void setY (int nY);
    int getX();
    int getY();

    void defineIfObstacle(QString blocName);
    bool isObstacle();
};

#endif // BLOC_H
