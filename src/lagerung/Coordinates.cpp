//
// Created by Michael Variola on 10/12/2019.
//

#include "Coordinates.h"

std::ostream& operator << (std::ostream& ostream, Coordinates coordinates){
    ostream << "X-Coord: " << coordinates.x_ << "\n";
    ostream << "Y-Coord: " << coordinates.y_ << "\n";
    ostream << "Z-Coord: " << coordinates.z_ << "\n\n";

    return ostream;
}

bool Coordinates::operator==(const Coordinates &coordinates) {
    return x_ == coordinates.x_ && y_ == coordinates.y_ && z_ == coordinates.z_;
}