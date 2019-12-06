#ifndef SRC_SHELF_H
#define SRC_SHELF_H

#include <vector>
#include "../setup/Loaderton.h"
#include "Size.h"
#include "Board.h"

class Shelf {

private:

public:
    Size size_;
    double boardHeight_;
    std::vector<Board> boards_;

    Shelf();

    void Store(Container container);
    Container Remove(Coordinates coordinates);
    std::vector<std::vector<FreeSpace>> GetFreeSpace();
};


#endif //SRC_SHELF_H
