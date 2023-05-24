//
// Created by avida on 5/15/2023.
//

#include "TrainedNinja.hpp"

namespace ariel {

    TrainedNinja::TrainedNinja(const string &name, const Point &location) : Ninja(name, location) {
        this->setSpeed(12);
        this->setIsNinja(true);
        this->setHealth(120);
    }
};// ariel