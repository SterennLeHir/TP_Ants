//
// Created by esir on 21/05/23.
//


#include "Timer.h"
#include "Renderer.h"
#include "Pheromone.h"

Pheromone::Pheromone(Environment *environment, const Vector2<float> position, float quantity) : Agent(environment, position, 1), m_quantity(quantity) {}

float Pheromone::getQuantity() const {
    return m_quantity;
}

void Pheromone::addQuantity(float quantity) {
    m_quantity += quantity;
}

void Pheromone::setQuantity(float quantity) {
    m_quantity = quantity;
}

void Pheromone::update() {
    setQuantity(getQuantity() - 0.01*getQuantity()*Timer::dt()); // Les phéromones s'évaporent
    if (getQuantity() < 0.01) toDestroy(); // La phéromone disparaît
    else {
        Renderer * instance = Renderer::getInstance(); // on récupère l'instance de renderer
        Renderer::Color color(0,128,128,std::min(getQuantity(), ((float) 255)));
        //Renderer::Color color(255,0,0, 255);
        instance->drawCircle(getPosition(), getRadius(), color);
    }
}