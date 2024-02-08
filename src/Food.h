//
// Created by esir on 02/05/23.
//

#ifndef TP_FOURMIS_FOOD_H
#define TP_FOURMIS_FOOD_H


#include "Agent.h"

class Food : public Agent {
private:
    bool foodCollected;
    float foodQuantity;
public:
    Food(Environment * environment, Vector2<float> position, float FoodQuantity) ;
    /**
     * Renvoie la quantité de nourriture restante
     * @return un float, la quantité de nourriture
     */
    float getFoodQuantity() const;

    /**
     *
     * @param quantity, la quantité de nourriture qu'on veut récolter
     * @return la quantité récupérée
     */
    float collectFood(float quantity);

    virtual void update();

};


#endif //TP_FOURMIS_FOOD_H
