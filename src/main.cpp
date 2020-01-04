#include "setup/Loaderton.h"
#include "lagerung/StorageManager.h"
#include <iostream>

Container GenerateContainer(){

    Container tempContainer{};



    return tempContainer;
}

int main() {
    Loaderton::Instance().Setup();

    // create storage manager
    StorageManager storageManager{};
    bool notFinished = true;

    while(notFinished){
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // initialize test container
        Container testContainer{Size{ 0.6, 0.6, 0.6},
                                Article{ArticleType::muttern, Priority::medium, 6}};

        storageManager.AddToQueue(testContainer);

    }
    Loaderton::Instance().Save();
    return 0;
}