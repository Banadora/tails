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
    QString type;

    bool hit;

    QGraphicsPixmapItem animView;

    QTimeLine *timeLine;
    int timespan;
    int startFrame;
    int stopFrame;

    QTimer *stopAnimTimer;

public:
    xAnimation(QString nName, QString nType, int nTimespan, int nStartFrame, int nStopFrame);

    QGraphicsPixmapItem *getAnimView();

    void startAnim();

public slots:
    void attackAnim(int frame);
    void stopAnim();
};

#endif // ANIMATION_H
