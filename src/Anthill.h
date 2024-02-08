//
// Created by esir on 09/05/23.
//

#ifndef TP_FOURMIS_ANTHILL_H
#define TP_FOURMIS_ANTHILL_H
#include "Agent.h"

class Anthill : public Agent {
private:
    float foodQuantity;

public:
    Anthill(Environment * environment, Vector2<float> position);

    /**
     * Permet aux fourmis de déposer de la nourriture récoltée
     * @param quantity la quantité de nourriture déposée
     */
    void depositFood(float quantity);

    virtual void update();

    virtual ~Anthill();
};


#endif //TP_FOURMIS_ANTHILL_H
