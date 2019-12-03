#ifndef SRC_QUEUE_H
#define SRC_QUEUE_H

#include <queue>
#include "Size.h"
#include "Coordinates.h"
#include "Container.h"

class Queue {

private:

public:
    Size size_;
    Coordinates coordinates_;
    std::queue<Container> containerQueue_;



};


#endif //SRC_QUEUE_H
