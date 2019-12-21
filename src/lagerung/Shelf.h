#ifndef SRC_SHELF_H
#define SRC_SHELF_H

#include <vector>
#include "../setup/Loaderton.h"
#include "Size.h"
#include "Board.h"
#include <cmath>

class Shelf {

private:

public:
    Coordinates coordinates_;
    Size size_;
    double boardHeight_;
    std::vector<Board> boards_;

    Shelf();
    Shelf(Coordinates coordinates);

    void Store(Container container);
    Container Remove(Coordinates coordinates);
    Coordinates GetFreeSpace(const Container& container);
};


#endif //SRC_SHELF_H
