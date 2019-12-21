#include <iostream>
#include "StorageManager.h"

StorageManager::StorageManager() {
    int shelfAmount = Loaderton::Instance().getJsonData()["shelf"]["amount"];
    float conveyorBeltLength = Loaderton::Instance().getJsonData()["conveyor_belt"]["length_to_first_shelf"];
    float shelfDepth = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    float shelfGap = Loaderton::Instance().getJsonData()["shelf"]["gap"];
    float shelfHeight = Loaderton::Instance().getJsonData()["shelf"]["height_total"];

    int roboAmount = shelfAmount / 2;
    robots_.reserve(roboAmount);

    for(int index = 0; index < roboAmount; index++) {
        double roboPositionX = (conveyorBeltLength + ((float)index * (shelfDepth * 2 + shelfGap)) + (shelfDepth + (shelfGap / 2)));

        robots_.emplace_back(Coordinates(roboPositionX, (shelfHeight / 2), 0),
                             Coordinates(roboPositionX, (shelfHeight / 2), 0),
                             Coordinates(roboPositionX, 0, 0));
    }

}

void StorageManager::RemoveFromStorage(ArticleType articleType, int amount) {
    // TODO
}

Coordinates StorageManager::FindOptimalSpace(const Container& container) {

    // TODO multithreaded search
    auto getFreeSpaceFromShelfs = [&](Shelf shelf) { return shelf.GetFreeSpace(container); };
    auto freeSpace = std::vector<std::vector<std::vector<FreeSpace>>>{};

    for (const auto& robo : robots_){
        freeSpace.push_back(getFreeSpaceFromShelfs(robo.leftShelf_));
        freeSpace.push_back(getFreeSpaceFromShelfs(robo.rightShelf_));
    }
}