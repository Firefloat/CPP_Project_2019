//
// Created by Michael Variola on 19/11/2019.
//

#ifndef SRC_ROBO_H
#define SRC_ROBO_H

#include <queue>
#include "Shelf.h"
#include "Container.h"

class Robo {
private:
    Shelf left_;
    Shelf right_;

public:
    std::queue<Container> leftQueue_{};
    std::queue<Container> rightQueue_{};
    const float maxHorizontalVel_;
    const float maxVerticalVel_;
    const float horizontalVel_;
    const float verticalVel_;
    const float timeForDeploy_;

    Robo(const Shelf& left, const Shelf& right, float horizontalVel, float max_horizontal_vel, float verticalVel,
            float max_veritcal_vel, float timeForDeploy = 5) : left_(left), right_(right),
            maxHorizontalVel_(max_horizontal_vel), maxVerticalVel_(max_veritcal_vel), horizontalVel_(horizontalVel),
            verticalVel_(verticalVel), timeForDeploy_(timeForDeploy) { }

    Container GetContainer(int prio);
    void SetContainer(int prio, Container container);
};


#endif //SRC_ROBO_H
