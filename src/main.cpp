#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    Container testContainer{Size{ 0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, Priority::high, 4}};

    StorageManager storageManager{};
    Coordinates bestCoords = storageManager.FindOptimalSpace(testContainer);
    std::cout << bestCoords << "\n";

    Loaderton::Instance().Save();
    return 0;
}