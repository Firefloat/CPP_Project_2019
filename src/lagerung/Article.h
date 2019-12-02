#ifndef SRC_ARTICLE_H
#define SRC_ARTICLE_H

#include "ArticleType.h"

struct Article {

private:

public:
    ArticleType type_;
    unsigned short priority_;
    unsigned int quantity_;

    Article(ArticleType type, unsigned short priority, unsigned int quantity) {
        type_ = type;
        priority_ = priority;
        quantity_ = quantity;
    }

};

#endif //SRC_ARTICLE_H
