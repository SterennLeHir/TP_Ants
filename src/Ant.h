//
// Created by esir on 21/05/23.
//

#ifndef TP_FOURMIS_ANT_H
#define TP_FOURMIS_ANT_H


#include "AntBasePheromone.h"

class Ant: public AntBasePheromone {
public:

    Ant(Environment *environment, Anthill *anthill, float speed = 1);

    void update();

};


#endif //TP_FOURMIS_ANT_H
