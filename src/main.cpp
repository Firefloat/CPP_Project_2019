#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>
#include <random>

// TODO: remove random number generator -> for testing only
unsigned int rd{42};
std::mt19937 eng{rd};
std::uniform_int_distribution<> intDist{0, 3};
// --------------------------------------------------------

Container GenerateContainer(){

    Container tempContainer{Size{0.6, 0.6, 0.6},
                            Article{ArticleType::muttern, static_cast<Priority>(intDist(eng)), 6}};

    return tempContainer;
}

int main() {
    Loaderton::Instance().Setup();

    std::cout << intDist(eng) << "\n\n\n";
    // create storage manager
    StorageManager storageManager{};
    bool notFinished = true;

    while(notFinished){
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // initialize test container
        Container testContainer = GenerateContainer();

        storageManager.AddToQueue(testContainer);
    }
    Loaderton::Instance().Save();
    return 0;
}