#include "Board.h"

Board::Board(Size size, Coordinates coordinates) : size_(size), coordinates_(coordinates) {
    double containerSize = Loaderton::Instance().getJsonData()["container"]["width_c1"];
    storedContainers_.reserve((int)(size_.width_ / containerSize));
}

std::vector<FreeSpace> Board::GetFreeSpace(const Container& container) {
    std::lock_guard lock(protector);

    auto resultVector = std::vector<FreeSpace>{};

    // get coordinates of start and end of board
    Coordinates tempCoordsPrev{coordinates_.x_, coordinates_.y_, coordinates_.z_-0.5*size_.width_};
    Coordinates tempCoordsNext{coordinates_.x_, coordinates_.y_, coordinates_.z_+0.5*size_.width_};

    // if no container is stored, return whole board as empty
    if (storedContainers_.empty()){
        resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
    }
    // otherwise filter spaces
    else{
        for (auto containerLoop : storedContainers_){
            // calculate start and end coordinates of container
            auto start = containerLoop.coordinates_.z_ - 0.5*containerLoop.size_.width_;
            auto end = containerLoop.coordinates_.z_ + 0.5*containerLoop.size_.width_;

            // if container is at start of shelf or at the end of another container
            if (start == tempCoordsPrev.z_){
                tempCoordsPrev.z_ = end;
                continue;
            }
            else{
                tempCoordsNext.z_ = start;
                if ((end - start) >= container.size_.width_){
                    resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
                }
                tempCoordsPrev.z_ = end;
            }
            // TODO: Verify if it works as intended
        }
    }
    return resultVector;
}

void Board::Store(Container container) {
    std::lock_guard lock(protector);
    for (auto it = storedContainers_.begin(); it < storedContainers_.end(); it++){
        // insert after
        if (container.coordinates_.z_ > it->coordinates_.z_){
            storedContainers_.insert(it+1, container);
            break;
        }
    }
}

Container Board::Remove(Coordinates coordinates) {
    std::lock_guard lock(protector);
    Container containerToRemove{};
    // find container
    for (auto found = storedContainers_.begin(); found < storedContainers_.end(); found++){
        if (found->coordinates_ == coordinates){
            // copy container to remove into variable
            containerToRemove = *found;
            // delete container in vector
            storedContainers_.erase(found);
            break;
        }
    }
    return containerToRemove;
}