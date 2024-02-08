//
// Created by esir on 23/05/23.
//

#ifndef TP_FOURMIS_ABSTRACTANTRULE_H
#define TP_FOURMIS_ABSTRACTANTRULE_H


#include "AbstractRule.h"
#include "AntBasePheromone.h"

class AbstractAntRule : public AbstractRule {
private:
    AntBasePheromone * antPointer;
public:
    AbstractAntRule(AntBasePheromone * ant);

    AntBasePheromone * getAnt() const ;

    ~AbstractAntRule();
};


#endif //TP_FOURMIS_ABSTRACTANTRULE_H
