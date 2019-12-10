#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>
#include "lagerung/TestEnvironment.h"

int main() {
    Loaderton::Instance().Setup();
    //std::cout << Loaderton::Instance().getJsonData();

    StorageManager storageManager;
    TestEnvironment environment;
    Article a = environment.removeAmountFromStorage();
    Container c = environment.getNewContainer();

    Loaderton::Instance().Save();
    return 0;
}