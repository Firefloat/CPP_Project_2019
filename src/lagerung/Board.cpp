#include "Board.h"

Board::Board(Size size, Coordinates coordinates) : size_(size), coordinates_(coordinates) {
    double containerSize = Loaderton::Instance().getJsonData()["container"]["width_c1"];
    storedContainers_.reserve((int)(size_.width_ / containerSize));
}

Board::Board(const Board &other) : storedContainers_{other.storedContainers_}{
    std::lock_guard<std::mutex> lock_other(const_cast<std::mutex&>(other.protector));
    size_ = other.size_;
    coordinates_ = other.coordinates_;
}

std::vector<FreeSpace> Board::GetFreeSpace(const Container& container) {
    double containerGap = Loaderton::Instance().getJsonData()["container"]["gap"];

    double epsilon = 0.01f;

    auto resultVector = std::vector<FreeSpace>{};

    // get coordinates of start and end of board
    Coordinates tempCoordsPrev{coordinates_.x_, coordinates_.y_, coordinates_.z_-0.5*size_.width_};
    Coordinates tempCoordsNext{coordinates_.x_, coordinates_.y_, coordinates_.z_+0.5*size_.width_};

    std::lock_guard<std::mutex> lock(protector);
    // if no container is stored, return whole board as empty
    if (storedContainers_.empty()){
        resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
    }
    // otherwise filter spaces
    else{

        // TODO: remove deprecated for loope
        for (auto &containerLoop : storedContainers_){
            // calculate start and end coordinates of container
            auto start = containerLoop.coordinates_.z_ - 0.5*containerLoop.size_.width_;
            auto end = containerLoop.coordinates_.z_ + 0.5*containerLoop.size_.width_;

            // if container is at start of shelf or at the end of another container
            // -> floats/doubles are more or less the same
            if (std::fabs(start - (tempCoordsPrev.z_ + containerGap)) < epsilon){
                tempCoordsPrev.z_ = end;
                resultVector.emplace_back(tempCoordsPrev, tempCoordsNext);
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

void Board::Store(Container &container) {
    std::cout << "Store Container in Board at y = " << coordinates_.y_ << "\n";
    std::lock_guard<std::mutex> lock(protector);

    for (auto it = storedContainers_.begin(); it < storedContainers_.end(); it++){
        if (container.coordinates_.z_ == it->coordinates_.z_){
            *it = container;
            break;
        }
        // insert after
        if (container.coordinates_.z_ > it->coordinates_.z_){
            storedContainers_.insert(it+1, container);
            break;
        }
    }
    // check if empty, insert at beginning
    if (storedContainers_.empty()){
        storedContainers_.push_back(container);
    }
}

Container Board::Remove(Coordinates coordinates) {
    std::lock_guard<std::mutex> lock(protector);
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