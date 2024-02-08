//
// Created by esir on 09/05/23.
//

#include "Anthill.h"
#include "Renderer.h"
#include "AntWithRules.h"

Anthill::Anthill(Environment * environment, Vector2<float> position) : Agent(environment, position, 10.0), foodQuantity(0){}

void Anthill::depositFood(float quantity) {
    foodQuantity += quantity;
}

void Anthill::update() {
    Renderer * instance = Renderer::getInstance(); // on récupère l'instance de renderer
    Renderer::Color color(0,0,255,255);
    instance->drawCircle(getPosition(), getRadius(), color); // on représente la nourriture par un cercle
    if(foodQuantity > 100) { // On crée de nouvelles fourmis quand il y a assez de nourriture
        new AntWithRules(this->getEnvironment(), this);
    }
}

Anthill::~Anthill() = default;