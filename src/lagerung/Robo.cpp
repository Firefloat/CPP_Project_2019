#include "Robo.h"

Robo::Robo(Coordinates coordinates, Coordinates inputCoordinates, Coordinates outputCoordinates) : coordinates_(coordinates), inputCoordinates_(inputCoordinates), outputCoordinates_(outputCoordinates){
    verticalAcceleration_  = Loaderton::Instance().getJsonData()["robo"]["vertical_acceleration"];
    verticalVelocity_ = Loaderton::Instance().getJsonData()["robo"]["vertical_velocity"];
    horizontalAcceleration_ = Loaderton::Instance().getJsonData()["robo"]["horizontal_acceleration"];
    horizontalVelocity_ = Loaderton::Instance().getJsonData()["robo"]["horizontal_velocity"];
    timeStoreRestore_ = Loaderton::Instance().getJsonData()["robo"]["time_store_restore"];
    speedMultiplier_ = Loaderton::Instance().getJsonData()["speed_multiplier"];
    speedMultiplier_ = speedMultiplier_ <= 0 ? 1e-9 : speedMultiplier_; // Zero and negative numbers not allowed (dividing)!


    double xLeft, xRight, yShelf, zShelf;

    // calculate left and right x-coordinates of queues and shelfs
    xLeft = coordinates_.x_ - 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) -
            0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));
    xRight = coordinates_.x_ + 0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["gap"])) +
             0.5*(static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["depth"]));

    // calculate y and z coordinates of shelfs
    yShelf = static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["height_total"])/2;
    zShelf = static_cast<double>(Loaderton::Instance().getJsonData()["shelf"]["width"])/2;

    // initialize coordinates of shelfs
    leftShelf_ = Shelf{Coordinates{xLeft, yShelf, zShelf}};
    rightShelf_ = Shelf{Coordinates{xRight, yShelf, zShelf}};

    // coordinates of queue
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

void Robo::AddToActionQueue(FunctionType functionType, Container container) {
    isAvailable = false;
//    std::cout << "Here" << std::endl;
    auto p1 = std::make_pair(functionType, container);
//    std::cout << "Here" << std::endl;
    actionQueue_.push(std::make_pair(functionType, container)); // <-- Hier Micha
//    std::cout << thread_.joinable() << std::endl;
    if (!(thread_.joinable())){
        thread_ = std::thread(&Robo::CheckActionQueue, this);
    }
}

void Robo::CheckActionQueue() {
    if(actionQueue_.empty() && thread_.joinable()){
        isAvailable = true;
    } else{
        Do();
    }
}

void Robo::Do() {
    // TODO: use thread for detach?
    auto action = actionQueue_.front();
    std::future<bool> doAction;
    switch (action.first) {
        case FunctionStore:
            doAction = std::async(&Robo::Store, this, action.second);
            break;
        case FunctionRemove:
            doAction = std::async(&Robo::Remove, this, action.second);
            break;
    }
    if(doAction.get()){
        actionQueue_.pop();
        CheckActionQueue();
    }
}


bool Robo::Store(Container container) {
    // TODO: pass per reference
    std::cout << "Store Container in Robo at x = " << coordinates_.x_ << "\n";
    try {
        container.isStored = true;
        if (coordinates_.x_ > container.coordinates_.x_) {
            leftShelf_.Store(container);
        } else {
            rightShelf_.Store(container);
        }
        std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(inputCoordinates_)/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(container.coordinates_)/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_/speedMultiplier_));
        return true;
    }
    catch(...) {
        return false;
    }
}

bool Robo::Remove(Container container) {
    // TODO: pass per reference
    try {
        container.isStored = false;
        if (coordinates_.x_ < container.coordinates_.x_) {
            leftShelf_.Remove(container.coordinates_);
        } else {
            rightShelf_.Remove(container.coordinates_);
        }
        std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(container.coordinates_)/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(GetMovingTime(outputCoordinates_)/speedMultiplier_));
        std::this_thread::sleep_for(std::chrono::duration<double>(timeStoreRestore_/speedMultiplier_));
        return true;
    }
    catch(...){
        return false;
    }
}

