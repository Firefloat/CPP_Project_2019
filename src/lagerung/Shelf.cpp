#include "Shelf.h"

Shelf::Shelf() {
    size_.width_ = Loaderton::Instance().getJsonData()["shelf"]["width"];
    size_.height_ = Loaderton::Instance().getJsonData()["shelf"]["height_total"];
    size_.depth_ = Loaderton::Instance().getJsonData()["shelf"]["depth"];
    boardHeight_ = Loaderton::Instance().getJsonData()["shelf"]["height_board"];

    boards_.reserve((int)(size_.height_ / boardHeight_));

    for(int index = 0; index < boards_.size(); index++) {
        boards_.emplace_back(Size(size_.width_, boardHeight_, size_.depth_), Coordinates((size_.width_ / 2), (index * boardHeight_ + boardHeight_ / 2), 0));
    }




}

void Shelf::Store(Container container) {
    // TODO
}

Container Shelf::Remove(Coordinates coordinates) {
    // TODO
}