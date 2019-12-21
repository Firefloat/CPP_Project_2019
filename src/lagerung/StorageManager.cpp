#include <iostream>
#include "StorageManager.h"

StorageManager::StorageManager() {
    int shelfAmount = Loaderton::Instance().getJsonData()["shelf"]["amount"];
    float conveyorBeltLength = Loaderton::Instance().getJsonData()["conveyor_belt"]["length_to_first_shelf"];
    float shelfDepth = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    float shelfGap = Loaderton::Instance().getJsonData()["shelf"]["gap"];

    int roboAmount = shelfAmount / 2;
    robots_.reserve(roboAmount);

    for(int index = 0; index < roboAmount; index++) {
        robots_.emplace_back(Coordinates(
                (conveyorBeltLength + ((float)index * (shelfDepth * 2 + shelfGap)) + (shelfDepth + (shelfGap / 2))),
                (shelfDepth / 2), 0));
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