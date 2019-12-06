#include "Robo.h"

Robo::Robo(Coordinates coordinates) : coordinates_(coordinates){

    double xLeft, xRight;

    // Calculate left and right x-coordinates of queues
    xLeft = coordinates_.x_ - 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) -
            0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));
    xRight = coordinates_.x_ + 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) +
             0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));

    leftQueue_.coordinates_ = Coordinates{xLeft, coordinates_.y_, coordinates_.z_};
    rightQueue_.coordinates_ = Coordinates{xRight, coordinates_.y_, coordinates_.z_};
}