#include <iostream>
#include "StorageManager.h"

StorageManager::StorageManager() {
    shelfAmount_ = Loaderton::Instance().getJsonData()["shelf"]["amount"];
    conveyorBeltLength_ = Loaderton::Instance().getJsonData()["conveyor_belt"]["length_to_first_shelf"];
    shelfDepth_ = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    shelfGap_ = Loaderton::Instance().getJsonData()["shelf"]["gap"];
    shelfHeight_ = Loaderton::Instance().getJsonData()["shelf"]["height_total"];

    int roboAmount = shelfAmount_ / 2;
    robots_.reserve(roboAmount);

    for(int index = 0; index < roboAmount; index++) {
        double roboPositionX = (conveyorBeltLength_ + ((float)index * (shelfDepth_ * 2 + shelfGap_)) +
                (shelfDepth_ + (shelfGap_ / 2)));

        robots_.emplace_back(
                Coordinates{roboPositionX,(shelfDepth_ / 2), 0},
                Coordinates{roboPositionX,(shelfDepth_ / 2), 0},
                Coordinates{roboPositionX, 0, 0});
    }
}

void StorageManager::RemoveFromStorage(ArticleType articleType, int amount) {


}

Coordinates StorageManager::FindOptimalSpace(const Container& container) {

    auto getFreeSpaceFromShelfs = [&](Shelf shelf) { return shelf.GetFreeSpace(container); };
    std::tuple<Coordinates, int> resultTuple;
    double smallestDifference{FLT_MAX};
    Coordinates bestCoords{};
    int weight{1};

    for (const auto& robo : robots_){
        if (robo.isAvailable){
            weight = 0;
        }
        // retrieve tuple from left shelf
        resultTuple = getFreeSpaceFromShelfs(robo.leftShelf_);

        // check if left shelf has best space, with smallest gap
        if (std::get<1>(resultTuple) + weight < smallestDifference){
            bestCoords = std::get<0>(resultTuple);
            smallestDifference = std::get<1>(resultTuple) + weight;
        }

        // retrieve tuple from right shelf
        resultTuple = getFreeSpaceFromShelfs(robo.rightShelf_);

        // check if right shelf has best space, with smallest gap
        if (std::get<1>(resultTuple) + weight < smallestDifference){
            bestCoords = std::get<0>(resultTuple);
            smallestDifference = std::get<1>(resultTuple) + weight;
        }
    }
    return bestCoords;
}

Robo& StorageManager::FindRoboByContainerXCoord(double xCoord) {

    // needed for float comparison with error margin
    double epsilon = 0.01f;

    // calculate offset from shelf to robo
    double offset = (shelfDepth_ + shelfGap_) * 0.5;

    // iterate over vector and find robot
    for (auto &robo : robots_){
        // if absolute values are less than epsilon, coordinates are almost the same
        if (std::fabs((xCoord + offset) - robo.coordinates_.x_) < epsilon){
            return robo;
        }
        if (std::fabs((xCoord - offset) - robo.coordinates_.x_) < epsilon){
            return robo;
        }
    }
}

void StorageManager::AddToQueue(Container &container) {
    // find best place to store container
    auto bestPlace = this->FindOptimalSpace(container);

    std::cout << "\n\nPackage " << container << " will be stored at: \n" << bestPlace << " --------------------------- \n\n"; // TODO: debug only

    container.coordinates_ = bestPlace;

    // find robo corrisponding to x-coord of best place
    // TODO: robo store multithreading


    Robo &robo = this->FindRoboByContainerXCoord(bestPlace.x_);

    if (robo.coordinates_.x_ > container.coordinates_.x_) {
        robo.leftShelf_.Store(container);
    } else {
        robo.rightShelf_.Store(container);
    }
    robo.AddToActionQueue(FunctionStore, container);
}