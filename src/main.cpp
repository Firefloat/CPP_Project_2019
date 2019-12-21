#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();

    // initialize test container
    Container testContainer{Size{ 0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, Priority::high, 4}};

    // create storage manager and find best place for test container
    StorageManager storageManager{};
    Coordinates bestCoords = storageManager.FindOptimalSpace(testContainer);

    // printing
    std::cout << "Best Place found:" << "\n";
    std::cout << bestCoords << "\n";

    Loaderton::Instance().Save();
    return 0;
}