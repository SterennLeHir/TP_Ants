//
// Created by esir on 02/05/23.
//

#include "Food.h"
#include "Renderer.h"

Food::Food(Environment * environment, Vector2<float> position, float foodQuantity) : Agent(environment, position, MathUtils::circleRadius(foodQuantity)), foodQuantity(foodQuantity), foodCollected(false){}

float Food::getFoodQuantity() const {
    return foodQuantity;
}

float Food::collectFood(float quantity){
    foodCollected = true;
    if(quantity < getFoodQuantity()) {
        foodQuantity -= quantity;
        return quantity;
    } else {
        foodQuantity = 0;
        return quantity;
    }

}

void Food::update() {
    if(foodQuantity == 0) {
        this->setStatus(Agent::Status::destroy);
    } else if(Food::foodCollected){ // si de la nourriture a été récoltée
        this->setRadius(MathUtils::circleRadius(foodQuantity)); // on met à jour le rayon
        foodCollected = false; // on réinitialise pour le tour suivant
    }
    Renderer * instance = Renderer::getInstance(); // on récupère l'instance de renderer
    Renderer::Color color(154,235,38,255);
    instance->drawCircle(getPosition(), getRadius(), color); // on représente la nourriture par un cercle
}