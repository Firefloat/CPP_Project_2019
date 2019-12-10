#include "Container.h"

float Container::GetPrioPos() {
    switch (article_.priority_){
        case Priority::high : return prio1Pos;
        case Priority::medium : return prio2Pos;
        case Priority::low : return prio3Pos;
    }
}

// initialize optimal positions for each priority
const float Container::prio1Pos = 0;
const float Container::prio2Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"])/2;
const float Container::prio3Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"]);;