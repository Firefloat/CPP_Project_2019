#ifndef SRC_CONTAINER_H
#define SRC_CONTAINER_H

#include "Size.h"
#include "Article.h"
#include "Coordinates.h"
#include "../setup/Loaderton.h"

class Container {

private:

public:
    static const float prio1Pos, prio2Pos, prio3Pos;
    Size size_;
    Article article_;
    Coordinates coordinates_;
    bool isStored = false;
    float GetPrioPos(Priority prio);

    Container(Size size, Article article) : size_(size), article_(article) {};

};



#endif //SRC_CONTAINER_H