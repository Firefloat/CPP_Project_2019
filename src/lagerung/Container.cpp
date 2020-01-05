#include "Container.h"

float Container::GetPrioPos() const {
    switch (article_.priority_){
        case Priority::high : return prio1Pos;
        case Priority::medium : return prio2Pos;
        case Priority::low : return prio3Pos;
    }
}

std::ostream& operator << (std::ostream& os, const Container& container){

    os << "ID: " << (size_t)&container << " with Article Type: " << container.article_.type_ << " and amount:  "
    << container.article_.quantity_;

    return os;
}

// initialize optimal positions for each priority
const float Container::prio1Pos = 0;
const float Container::prio2Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"])/2;
const float Container::prio3Pos = static_cast<float>(Loaderton::Instance().getJsonData()["shelf"]["width"]);

