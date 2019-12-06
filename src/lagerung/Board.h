#ifndef SRC_BOARD_H
#define SRC_BOARD_H

#include <vector>
#include "../setup/Loaderton.h"
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

    Board(Size size, Coordinates coordinates);

    std::vector<FreeSpace> GetFreeSpace(const Container& container);
    void Store(Container container);
    Container Remove(Coordinates coordinates);
};


#endif //SRC_BOARD_H
