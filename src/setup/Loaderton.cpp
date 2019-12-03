//
// Created by Michael Variola on 26/11/2019.
//

#include "Loaderton.h"
#include <iostream>

void Loaderton::Load() {
    std::ifstream tempFile{saveFileName};
    // TODO
}

void Loaderton::Save() {
    // TODO
    std::ofstream tempFile(saveFileName);
    tempFile << jsonData.dump(intentSize);
}

void Loaderton::Setup() {
    std::ifstream tempFile{setupFileName};
    jsonData = json::parse(tempFile);
}