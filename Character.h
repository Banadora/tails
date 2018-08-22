#ifndef _CHARACTER_H
#define _CHARACTER_H


#include "CharacterView.h"
#include <QString>


class Character {
  private:
    CharacterView characterView;


  public:
    Character(const QString & QItemName);

};
#endif
