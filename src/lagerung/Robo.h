#ifndef SRC_ROBO_H
#define SRC_ROBO_H

#include "Queue.h"
#include "Coordinates.h"
#include "Shelf.h"
#include "Container.h"

class Robo {

private:

public:
    Coordinates coordinates_;
    Queue leftQueue_;
    Queue rightQueue_;
    Shelf leftShelf_;
    Shelf rightShelf_;

    // TODO: Actionqueue

    Robo(Coordinates coordinates);

};


#endif //SRC_ROBO_H
