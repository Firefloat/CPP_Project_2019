#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    Priority p = Priority::low;
    std::cout << Container::prio2Pos;

    StorageManager storageManager{};

    Loaderton::Instance().Save();
    return 0;
}