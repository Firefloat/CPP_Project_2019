#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>
#include "lagerung/TestEnvironment.h"

int main() {
    Loaderton::Instance().Setup();
    std::cout << Loaderton::Instance().getJsonData();

    StorageManager storageManager;
    TestEnvironment environment;
    Article c = environment.removeAmountFromStorage();

    Loaderton::Instance().Save();
    return 0;
}