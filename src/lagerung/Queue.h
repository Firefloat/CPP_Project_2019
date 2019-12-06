#ifndef SRC_QUEUE_H
#define SRC_QUEUE_H

#include <queue>
#include "Size.h"
#include "Coordinates.h"
#include "Container.h"
#include "../setup/Loaderton.h"

class Queue {

private:

public:
    Size size_;
    Coordinates coordinates_;
    std::queue<Container> containerQueue_;

    Queue() {
        size_.width_ = Loaderton::Instance().getJsonData()["conveyor_belt"]["length_queue"];
    }
};


#endif //SRC_QUEUE_H
