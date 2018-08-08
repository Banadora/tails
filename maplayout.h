#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include <QString>

class xMapLayout {

    QString layout[12];

public:
    void setLayout(int layoutNumber);
    QString getBlocName(int x, int y);
};



#endif // MAPLAYOUT_H
