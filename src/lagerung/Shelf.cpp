#include "Shelf.h"

Shelf::Shelf() {
    size_.width_ = Loaderton::Instance().getJsonData()["shelf"]["width"];
    size_.height_ = Loaderton::Instance().getJsonData()["shelf"]["height_total"];
    size_.depth_ = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    boardHeight_ = Loaderton::Instance().getJsonData()["shelf"]["height_board"];

    double boardCount = (int)(size_.height_ / boardHeight_);
    boards_.reserve(boardCount);

    for(int index = 0; index < boardCount; index++) {
        boards_.emplace_back(Size(size_.width_, boardHeight_, size_.depth_),
                Coordinates(coordinates_.x_,(index * boardHeight_ + boardHeight_ / 2), (size_.width_ / 2)));
    }
}

Shelf::Shelf(Coordinates coordinates) : coordinates_(coordinates){
    // lean on standard constructor
    Shelf();
}


Coordinates Shelf::GetFreeSpace(const Container& container){

    Coordinates bestCoords;
    // set difference to max value
    double smallestDifference{MAXFLOAT};
    // retrieve container gap
    double containerGap = Loaderton::Instance().getJsonData()["container"]["gap"];
    // get optimal position for container
    double optimalPosition{container.GetPrioPos()};

    for (auto board : boards_){

        for (auto freeSpace : board.GetFreeSpace(container)){
            // TODO get vector by reference
            double freeSpaceXCoord{freeSpace.previous_.x_ + (freeSpace.next_.x_ - freeSpace.previous_.x_)/2};
            double absDistancePrevious{std::abs(optimalPosition - freeSpace.previous_.x_)};
            double absDistanceNext{std::abs(optimalPosition - freeSpace.next_.x_)};
            double absDistanceCenter{std::abs(optimalPosition - freeSpaceXCoord)};
            // check if absolute difference is smaller than optimal
            if (absDistancePrevious < smallestDifference) {
                // set coordinates to new optimum
                bestCoords = freeSpace.previous_;
                bestCoords.x_ = freeSpace.previous_.x_ + containerGap + (container.size_.width_/2);
                smallestDifference = absDistancePrevious;
            }
            if(absDistanceNext < smallestDifference) {
                bestCoords = freeSpace.next_;
                bestCoords.x_ = freeSpace.next_.x_ - containerGap - (container.size_.width_/2);
                smallestDifference = absDistanceNext;
            }
            if(absDistanceCenter  < smallestDifference) {
                bestCoords = freeSpace.next_;
                bestCoords.x_ = freeSpaceXCoord;
                smallestDifference = absDistanceCenter;
            }
        }
    }
    return bestCoords;
}

Container Shelf::Remove(Coordinates coordinates) {
    // TODO
}