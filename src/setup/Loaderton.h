//
// Created by Michael Variola on 26/11/2019.
//

#ifndef SRC_LOADERTON_H
#define SRC_LOADERTON_H

#include "../extern/json.hpp"
#include <fstream>
#include <string>

class Loaderton {
private:
    std::string setupFileName;
    std::string saveFileName;
    Loaderton() : setupFileName("../data/setup.json"), saveFileName("../data/save.json") {};

public:
    void Setup();
    void Save();
    void Load();
    Loaderton(Loaderton &) = delete;
    void operator=(Loaderton &) = delete;
    static Loaderton& Instance(){
        static Loaderton instance;
        return instance;
    };
};


#endif //SRC_LOADERTON_H
