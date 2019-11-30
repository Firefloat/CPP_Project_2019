#include <iostream>
#include "extern/json.hpp"
#include <fstream>

int main() {
    using json = nlohmann::json;
    std::ifstream myfile{"../data/setup.json"};
    json j = json::parse(myfile);
    std::cout << j["container"]["depth"] << std::endl;
    return 0;
}