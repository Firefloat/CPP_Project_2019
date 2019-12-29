#include "Robo.h"

Robo::Robo(Coordinates coordinates, Coordinates inputCoordinates, Coordinates outputCoordinates) : coordinates_(coordinates), inputCoordinates_(inputCoordinates), outputCoordinates_(outputCoordinates){
    verticalAcceleration_  = Loaderton::Instance().getJsonData()["robo"]["vertical_acceleration"];
    verticalVelocity_ = Loaderton::Instance().getJsonData()["robo"]["vertical_velocity"];
    horizontalAcceleration_ = Loaderton::Instance().getJsonData()["robo"]["horizontal_acceleration"];
    horizontalVelocity_ = Loaderton::Instance().getJsonData()["robo"]["horizontal_velocity"];
    timeStoreRestore_ = Loaderton::Instance().getJsonData()["robo"]["time_store_restore"];

    // Calculate left and right x-coordinates of queues
    double xLeft = coordinates_.x_ - 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) -
            0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));

    queue_.coordinates_ = Coordinates{xLeft, coordinates_.y_, coordinates_.z_};
}

double Robo::GetMovingTime(Coordinates targetCoordinates) {

    // Vertical
    double timeV = 0;
    double timeOfAccelerationV = verticalVelocity_ / verticalAcceleration_;
    double distanceOfAccelerationV = 0.5 * verticalAcceleration_ * (timeOfAccelerationV * timeOfAccelerationV);
    double distanceY = abs(coordinates_.y_ - targetCoordinates.y_);

    if ((distanceY - (2 * distanceOfAccelerationV)) > 0) {
        // Trapez
        double distanceOnMaxSpeed = distanceY - (2 * distanceOfAccelerationV);
        timeV = distanceOnMaxSpeed / verticalVelocity_;
        timeV = timeV + (2 * timeOfAccelerationV);
    } else {
        // Dreieck
        double remainingDistanceV = distanceY / 2;
        timeV = 2 * (sqrt(remainingDistanceV / (0.5 * verticalAcceleration_)));
    }

    // Horizontal
    double timeH = 0;
    double timeOfAccelerationH = horizontalVelocity_ / horizontalAcceleration_;
    double distanceOfAccelerationH = 0.5 * horizontalAcceleration_ * (timeOfAccelerationH * timeOfAccelerationH);
    double distanceZ = abs(coordinates_.z_ - targetCoordinates.x_);

    if ((distanceZ - (2 * distanceOfAccelerationH)) > 0) {
        // Trapez
        double distanceOnMaxSpeed = distanceZ - (2 * distanceOfAccelerationH);
        timeH = distanceOnMaxSpeed / horizontalVelocity_;
        timeH = timeH + (2 * timeOfAccelerationH);
    } else {
        // Dreieck
        double remainingDistanceH = distanceZ / 2;
        timeH = 2 * (sqrt(remainingDistanceH / (0.5 * horizontalAcceleration_)));
    }

    double totalTime = timeV > timeH ? timeV : timeH;

    return totalTime;
}

void Robo::AddToActionQueue(FunctionType functionType, Coordinates coordinates) {
    actionQueue_.push(std::make_pair(functionType, coordinates));
}

void Robo::Do() {

    auto action = actionQueue_.front();

    switch (action.first) {
        case FunctionStore:
            std::future<bool> doAction = std::async(&Robo::Store, this, action.second);


            break;
        case FunctionRemove:


            break;
    }
}


bool Robo::Store(Coordinates coordinates) {
    // TODO Storing - Remove from Queue
    std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(inputCoordinates_)));
    std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_));
    std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(coordinates)));
    std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_));
    return true;
}

bool Robo::Remove(Coordinates coordinates) {
    // TODO Remove from Shelf
    std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(coordinates)));
    std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_));
    std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(outputCoordinates_)));
    std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_));
    return true;
}

