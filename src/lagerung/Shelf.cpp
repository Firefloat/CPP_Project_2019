#include "Shelf.h"

// method for initializing
void Shelf::init(){
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

Shelf::Shelf(){
    init();
}

Shelf::Shelf(Coordinates coordinates) : coordinates_(coordinates){
    init();
}


std::tuple<Coordinates, double> Shelf::GetFreeSpace(const Container& container){

    Coordinates bestCoords;
    // set difference to max value
    double smallestDifference{FLT_MAX};
    // retrieve container gap
    double containerGap = Loaderton::Instance().getJsonData()["container"]["gap"];
    // get optimal position for container
    double optimalPosition{container.GetPrioPos()};

    for (auto &board : boards_){
        for (auto &freeSpace : board.GetFreeSpace(container)){
            // TODO: get vector by reference
            double freeSpaceXCoord{freeSpace.previous_.z_ + (freeSpace.next_.z_ - freeSpace.previous_.z_)/2};
            double absDistancePrevious{std::abs(optimalPosition - freeSpace.previous_.z_)};
            double absDistanceNext{std::abs(optimalPosition - freeSpace.next_.z_)};
            double absDistanceCenter{std::abs(optimalPosition - freeSpaceXCoord)};
            // check if absolute difference is smaller than optimal
            if (absDistancePrevious < smallestDifference) {
                // set coordinates to new optimum
                bestCoords = freeSpace.previous_;
                bestCoords.z_ = freeSpace.previous_.z_ + containerGap + (container.size_.width_/2);
                smallestDifference = absDistancePrevious;
            }
            if(absDistanceNext < smallestDifference) {
                bestCoords = freeSpace.next_;
                bestCoords.z_ = freeSpace.next_.z_ - containerGap - (container.size_.width_/2);
                smallestDifference = absDistanceNext;
            }
            if(absDistanceCenter  < smallestDifference) {
                bestCoords = freeSpace.next_;
                bestCoords.z_ = freeSpaceXCoord;
                smallestDifference = absDistanceCenter;
            }
        }
    }
    return std::make_tuple(bestCoords, smallestDifference);
}

Container Shelf::Remove(Coordinates coordinates) {
    // TODO
    return Container(size_, Article(muttern,high,2));
}

void Shelf::Store(Container &container) {
    double epsilon = 0.01f;
    for (auto &board : boards_){
        if (std::fabs(board.coordinates_.y_ - container.coordinates_.y_) < epsilon){
            board.Store(container);
            std::cout << "Store Container in Shelf at x = " << coordinates_.x_ << "\n";
            break;
        }
    }
}