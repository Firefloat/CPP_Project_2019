#ifndef SRC_ARTICLE_H
#define SRC_ARTICLE_H

#include "ArticleType.h"

struct Article {

private:

public:
    ArticleType type_;
    Priority priority_;
    unsigned int quantity_;

    Article(ArticleType type, Priority priority, unsigned int quantity) : type_(type), priority_(priority), quantity_(quantity) {

    }
    Article(){};

};

#endif //SRC_ARTICLE_H
