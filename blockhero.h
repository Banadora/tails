#ifndef BLOCKHERO_H
#define BLOCKHERO_H

#include "block.h"


class xBlockHero : public xBlock {

public:
    xBlockHero(QString blocName);

    void move(QString direction);
};

#endif // BLOCKHERO_H
