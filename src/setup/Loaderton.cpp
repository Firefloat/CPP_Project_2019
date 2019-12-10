//
// Created by Michael Variola on 26/11/2019.
//

#include "Loaderton.h"
#include <iostream>

void Loaderton::Load() {
    std::ifstream tempFile{saveFileName_};
    // TODO
}

void Loaderton::Save() {
    // TODO
    std::ofstream tempFile(saveFileName_);
    tempFile << jsonData_.dump(intentSize_);
}

void Loaderton::Setup() {
    std::ifstream tempFile{setupFileName_};
    jsonData_ = json::parse(tempFile);
    prio1Pos = 0;
    prio3Pos = jsonData_["shelf"]["width"];
    prio2Pos = prio3Pos/2;
}