#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    //std::cout << Loaderton::Instance().getJsonData()["speed_multiplier"];

    StorageManager storageManager;
    std::cout << storageManager.robots_[0].GetMovingTime(Coordinates(160, 18, 0));

    Loaderton::Instance().Save();
    return 0;
}