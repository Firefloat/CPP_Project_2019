#ifndef SRC_COORDINATES_H
#define SRC_COORDINATES_H

#include <iostream>

struct Coordinates {

private:

public:
    double x_;
    double y_;
    double z_;

    Coordinates() {
        x_ = 0;
        y_ = 0;
        z_ = 0;
    }

    Coordinates(double x, double y, double z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    friend std::ostream& operator << (std::ostream& ostream, Coordinates coordinates);

};

#endif //SRC_COORDINATES_H
