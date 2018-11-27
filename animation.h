#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>


class xAnimation : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    QObject *p; //parent object

    QString name;
    QString type;

    bool hit;

    QGraphicsPixmapItem animView;

    QTimeLine *timeLine;
    int timespan;
    int startFrame;
    int stopFrame;

public:
    xAnimation(QObject *parent, QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame);

    QObject *getParent();

    QGraphicsPixmapItem *getAnimView();

    QTimeLine *getTimeline();

    void startAnim();

public slots:
    void attackAnim(int frame);
    void stopAnim();
};

#endif // ANIMATION_H
