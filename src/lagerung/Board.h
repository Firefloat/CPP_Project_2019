#ifndef SRC_BOARD_H
#define SRC_BOARD_H

#include <vector>
#include "Size.h"
#include "Coordinates.h"
#include "FreeSpace.h"
#include "Container.h"

class Board {

private:

public:
    Size size_;
    Coordinates coordinates_;
    std::vector<Container> storedContainers_;

    Board(Size size, Coordinates coordinates) : size_(size), coordinates_(coordinates) {
        storedContainers_.reserve(/*TODO: Calculate*/1);
    };

    std::vector<FreeSpace> GetFreeSpace();
    void Store(Container container);
    Container Remove(Coordinates coordinates);

};


#endif //SRC_BOARD_H
