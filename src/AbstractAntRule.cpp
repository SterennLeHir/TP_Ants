//
// Created by esir on 23/05/23.
//

#include "AbstractAntRule.h"


AbstractAntRule::AbstractAntRule(AntBasePheromone *ant) : antPointer(ant){}

AntBasePheromone * AbstractAntRule::getAnt() const {
    return antPointer;
}

AbstractAntRule::~AbstractAntRule() {
    if(getAnt()->isDead()) antPointer = nullptr;
}