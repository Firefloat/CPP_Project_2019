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
    Coordinates bestCoords{};
    // for debugging only
    int i{1};
    for (const auto& robo : robots_){
        std::cout << "-----------------------------------------------" << "\n";
        std::cout << "Shelf number " << i << " and " << i+1 << "\n";
        bestCoords = getFreeSpaceFromShelfs(robo.leftShelf_);
        std::cout << bestCoords << "\n";
        bestCoords = getFreeSpaceFromShelfs(robo.rightShelf_);
        std::cout << bestCoords << "\n";
        i+=2;
    }
}