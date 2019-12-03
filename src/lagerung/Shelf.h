#ifndef SRC_SHELF_H
#define SRC_SHELF_H

#include <vector>
#include "Size.h"
#include "Board.h"

class Shelf {

private:

public:
    Size size_;
    std::vector<Board> boards_;

    Shelf(Size size) : size_(size) {
        //boards_(/*TODO: Count*/, Board(Size, Coordinates));
    };

    void Store(Container container);
    Container Remove(Coordinates coordinates);

};


#endif //SRC_SHELF_H
