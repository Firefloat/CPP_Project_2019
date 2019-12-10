#include "Shelf.h"

Shelf::Shelf() {
    size_.width_ = Loaderton::Instance().getJsonData()["shelf"]["width"];
    size_.height_ = Loaderton::Instance().getJsonData()["shelf"]["height_total"];
    size_.depth_ = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    boardHeight_ = Loaderton::Instance().getJsonData()["shelf"]["height_board"];

    double boardCount = (int)(size_.height_ / boardHeight_);
    boards_.reserve(boardCount);

    for(int index = 0; index < boardCount; index++) {
        boards_.emplace_back(Size(size_.width_, boardHeight_, size_.depth_), Coordinates((size_.width_ / 2), (index * boardHeight_ + boardHeight_ / 2), 0));
    }


}

std::vector<std::vector<FreeSpace>> Shelf::GetFreeSpace(const Container& container){
    // TODO get best space with priority
    auto resultVector = std::vector<std::vector<FreeSpace>>{};
    for (auto board : boards_){
        resultVector.push_back(board.GetFreeSpace(container));
    }
    return resultVector;
}

Container Shelf::Remove(Coordinates coordinates) {
    // TODO
}