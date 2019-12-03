#include "StorageManager.h"

StorageManager::StorageManager() {
    int shelfAmount = Loaderton::Instance().getJsonData()["shelf"]["amount"];
    float conveyorBeltLength = Loaderton::Instance().getJsonData()["conveyor_belt"]["length_to_first_shelf"];
    float shelfDepth = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    float shelfGap = Loaderton::Instance().getJsonData()["shelf"]["gap"];


    robots_.reserve((int)(shelfAmount / 2));

    for(int index = 0; index < (int)robots_.size(); index++) {
        robots_.emplace_back(Coordinates((conveyorBeltLength + ((float)index * (shelfDepth * 2 + shelfGap)) + (shelfDepth + (shelfGap / 2))), (shelfDepth / 2), 0));
    }

}

void StorageManager::AddToQueue(Container container) {
    // TODO
}

void StorageManager::RemoveFromStorage(ArticleType articleType, int amount) {
    // TODO
}