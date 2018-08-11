#include "maplayout.h"
#include "game.h"


xMapLayout::xMapLayout() :
    startX(1),
    startY(1)
{
    for (int i = 0; i < 10; i++) { exitsX[i] = -1; exitsY[i] = -1; }
}

////////// visually define layout of blocks and hero start position
void xMapLayout::setLayout(int layoutNumber) {

    switch (layoutNumber) {
        case 1:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g1 g1 g0 g1 g1 g1 g1 m0 g1 g1 g1 g1"  ; //y = 0
            layout[1] =   "g1 g0 g0 g0 g1 g0 g0 m0 g1 g0 g0 g1"  ; //y = 1
            layout[2] =   "g1 g0 g1 g0 g1 m2 m1 m4 g1 g0 g0 g1"  ; //y = 2
            layout[3] =   "g1 g0 g0 g0 g0 m0 g1 g1 g0 g0 g0 g1"  ; //y = 3
            layout[4] =   "g1 g0 g1 g0 g0 m0 g0 g1 g1 g0 g0 g1"  ; //y = 4
            layout[5] =   "g1 g0 g0 g0 g1 m5 m1 m3 g0 g1 g0 g1"  ; //y = 5
            layout[6] =   "g1 g0 g0 g1 g1 g1 g0 m0 g0 g0 g0 g1"  ; //y = 6
            layout[7] =   "g1 g0 g1 g0 g0 g0 m2 m4 g0 g1 g0 g1"  ; //y = 7
            layout[8] =   "g1 g1 g0 g0 g1 g0 m0 g0 g1 g1 g0 g1"  ; //y = 8
            layout[9] =   "g1 g0 g0 g1 m2 m1 m4 g0 g1 g1 g0 g1"  ; //y = 9
            layout[10] =  "g1 g0 g0 g0 m0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 10
            layout[11] =  "g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1"  ; //y = 11

            startX = 4; startY = 10;
            exitsX[1] = 7; exitsY[1] = 0;
            exitsX[2] = 2; exitsY[2] = 0;
            break;

        case 2:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1"  ; //y = 0
            layout[1] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 1
            layout[2] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 2
            layout[3] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 3
            layout[4] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 4
            layout[5] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 5
            layout[6] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 6
            layout[7] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 7
            layout[8] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 8
            layout[9] =   "g1 g0 g0 g0 g0 g0 g0 m6 g0 g0 g0 g1"  ; //y = 9
            layout[10] =  "g1 g0 g0 g0 g0 g0 g0 m0 g0 g0 g0 g1"  ; //y = 10
            layout[11] =  "g1 g1 g0 g1 g1 g1 g1 m0 g1 g1 g1 g1"  ; //y = 11

            break;
    }
}

int xMapLayout::getStartX() { return startX; }
int xMapLayout::getStartY() { return startY; }
void xMapLayout::setStartX(int nX) { startX = nX; }
void xMapLayout::setStartY(int nY) { startY = nY; }

int xMapLayout::getExitsX(int index) { return exitsX[index]; }
int xMapLayout::getExitsY(int index) { return exitsY[index]; }

////////// get the real name of block from layout identifier
QString xMapLayout::getBlockName(int x, int y) {

    QString block;

    block = layout[y].mid(x*3, 2);

    if (block == "g0") { return "grass0"; }
    else if (block == "g1") { return "grass1"; }
    else if (block == "m0") { return "mud0"; }
    else if (block == "m1") { return "mud1"; }
    else if (block == "m2") { return "mud2"; }
    else if (block == "m3") { return "mud3"; }
    else if (block == "m4") { return "mud4"; }
    else if (block == "m5") { return "mud5"; }
    else if (block == "m6") { return "mud6"; }
    else { return "blank"; }
}

