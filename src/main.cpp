#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();

    // create storage manager
    StorageManager storageManager{};
    bool notFinished = true;

    while(notFinished){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        // initialize test container
        Container testContainer{Size{ 0.6, 0.6, 0.6},
                                Article{ArticleType::muttern, Priority::high, 4}};

        storageManager.AddToQueue(testContainer);
        
        // find best place with async search
//        auto getBestCoords = std::async(std::launch::async, &StorageManager::FindOptimalSpace, std::ref(storageManager),
//                                        std::ref(testContainer));
//        auto bestCoords = getBestCoords.get();

//        auto thread = std::thread{&Robo::Store, &storageManager.FindRoboByContainerXCoord(bestCoords.x_), testContainer};
//        thread.detach();
    }

    // test if robots get found by shelf coordinates TODO: remove
//    std:: cout << storageManager.FindRoboByContainerXCoord(5.4).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(8.2).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(9).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(11.8).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(12.6).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(15.4).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(16.2).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(19).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(19.8).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(22.6).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(23.4).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(26.2).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(27).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(29.8).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(30.6).coordinates_;
//    std:: cout << storageManager.FindRoboByContainerXCoord(33.4).coordinates_;

    Loaderton::Instance().Save();
    return 0;
}