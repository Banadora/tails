
#include "maplayout.h"


void xMapLayout::setLayout(int layoutNumber) {

    switch (layoutNumber) {
        case 1:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0"  ; //y = 0
            layout[1] =   "g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0"  ; //y = 1
            layout[2] =   "g0 g0 g0 g0 g0 g0    g0 g0 g0 g0 g0"  ; //y = 2
            layout[3] =   "g0 g0 g0 g0 g0 g0    g0 g0 g0 g0 g0"  ; //y = 3
            layout[4] =   "g0 g0 g0 g0 g0 g0    g0 g0 g0 g0 g0"  ; //y = 4
            layout[5] =   "g0 g0 g0 g0 g0 g0       g0 g0 g0 g0"  ; //y = 5
            layout[6] =   "g0 g0 g0 g0 g0 g0 g0    g0 g0 g0 g0"  ; //y = 6
            layout[7] =   "g0 g0 g0 g0 g0 g0       g0 g0 g0 g0"  ; //y = 7
            layout[8] =   "g0 g0 g0 g0 g0 g0    g0 g0 g0 g0 g0"  ; //y = 8
            layout[9] =   "g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0"  ; //y = 9
            layout[10] =  "g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0"  ; //y = 10
            layout[11] =  "g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0"  ; //y = 11
            break;

        case 2:
            break;
    }

}

QString xMapLayout::getBlocName(int x, int y) {

    QString bloc;

    bloc = layout[y].mid(x*3,2);

    if (bloc == "g0") { return "grass0"; }
    else { return "blank"; }
}
