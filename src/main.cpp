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

    // test if robots get found by shelf coordinates TODO: remove
    std:: cout << storageManager.FindRoboByContainerXCoord(5.4).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(8.2).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(9).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(11.8).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(12.6).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(15.4).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(16.2).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(19).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(19.8).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(22.6).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(23.4).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(26.2).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(27).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(29.8).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(30.6).coordinates_;
    std:: cout << storageManager.FindRoboByContainerXCoord(33.4).coordinates_;

    Loaderton::Instance().Save();
    return 0;
}