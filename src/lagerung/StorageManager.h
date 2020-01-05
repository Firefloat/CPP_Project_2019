#ifndef SRC_STORAGEMANAGER_H
#define SRC_STORAGEMANAGER_H

#include <queue>
#include <vector>
#include "../setup/Loaderton.h"
#include "Robo.h"
#include "ArticleType.h"
#include "Article.h"
#include "Container.h"

class StorageManager {

private:
    int shelfAmount_;
    float conveyorBeltLength_, shelfDepth_, shelfGap_, shelfHeight_;

public:
    std::vector<Robo> robots_;
    StorageManager();
    Coordinates FindOptimalSpace(const Container& container);
    void AddToQueue(const Container &container);
    void RemoveFromStorage(ArticleType articleType, int amount);

    // for debugging only TODO: move to private
    Robo& FindRoboByContainerXCoord(double xCoord);
};


#endif //SRC_STORAGEMANAGER_H
