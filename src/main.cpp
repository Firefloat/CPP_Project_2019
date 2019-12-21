#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    Container testContainer{Size{ 0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, Priority::medium, 4}};

    StorageManager storageManager{};
    storageManager.FindOptimalSpace(testContainer);

    Loaderton::Instance().Save();
    return 0;
}