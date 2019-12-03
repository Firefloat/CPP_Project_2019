#include "Board.h"

Board::Board(Size size, Coordinates coordinates) : size_(size), coordinates_(coordinates) {
    double containerSize = Loaderton::Instance().getJsonData()["container"]["width_c1"];
    storedContainers_.reserve((int)(size_.width_ / containerSize));
}

std::vector<FreeSpace> Board::GetFreeSpace() {
    return std::vector<FreeSpace>(); // TODO
}

void Board::Store(Container container) {
    // TODO
}

Container Board::Remove(Coordinates coordinates) {
    // TODO
}