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

Loaderton::json Loaderton::getJsonData() {
    if (jsonData_.empty()){
        // for static variable initializing
        Setup();
    }
    return jsonData_;
}

void Loaderton::Setup() {
    std::ifstream tempFile{setupFileName_};
    jsonData_ = json::parse(tempFile);
}