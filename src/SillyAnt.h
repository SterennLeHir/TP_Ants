//
// Created by esir on 20/05/23.
//

#ifndef TP_FOURMIS_SILLYANT_H
#define TP_FOURMIS_SILLYANT_H


#include "AntBase.h"

class SillyAnt: public AntBase {

public:
    SillyAnt(Environment * environment, Anthill * anthill, float speed = 1);

    void update();
};


#endif //TP_FOURMIS_SILLYANT_H
