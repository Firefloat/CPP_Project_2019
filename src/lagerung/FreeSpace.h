#ifndef SRC_FREESPACE_H
#define SRC_FREESPACE_H

#include "Coordinates.h"

struct FreeSpace {

private:

public:
    Coordinates previous_;
    Coordinates next_;

    FreeSpace(Coordinates previous, Coordinates next) : previous_(previous), next_(next) {};

};

#endif //SRC_FREESPACE_H
