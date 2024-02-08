//
// Created by esir on 27/05/23.
//

#include "AntWithRules.h"
#include "Timer.h"

// Méthodes de la classe AntWithRules
AntWithRules::AntWithRules(Environment *environment, Anthill *anthill, float speed) : AntBasePheromone(environment, anthill, Vector2<float>::random(), speed), rules(new OrRule(std::vector<AbstractRule *> {new OnFood(this), new PerceivedFood(this), new PerceivedPheromone(this), new NoFoodNoPheromone(this), new FoodAtHome(this), new FoodNotAtHome(this)})){}

void AntWithRules::update() {
    AntBase::update();
    rules->action();
}

AntWithRules::~AntWithRules() {
    delete rules;
}

//// Méthodes des classes internes correspondant aux règles ////
// La fourmi se situe sur de la nourriture et n'en transporte pas
AntWithRules::OnFood::OnFood(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::OnFood::condition() {
    return (getAnt()->getFoodCarried() == 0) && !(getAnt()->perceive<Food>().empty());
}

void AntWithRules::OnFood::action() {
    std::vector<Food*> food = getAnt()->perceive<Food>();
    getAnt()->collectFood(food.front());
    getAnt()->putPheromone(100);
}

// La fourmi perçoit de la nourriture et n'en transporte pas
AntWithRules::PerceivedFood::PerceivedFood(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::PerceivedFood::condition() {
    return (getAnt()->getFoodCarried() == 0) && (getAnt()->chooseFood() != nullptr);
}

void AntWithRules::PerceivedFood::action() {
    Food * target = getAnt()->chooseFood();
    getAnt()->goTo(target->getPosition());
    getAnt()->move();
    getAnt()->putPheromone(10);
}

// La fourmi perçoit des phéromones et ne transporte pas de nourritures
AntWithRules::PerceivedPheromone::PerceivedPheromone(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::PerceivedPheromone::condition() {
    return (getAnt()->getFoodCarried() == 0) && (getAnt()->choosePheromone() != nullptr);
}

void AntWithRules::PerceivedPheromone::action() {
    Pheromone * target = getAnt()->choosePheromone();
    getAnt()->goTo(target->getPosition());
    getAnt()->move();
}

// La fourmi ne perçoit ni nourriture ni phéromone et ne transporte pas de nourriture
AntWithRules::NoFoodNoPheromone::NoFoodNoPheromone(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::NoFoodNoPheromone::condition() {
    return (getAnt()->getFoodCarried() == 0) && (getAnt()->choosePheromone() == nullptr) && (getAnt()->chooseFood() == nullptr);
}

void AntWithRules::NoFoodNoPheromone::action() {
    float angle(MathUtils::random((-MathUtils::pi / 10) * Timer::dt(), (MathUtils::pi / 10) * Timer::dt()));
    getAnt()->turn(angle); // On retourne la fourmi d'un certain angle
    getAnt()->move();
}

// La fourmi se situe sur la fourmilère avec de la nourriture
AntWithRules::FoodAtHome::FoodAtHome(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::FoodAtHome::condition() {
    return (getAnt()->getFoodCarried() > 0) && (getAnt()->detectedHome());
}

void AntWithRules::FoodAtHome::action() {
    getAnt()->putPheromone(100);
    getAnt()->dropFood();
    getAnt()->turnAround();
    getAnt()->move();
}

// La fourmi ne se situe pas sur la forumilère et transporte de la nourriture
AntWithRules::FoodNotAtHome::FoodNotAtHome(AntBasePheromone *ant) : AbstractAntRule(ant){}
bool AntWithRules::FoodNotAtHome::condition() {
    return (getAnt()->getFoodCarried() > 0) && !(getAnt()->detectedHome());
}

void AntWithRules::FoodNotAtHome::action() {
    getAnt()->putPheromone(100);
    getAnt()->goBackHome(); // La fourmi se tourne vers le nid;
    Pheromone * p = getAnt()->choosePheromone();
    if (p != nullptr) { // La fourmi perçoit une phéromone
        getAnt()->goTo(p->getPosition()); // La fourmi se dirige vers la phéromone choisie
    } else { // La fourmi ne perçoit pas de phéromones
        getAnt()->goBackHome(); // Elle rentre en ligne droite
    }
    getAnt()->move();
}