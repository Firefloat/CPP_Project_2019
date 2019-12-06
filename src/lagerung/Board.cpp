#include "Board.h"

Board::Board(Size size, Coordinates coordinates) : size_(size), coordinates_(coordinates) {
    double containerSize = Loaderton::Instance().getJsonData()["container"]["width_c1"];
    storedContainers_.reserve((int)(size_.width_ / containerSize));
}

std::vector<FreeSpace> Board::GetFreeSpace(const Container& container) {
    auto resultVector = std::vector<FreeSpace>{};

    // get coordinates of start and end of board
    Coordinates tempCoordsPrev{coordinates_.x_-0.5*size_.width_, coordinates_.y_, coordinates_.z_};
    Coordinates tempCoordsNext{coordinates_.x_+0.5*size_.width_, coordinates_.y_, coordinates_.z_};

    // if no container is stored, return whole board as empty
    if (storedContainers_.empty()){
        resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
    }
    // otherwise filter spaces
    else{
        for (auto containerLoop : storedContainers_){
            // calculate start and end coordinates of container
            auto start = containerLoop.coordinates_.x_ - 0.5*containerLoop.size_.width_;
            auto end = containerLoop.coordinates_.x_ + 0.5*containerLoop.size_.width_;

            // if container is at start of shelf or at the end of another container
            if (start == tempCoordsPrev.x_){
                tempCoordsPrev.x_ = end;
                continue;
            }
            else{
                tempCoordsNext.x_ = start;
                if ((end - start) >= container.size_.width_){
                    resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
                }
                tempCoordsPrev.x_ = end;
            }
            // TODO Verify if it works as intended
        }
    }
    return resultVector;
}

void Board::Store(Container container) {
    // TODO
}

Container Board::Remove(Coordinates coordinates) {
    // TODO
}