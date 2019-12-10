#include "Container.h"

float Container::GetPrioPos(enum Priority prio) {
    switch (prio){
        case Priority::high : return 0;
    }
}

const float Container::prio1Pos = 0;
const float Container::prio2Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"])/2;
const float Container::prio3Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"]);;