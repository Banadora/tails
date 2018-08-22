
#include "SceneBlock.h"

////////// init

SceneBlock::SceneBlock(QString blockName) :
    blockName(blockName)
{

    setPixmap(QPixmap(":/img/" + blockName + ".png"));
}

void SceneBlock::set_obstacle(bool value) {
  obstacle = value;
}

