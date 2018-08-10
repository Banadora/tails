#ifndef BLOCKHERO_H
#define BLOCKHERO_H

#include "block.h"


class xBlockHero : public xBlock {

public:
    xBlockHero(QString blocName);

    void keyPressEvent(QKeyEvent *event);
};

#endif // BLOCKHERO_H
