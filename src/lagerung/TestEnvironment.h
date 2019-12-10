#ifndef SRC_TESTENVIRONMENT_H
#define SRC_TESTENVIRONMENT_H

#include "Container.h"
#include "Size.h"
#include "Article.h"
#include "../setup/Loaderton.h"
#include "StorageManager.h"


class TestEnvironment {

private:

public:
    Size sizeC1_;
    Size sizeC2_;
    Size sizeC3_;

    Article article = Article(schrauben, 0, 0);;

    TestEnvironment();

    Container getNewContainer();
    Article removeAmountFromStorage();
    };


#endif //SRC_TESTENVIRONMENT_H
