//
// Created by esir on 09/05/23.
//

#include "AntBase.h"
#include "Timer.h"
#include "Renderer.h"

AntBase::AntBase(Environment * environment, Anthill * anthill, Vector2<float> direction, float speed): anthill(anthill), Agent(environment, anthill->getPosition(), 1.0), birthTime(0), life(MathUtils::random(1000,2500)), foodCarried(0), maxFoodCarried(5), direction(direction), speed(speed){}

bool AntBase::detectedHome() const {
    std::vector<Anthill*> perceivedHome = perceive<Anthill>(); // detecte les fourmilieres où se situe la fourmi
    if(std::count(perceivedHome.begin(), perceivedHome.end(), anthill)) { // si la fourmi est au niveau de la fourmilière
        return true;
    }
    return false;
}

Food * AntBase::detectedFood() const {
    std::vector<Food*> perceivedFood = perceive<Food>(); // On récupère les nourriture perçues
    if (!perceivedFood.empty()) return perceivedFood.front(); // On récupère le premier élément
    else return nullptr;
}

void AntBase::dropFood() {
    anthill->depositFood(foodCarried);
    foodCarried = 0 ;
}

void AntBase::collectFood(Food * target) {
    assert(foodCarried < maxFoodCarried); // On vérifie que la fourmi peut transporter plus de nourriture
    foodCarried += target->collectFood(maxFoodCarried - foodCarried);
    target = nullptr; // on réinitialise la cible
}

void AntBase::move() {
    translate(direction * speed * Timer::dt());
}

void AntBase::goBackHome(){
    setDirection(getPosition().direction(anthill->getPosition())); // On modifie la direction pour mettre celle allant à la fourmilière
}

void AntBase::turnAround(){
    setDirection(getDirection()*(Vector2<float>(-1,-1)));
}

void AntBase::turn(const float & angle) {
    setDirection(getDirection().rotate(angle));
}

void AntBase::goTo(Vector2<float> pos) {
    setDirection(getPosition().direction(pos));
}

Food * AntBase::chooseFood() const {
    std::vector<Food*> perceivedFood = perceive<Food>(direction, MathUtils::piDiv2, 3); // On récupère les instance de nourriture perçues par la fourmi
    if (!perceivedFood.empty()) return perceivedFood.front(); // On récupère le premier élément
    else return nullptr;
}

bool AntBase::isDead() {
    return (life <= 0);
}

Vector2<float> AntBase::getDirection() const {
    return direction;
}

void AntBase::setDirection (Vector2<float> d) {
    direction = d;
}

void AntBase::setFoodCarried(float f) {
    assert (f <= getMaxFoodCarried());
    foodCarried = f;
}

float AntBase::getFoodCarried() const {
    return foodCarried;
}

float AntBase::getMaxFoodCarried() const {
    return maxFoodCarried;
}

void AntBase::update() {
    life -= Timer::dt(); // On actualise le temps restant de vie de la fourmi
    if (isDead()) toDestroy();
    else {
        Renderer * instance = Renderer::getInstance(); // on récupère l'instance de renderer
        if (foodCarried == 0) { // point blanc si la fourmi ne transporte pas de nourriture
            Renderer::Color color(255,255,255,255);
            instance->drawCircle(getPosition(), getRadius(), color);
        } else { // point vert sinon
            Renderer::Color color(128,255,128,255);
            instance->drawCircle(getPosition(), getRadius(), color);
        }
    }
}

AntBase::~AntBase() = default;