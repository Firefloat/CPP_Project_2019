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

public:
    std::vector<Robo> robots_;
    // dict / list Article -> quantity is stored in Article
    std::queue<Container> toStore;


    StorageManager();

    void AddToQueue(Container container);
    void RemoveFromStorage(ArticleType articleType, int amount);

};


#endif //SRC_STORAGEMANAGER_H
