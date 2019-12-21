#include "Robo.h"

Robo::Robo(Coordinates coordinates) : coordinates_(coordinates){

    double xLeft, xRight, yShelf, zShelf;

    // calculate left and right x-coordinates of queues and shelfs
    xLeft = coordinates_.x_ - 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) -
            0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));
    xRight = coordinates_.x_ + 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) +
             0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));

    // calculate y and z coordinates of shelfs
    yShelf = static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["height_total"])/2;
    zShelf = static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["width"])/2;

    // set coordinates of queues
    leftQueue_.coordinates_ = Coordinates{xLeft, coordinates_.y_, coordinates_.z_};
    rightQueue_.coordinates_ = Coordinates{xRight, coordinates_.y_, coordinates_.z_};

    // initialize coordinates of shelfs
    leftShelf_.coordinates_ = Coordinates{xLeft, yShelf, zShelf};
    rightShelf_.coordinates_ = Coordinates{xRight, yShelf, zShelf};
}