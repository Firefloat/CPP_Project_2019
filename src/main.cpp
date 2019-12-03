#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    std::cout << Loaderton::Instance().getJsonData();

    StorageManager storageManager;

    Loaderton::Instance().Save();
    return 0;
}