#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();

    // initialize test container
    Container testContainer{Size{ 0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, Priority::high, 4}};

    // create storage manager
    StorageManager storageManager{};

    // find best place with async search
    auto getBestCoords = std::async(std::launch::async, &StorageManager::FindOptimalSpace, std::ref(storageManager),
            std::ref(testContainer));
    auto bestCoords = getBestCoords.get();
    
    // printing
    std::cout << "Best Place found:" << "\n";
    std::cout << bestCoords << "\n";

    Loaderton::Instance().Save();
    return 0;
}