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
    // TODO
}

Coordinates StorageManager::FindOptimalSpace(const Container& container) {

    auto getFreeSpaceFromShelfs = [&](Shelf shelf) { return shelf.GetFreeSpace(container); };
    std::tuple<Coordinates, int> resultTuple;
    double smallestDifference{MAXFLOAT};
    Coordinates bestCoords{};

    for (const auto& robo : robots_){
        // retrieve tuple from left shelf
        resultTuple = getFreeSpaceFromShelfs(robo.leftShelf_);

        // check if left shelf has best space, with smallest gap
        if (std::get<1>(resultTuple) < smallestDifference){
            bestCoords = std::get<0>(resultTuple);
            smallestDifference = std::get<1>(resultTuple);
        }

        // retrieve tuple from right shelf
        resultTuple = getFreeSpaceFromShelfs(robo.rightShelf_);

        // check if right shelf has best space, with smallest gap
        if (std::get<1>(resultTuple) < smallestDifference){
            bestCoords = std::get<0>(resultTuple);
            smallestDifference = std::get<1>(resultTuple);
        }
    }
    return bestCoords;
}

Robo& StorageManager::FindRoboByX(float xCoord) {
    // TODO: find right robo
}