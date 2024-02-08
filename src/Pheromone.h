//
// Created by esir on 21/05/23.
//

#ifndef TP_FOURMIS_PHEROMONE_H
#define TP_FOURMIS_PHEROMONE_H


#include "Agent.h"

class Pheromone: public Agent {

private:
    float m_quantity;

public:
    Pheromone(Environment * environment, Vector2<float> position, float quantity);

    float getQuantity() const;

    void setQuantity(float quantity);

    /**
     * Ajoute une quantité de phéromone
     * @param quantity, la quantité à ajouter
     */
    void addQuantity(float quantity);

    virtual void update();
};


#endif //TP_FOURMIS_PHEROMONE_H
