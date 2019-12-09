#include "TestEnvironment.h"
#include <iostream>


TestEnvironment::TestEnvironment() {

    sizeC1_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c1"];
    sizeC1_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC1_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC2_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c2"];
    sizeC2_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC2_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC3_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c3"];
    sizeC3_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC3_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

}

Container TestEnvironment::getNewContainer() {
    short inputNumber;
    short amount;
    short prio;
    Size choosenSize;
    bool isInputLegit = false;

        while(!isInputLegit) {
            std::cout << "Please select container size." << std::endl;
            std::cout << "(1) Container C1: Width = " << sizeC1_.width_ << " | Hight = " << sizeC1_.height_
                      << " | Depth = " << sizeC1_.depth_ << std::endl;
            std::cout << "(2) Container C2: Width = " << sizeC2_.width_ << " | Hight = " << sizeC2_.height_
                      << " | Depth = " << sizeC2_.depth_ << std::endl;
            std::cout << "(3) Container C3: Width = " << sizeC3_.width_ << " | Hight = " << sizeC3_.height_
                      << " | Depth = " << sizeC3_.depth_ << std::endl;

            std::cin >> inputNumber;
            switch (inputNumber) {
                case 1:
                    choosenSize = sizeC1_;
                    isInputLegit = true;
                    break;
                case 2:
                    choosenSize = sizeC2_;
                    isInputLegit = true;
                    break;
                case 3:
                    choosenSize = sizeC3_;
                    isInputLegit = true;
                    break;
                default:
                    std::cout << "Wrong Input\n";
            }
        }
        isInputLegit = false;
        while (!isInputLegit){
            std::cout << "Please select article type and insert amount and priority." << std::endl;
            std::cout << "Article Types: (1)" << schrauben << " | (2)" << muttern << std::endl;

            std::cout << "Article: ";
            std::cin >> inputNumber;

            std::cout << "Amount: ";
            std::cin >> amount;

            std::cout << "Priority: ";
            std::cin >> prio;

            switch (inputNumber) {
                case 1:
                    article.type_ = schrauben;
                    article.quantity_ = amount;
                    article.priority_ = prio;
                    isInputLegit = true;
                    break;
                case 2:
                    article.type_ = muttern;
                    article.quantity_ = amount;
                    article.priority_ = prio;
                    isInputLegit = true;
                    break;
                default:
                    std::cout << "Wrong Input\n";
            }
        }

    Container c = Container(choosenSize, article);

    return c ;
}

Article TestEnvironment::removeAmountFromStorage() {
    bool isInputLegit = false;
    int inputNumber;
    int amount;

    while (!isInputLegit){
        std::cout << "Type in article type and amount to remove. Possible articles: (1)" << schrauben << " | (2)" << muttern << std::endl;
        std::cout << "Article: ";
        std::cin >> inputNumber;

        std::cout << "Amount: ";
        std::cin >> amount;

        switch (inputNumber) {
            case 1:
                article.type_ = schrauben;
                article.quantity_ = amount;
                isInputLegit = true;
                break;
            case 2:
                article.type_ = muttern;
                article.quantity_ = amount;
                isInputLegit = true;
                break;
            default:
                std::cout << "Wrong Input\n";
        }
    }
    return article;
}

/*
 * #include "TestEnvironment.h"
#include <iostream>


TestEnvironment::TestEnvironment() {

    sizeC1_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c1"];
    sizeC1_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC1_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC2_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c2"];
    sizeC2_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC2_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC3_.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c3"];
    sizeC3_.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC3_.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

}

void TestEnvironment::getNewContainer() {
    char inputToDo;
    short inputNumber;
    short amount;
    short prio;
    Size choosenSize;
    bool isInputLegit = false;
    bool isGoingOn = true;

    while (isGoingOn) {
        std::cout << "Add container? (y/n)" << std::endl;
        std::cin >> inputToDo;

        if (inputToDo == 'y' || inputToDo == 'Y') {
            while (!isInputLegit) {
                std::cout << "Please select container size." << std::endl;
                std::cout << "(1) Container C1: Width = " << sizeC1_.width_ << " | Hight = " << sizeC1_.height_
                          << " | Depth = " << sizeC1_.depth_ << std::endl;
                std::cout << "(2) Container C2: Width = " << sizeC2_.width_ << " | Hight = " << sizeC2_.height_
                          << " | Depth = " << sizeC2_.depth_ << std::endl;
                std::cout << "(3) Container C3: Width = " << sizeC3_.width_ << " | Hight = " << sizeC3_.height_
                          << " | Depth = " << sizeC3_.depth_ << std::endl;

                std::cin >> inputNumber;
                switch (inputNumber) {
                    case 1:
                        choosenSize = sizeC1_;
                        isInputLegit = true;
                        break;
                    case 2:
                        choosenSize = sizeC2_;
                        isInputLegit = true;
                        break;
                    case 3:
                        choosenSize = sizeC3_;
                        isInputLegit = true;
                        break;
                    default:
                        std::cout << "Wrong Input\n";
                }
            }
            isInputLegit = false;
            while (!isInputLegit) {
                std::cout << "Please select article type and insert amount and priority." << std::endl;
                std::cout << "Article Types: (1)" << schrauben << " | (2)" << muttern << std::endl;

                std::cout << "Article: ";
                std::cin >> inputNumber;

                std::cout << "Amount: ";
                std::cin >> amount;

                std::cout << "Priority: ";
                std::cin >> prio;

                switch (inputNumber) {
                    case 1:
                        article.type_ = schrauben;
                        article.quantity_ = amount;
                        article.priority_ = prio;
                        isInputLegit = true;
                        break;
                    case 2:
                        article.type_ = muttern;
                        article.quantity_ = amount;
                        article.priority_ = prio;
                        isInputLegit = true;
                        break;
                    default:
                        std::cout << "Wrong Input\n";
                }
            }
            StorageManager storageManager;
            storageManager.AddToQueue(Container(choosenSize, article));
        }else{
            isGoingOn = false;
        }
    }
}


*/
