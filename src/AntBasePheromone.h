//
// Created by esir on 21/05/23.
//

#ifndef TP_FOURMIS_ANTBASEPHEROMONE_H
#define TP_FOURMIS_ANTBASEPHEROMONE_H


#include "AntBase.h"
#include "Pheromone.h"

class AntBasePheromone : public AntBase {


public:
    AntBasePheromone(Environment *environment, Anthill *anthill, const Vector2<float> &direction, float speed = 1);

    /**
     * Ajoute une quantité de phéromone ou crée une phéromone à la position de la fourmi
     * @param quantity la quantité de phéromonèe à ajouter
     */
    void putPheromone(float quantity);

    /**
     * Chosit une phéromone à suivre parmi celles perçues
     * @return le pointeur de la phéromone à suivre ou nullptr s'il n'y a aucune phéromone perçue
     */
    Pheromone * choosePheromone() const;

};


#endif //TP_FOURMIS_ANTBASEPHEROMONE_H
