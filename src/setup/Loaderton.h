//
// Created by Michael Variola on 26/11/2019.
//

#ifndef SRC_LOADERTON_H
#define SRC_LOADERTON_H

#include "../extern/json.hpp"
#include <fstream>
#include <string>

class Loaderton {
    using json = nlohmann::json;
private:
    const int8_t intentSize = 4;
    std::string setupFileName;
    std::string saveFileName;
    json jsonData;
    Loaderton() : setupFileName("../data/setup.json"), saveFileName("../data/save.json") {};

public:
    void Setup();
    void Save();
    void Load();
    json getJsonData() { return jsonData; }

    // delete copy constructor and assignment operator
    Loaderton(Loaderton &) = delete;
    void operator=(Loaderton &) = delete;

    // singleton pattern
    static Loaderton& Instance(){
        static Loaderton instance;
        return instance;
    };
};


#endif //SRC_LOADERTON_H
