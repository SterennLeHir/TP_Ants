//
// Created by esir on 20/05/23.
//

#include <iostream>
#include "SillyAnt.h"
#include "Timer.h"

SillyAnt::SillyAnt(Environment * environment, Anthill * anthill, float speed): AntBase(environment, anthill, Vector2<float>::random(), speed){
}

void SillyAnt::update() {
    AntBase::update();
    if (getFoodCarried() > 0) { // La fourmi rentre à la fourmilière si elle a de la nourriture
        if (detectedHome()) {
            dropFood(); // La fourmi dépose la nourriture qu'elle transporte
        } else {
            goBackHome();
            move();
        }
    } else { // Si la fourmi n'a pas de nourriture
        Food *food = detectedFood();
        if (food != nullptr) { // Si la fourmi est au niveau d'une nourriture
            collectFood(food);
            goBackHome(); // Elle rentre à la fourmilière
        } else { // si elle ne se situe pas sur une nourriture
            Food *target = chooseFood(); // On récupère une cible perçue par la fourmi
            if (target != nullptr) {
                goTo(target->getPosition());
            } else { // S'il n'y a pas de nourriture perçue
                float angle(MathUtils::random((-MathUtils::pi / 10) * Timer::dt(), (MathUtils::pi / 10) * Timer::dt()));
                turn(angle); // On retourne la fourmi d'un certain angle
            }
        }
        move();
    }
}
