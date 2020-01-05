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

//    Container tempContainer{Size{0.6, 0.6, 0.6},
//                            Article{ArticleType::muttern, static_cast<Priority>(intDist(eng)),
//                                    static_cast<unsigned int>(quantityDist(eng))}};

    Container tempContainer{Size{0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, Priority::medium,
                                    static_cast<unsigned int>(quantityDist(eng))}};
    return tempContainer;
}

void UserInteraction(StorageManager& storageManager){
    bool notFinished = true;
    while(notFinished){


        // initialize test container
        Container testContainer = GenerateContainer();

        storageManager.AddToQueue(testContainer);

        std::cout << "Press any key to continue \n";
        std::getchar();
    }
}

void Simulation(StorageManager& storageManager){
    bool notFinished = true;
    while(notFinished){


        // initialize test container
        Container testContainer = GenerateContainer();

        storageManager.AddToQueue(testContainer);

        std::cout << "Press any key to continue \n";
        std::getchar();
    }
}

int main() {
    Loaderton::Instance().Setup();

    // create storage manager
    StorageManager storageManager{};

    std::cout << "For simulation press 's'\n\n";
    std::cout << "For interaction press 'i'\n\n";

//    int c = std::getchar();

    int c = 's';

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