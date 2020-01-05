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
    double epsilon = 0.01f;

    return (std::fabs(x_ - coordinates.x_) <= epsilon) && (std::fabs(y_ - coordinates.y_) <= epsilon) && (std::fabs(z_ - coordinates.z_) <= epsilon);
}