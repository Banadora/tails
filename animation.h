#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>


class xAnimation : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    QString name;

    QGraphicsPixmapItem animView;

    QTimeLine *timeLine = new QTimeLine(120, this);
    int startFrame;
    int stopFrame;

    QTimer *stopAnimTimer;

public:
    xAnimation(QString nName, int nStartFrame, int nStopFrame);

    void setName (QString nName);
    QString getName();

    QGraphicsPixmapItem *getAnimView();

    QTimeLine *getTimeLine();

    void startAnim();

public slots:
    void attackAnim(int frame);
    void stopAnim();
};

#endif // ANIMATION_H
