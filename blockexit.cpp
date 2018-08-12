#include "blockexit.h"


//////////////////////////////////////////////////Getters
///
int xBlockExit::getDestinationLayout() const
{
    return destinationLayout;
}

int xBlockExit::getDestinationX() const
{
    return destinationX;
}

int xBlockExit::getDestinationY() const
{
    return destinationY;
}


///////////////////////////////////////////////Constructors
///
///
xBlockExit::xBlockExit() :
    xBlock()
{ }

xBlockExit::xBlockExit(QString blocName) :
    xBlock(blocName)
{ }

xBlockExit::xBlockExit(QString blocName, int nDestinationLayout, int nDestinationX, int nDestinationY) :
    xBlock(blocName)
{
    destinationLayout = nDestinationLayout;
    destinationX = nDestinationX;
    destinationY = nDestinationY;
}

