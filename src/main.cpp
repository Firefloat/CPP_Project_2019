#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>
#include <random>

// TODO: remove random number generator -> for testing only
unsigned int rd{42};
std::mt19937 eng{rd};
std::uniform_int_distribution<> intDist{0, 3};
std::uniform_int_distribution<> quantityDist{0, 100};
// --------------------------------------------------------

Container GenerateContainer(){

    Container tempContainer{Size{0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, static_cast<Priority>(intDist(eng)),
                                    static_cast<unsigned int>(quantityDist(eng))}};

//    Container tempContainer{Size{0.6, 0.6, 0.6},
//                            Article{ArticleType::muttern, Priority::medium,
//                                    static_cast<unsigned int>(quantityDist(eng))}};
    return tempContainer;
}

void UserInteraction(StorageManager& storageManager){
    bool isInputLegit{false};

    Size sizeC1, sizeC2, sizeC3;

    sizeC1.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c1"];
    sizeC1.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC1.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC2.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c2"];
    sizeC2.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC2.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    sizeC3.width_ = (double) Loaderton::Instance().getJsonData()["container"]["width_c3"];
    sizeC3.height_ = (double) Loaderton::Instance().getJsonData()["container"]["height"];
    sizeC3.depth_ = (double) Loaderton::Instance().getJsonData()["container"]["depth"];

    bool notFinished = true;
    while(notFinished){

        short inputNumber;
        unsigned int amount;
        short prioSelection;
        Priority prio;
        Size choosenSize;
        Article article{};

        while(!isInputLegit) {
            std::cout << "Please select container size." << std::endl;
            std::cout << "(1) Container C1: Width = " << sizeC1.width_ << " | Hight = " << sizeC1.height_
                      << " | Depth = " << sizeC1.depth_ << std::endl;
            std::cout << "(2) Container C2: Width = " << sizeC2.width_ << " | Hight = " << sizeC2.height_
                      << " | Depth = " << sizeC2.depth_ << std::endl;
            std::cout << "(3) Container C3: Width = " << sizeC3.width_ << " | Hight = " << sizeC3.height_
                      << " | Depth = " << sizeC3.depth_ << std::endl;
            std::cout << "Container: ";
            std::cin >> inputNumber;
            switch (inputNumber) {
                case 1:
                    choosenSize = sizeC1;
                    isInputLegit = true;
                    break;
                case 2:
                    choosenSize = sizeC2;
                    isInputLegit = true;
                    break;
                case 3:
                    choosenSize = sizeC3;
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
            std::cin >> prioSelection;

            switch (prioSelection){
                case 1:
                    prio = Priority::low;
                    break;
                case 2:
                    prio = Priority::medium;
                    break;
                case 3:
                    prio = Priority::high;
                    break;
                default:
                    std::cout << "Wrong Input\n";
            }

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

        storageManager.AddToQueue(c );
        isInputLegit = false;
    }
}

void Simulation(StorageManager& storageManager){
    bool notFinished = true;
    while(notFinished){

        std::this_thread::sleep_for(std::chrono::seconds(3));

        // initialize test container
        Container testContainer = GenerateContainer();

        storageManager.AddToQueue(testContainer);

    }
}

int main() {
    Loaderton::Instance().Setup();

    // create storage manager
    StorageManager storageManager{};

    std::cout << "For simulation press 's'\n\n";
    std::cout << "For interaction press 'i'\n\n";

    int c = std::getchar();

//    int c = 's';

    if (c == 's' || c == 'S'){
        Simulation(storageManager);
    }
    if (c == 'i' || c == 'I'){
        UserInteraction(storageManager);
    }
    else{
        std::cout << "Wrong character abort!!!!!!";
        exit(13);
    }


    Loaderton::Instance().Save();
    return 0;
}