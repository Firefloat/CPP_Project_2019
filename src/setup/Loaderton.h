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
    const int8_t intentSize_ = 4;
    std::string setupFileName_;
    std::string saveFileName_;
    json jsonData_;
    Loaderton() : setupFileName_("../data/setup.json"), saveFileName_("../data/save.json") {};

public:
    void Setup();
    void Save();
    void Load();
    json getJsonData() { return jsonData_; }

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
