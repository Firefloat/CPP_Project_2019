#include "setup/Loaderton.h"
#include <iostream>

int main() {
    Loaderton::Instance().Setup();
    std::cout << Loaderton::Instance().getJsonData();
    Loaderton::Instance().Save();
    return 0;
}