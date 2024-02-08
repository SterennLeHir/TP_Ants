//
// Created by esir on 21/05/23.
//

#include "AntBasePheromone.h"

AntBasePheromone::AntBasePheromone(Environment *environment, Anthill * anthill, const Vector2<float> &direction, float speed) : AntBase(environment, anthill, direction, speed) {}

void AntBasePheromone::putPheromone(float quantity) {
    std::vector<Pheromone*> perceivedPheromone = perceive<Pheromone>(); // On detecte les pheromones déjà présentes s'il y en a
    if (perceivedPheromone.empty()) { // S'il n'y en a pas
        Pheromone * pheromone = new Pheromone(getEnvironment(), getPosition(), quantity); // La fourmi crée une phéromone
    } else {
        for (Pheromone * p : perceivedPheromone) {
            p->addQuantity(quantity); // On ajoute une quantité de phéromone
        }
    }
}

Pheromone * AntBasePheromone::choosePheromone() const {
    std::vector<Pheromone*> perceivedPheromone = perceive<Pheromone>(getDirection(), MathUtils::piDiv2, 8); // On récupère les phéromones perçues
    if (perceivedPheromone.empty()) return nullptr;
    else {
        std::vector<float> quantities;
        for(Pheromone * p : perceivedPheromone) {
            quantities.push_back(p->getQuantity()); // On crée un tableau avec les quantités des phéromones
        }
        std::reverse(quantities.begin(), quantities.end()); // On inverse le tableau pour que l'ordre des quantités corresponde à celui des phéromones
        int chosenIndex = MathUtils::randomChoose(quantities);  // On récupère l'indice de la quantité choisie
        return perceivedPheromone[chosenIndex];
    }
}
