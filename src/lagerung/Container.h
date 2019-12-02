#ifndef SRC_CONTAINER_H
#define SRC_CONTAINER_H

#include "Size.h"
#include "Article.h"
#include "Coordinates.h"

class Container {

private:

public:
    Size size_;
    Article article_;
    Coordinates coordinates_;
    bool isStored = false;

    Container(Size size, Article article) : size_(size), article_(article) {};

};


#endif //SRC_CONTAINER_H