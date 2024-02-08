//
// Created by esir on 21/05/23.
//

#include <iostream>
#include "Ant.h"
#include "Timer.h"

Ant::Ant(Environment *environment, Anthill *anthill, float speed) : AntBasePheromone(environment, anthill, Vector2<float>::random(), speed) {
}

void Ant::update() {
    AntBase::update();
    if (getFoodCarried() > 0) { // La fourmi transporte de la nourriture
        putPheromone(100);
        if (detectedHome()) { // La fourmi se trouve sur la fourmilière
            dropFood();
            turnAround();
        } else {
            Pheromone * p = choosePheromone();
            if (p != nullptr) { // La fourmi perçoit une phéromone
                goTo(p->getPosition()); // La fourmi se dirige vers la phéromone choisie
            } else { // La fourmi ne perçoit pas de phéromone
                goBackHome(); // Elle rentre en ligne droite
            }
        }
        move();
    } else { // La fourmi n'a pas de nourriture
        Food * food = detectedFood();
        if (food != nullptr) { // Si la fourmi est sur une instance de nourriture
            collectFood(food);
        } else {
            Food * target = chooseFood();
            if (target != nullptr) { // Si la fourmi perçoit de la nourriture
                putPheromone(10);
                goTo(target->getPosition()); // Elle s'y dirige
            } else {
                Pheromone * pheromone = choosePheromone();
                if (pheromone != nullptr) { // Si la fourmi détecte une phéromone
                    goTo(pheromone->getPosition());
                } else {
                    float angle(MathUtils::random((-MathUtils::pi / 10) * Timer::dt(), (MathUtils::pi / 10) * Timer::dt()));
                    turn(angle); // On retourne la fourmi d'un certain angle
                }
            }
            move();
        }
    }
}
