//
// Created by esir on 27/05/23.
//

#include "AntBasePheromone.h"
#include "AbstractAntRule.h"
#include "OrRule.h"

#ifndef TP_FOURMIS_ANTWITHRULES_H
#define TP_FOURMIS_ANTWITHRULES_

class AntWithRules : public AntBasePheromone {

private:
    OrRule * rules;
public:

    AntWithRules(Environment * environment, Anthill * anthill, float speed = 1);

    void update() override;

    ~AntWithRules() override;

    //Déclaration des classes internes correspondant aux règles
    class OnFood : public AbstractAntRule { // La fourmi se situe sur de la nourriture et n'en transporte pas
    public:
        OnFood(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };

    class PerceivedFood : public AbstractAntRule { // La fourmi perçoit de la nourriture et n'en transporte pas
    public:
        PerceivedFood(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };

    class PerceivedPheromone: public AbstractAntRule { // La fourmi perçoit des phéromones et ne transporte pas de nourritures
    public:
        PerceivedPheromone(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };

    class NoFoodNoPheromone: public AbstractAntRule { // La fourmi ne perçoit ni nourriture ni phéromone et ne transporte pas de nourriture
    public:
        NoFoodNoPheromone(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };

    class FoodAtHome : public AbstractAntRule { // La fourmi se situe sur la fourmilère avec de la nourriture
    public:
        FoodAtHome(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };

    class FoodNotAtHome : public AbstractAntRule { // La fourmi ne se situe pas sur la forumilère et transporte de la nourriture
    public:
        FoodNotAtHome(AntBasePheromone * ant);

        bool condition() override ;

        void action() override;

    };
};


#endif //TP_FOURMIS_ANTWITHRULES_H
