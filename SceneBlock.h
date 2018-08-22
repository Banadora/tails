#ifndef _SCENEBLOCK_H
#define _SCENEBLOCK_H


#include <QGraphicsPixmapItem>

#include <QObject>

#include <QString>


class SceneBlock : public QGraphicsPixmapItem, public QObject {
  Q_OBJECT
  protected:
    int width;

    int height;

    bool obstacle=  false;


  private:
    QString blockName=  "";


  public:
    SceneBlock(QString blockName);

    inline const bool get_obstacle() const;

    void set_obstacle(bool value);

};
inline const bool SceneBlock::get_obstacle() const {
  return obstacle;
}

#endif
