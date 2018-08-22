#ifndef _MAP_H
#define _MAP_H


#include <QString>

#include <QGraphicsScene>


class SceneBlock;

class Map : public QGraphicsScene {
  private:
    QString mapNorth;

    QString mapEast;

    QString mapSouth;

    QString mapWest;


  public:
    void saveAsXML(const QString & mapFilePath);

    bool isPosObstacle(int x, int y);

    bool isPosOutOfBounds(int x, int y);

    Map loadFromXML(const QString & mapFilePath);


  private:
    <SceneBlock> ;

};
#endif
