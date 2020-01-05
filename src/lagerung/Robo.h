#ifndef SRC_ROBO_H
#define SRC_ROBO_H

#include <math.h>
#include <queue>
#include <future>
#include <chrono>
#include <thread>
#include "Queue.h"
#include "Coordinates.h"
#include "Shelf.h"
#include "Container.h"

enum FunctionType {
    FunctionStore,
    FunctionRemove
};

class Robo {

private:

public:
    volatile bool isAvailable{true};
    float queueLength;
    float verticalAcceleration_;
    float verticalVelocity_;
    float horizontalAcceleration_;
    float horizontalVelocity_;
    float timeStoreRestore_;
    float speedMultiplier_;
    Coordinates coordinates_;
    Coordinates inputCoordinates_;
    Coordinates outputCoordinates_;
    Queue queue_;
    Shelf leftShelf_;
    Shelf rightShelf_;
    std::queue<std::pair<FunctionType , Container>> actionQueue_;
    std::thread thread_;
    // TODO: Actionqueue
    Robo(Coordinates coordinates, Coordinates inputCoordinates, Coordinates outputCoordinates);
    double GetMovingTime(Coordinates targetCoordinates);
    void AddToActionQueue(FunctionType functionType, Container container);
    void CheckActionQueue();
    void Do();
    bool Store(Container container);
    bool Remove(Container container);
};


#endif //SRC_ROBO_H
