//
// Created by esir on 09/05/23.
//

#ifndef TP_FOURMIS_ANTBASE_H
#define TP_FOURMIS_ANTBASE_H


#include "Agent.h"
#include "Anthill.h"
#include "Food.h"

class AntBase : public Agent {
private:
    float foodCarried; // la quantité de nourriture que la fourmi transporte
    float maxFoodCarried; // la quantité maximale que la fourmi peut transporter
    Anthill * anthill; //la fourmilière à laquelle appartient la fourmi
    float speed;
    Vector2<float> direction;
    float life; // en secondes
    float birthTime; // temps écoulé depuis le lancement de l'application au moment où on crée la fourmi

public:
    AntBase(Environment * environment, Anthill * anthill, Vector2<float> direction, float speed = 1);

    virtual void update();

    /**
     * Dépose la quantité de nourriture dans la fourmilière
     */
    void dropFood();
    /**
     * Détecte si la fourmi est au niveau de la fourmiliere
     */
    bool detectedHome() const;

    /**
    * Détecte si la fourmi est au niveau d'une instance de nourriture
    * @return l'instancce de nourriture détéctée, nullptr s'il n'y en a pas
    */
    Food * detectedFood() const;

    /**
     * Change la position de la fourmi en lui instaurant une direction aléatoire
     */
    void move();

    /**
     * Donne la direction de la fourmilière à la fourmi pour qu'elle puisse s'y diriger
     */
    void goBackHome();

    /**
     * Calcule l'opposé de la direction de déplacement, permet à la fourmi de faire demi-tour
     */
    void turnAround();

    /**
     * Modifie la direction de la fourmi pour qu'elle se dirige vers la cible voulue
     * @param pos, la position de la cible
     */
    void goTo(Vector2<float> pos);

    /**
     * Modifie la direction de la fourmi pour la faire tourner d'un certain angle
     * @param angle, l'angle de rotation
     */
    void turn(const float & angle);

    /**
     * Récolte de la nourriture
     * @param target, la cible où la fourmi va récolter de la nourriture
     */
    void collectFood(Food * target);

    /**
     * Trouve une instance de nourriture pour s'y diriger
     * @return le pointeur vers la nourriture, ou nullptdr s'il n'y aucune nourriture perçue
     */
   Food * chooseFood() const;

    /**
     * Indique si la fourmi a atteint sa durée de vie
     * @return true si la durée de vie est dépassée, false sinon
     */
    bool isDead();

    /**
     * @return le vecteur direction de la fourmi
     */
    Vector2<float> getDirection() const;

    /**
     *
     * @param direction, la nouvelle direction de la fourmi
     */
    void setDirection (Vector2<float> direction);

    /**
     *
     * @param f, la nouvelle quantité de nourriture transportée par la fourmi
     */
    void setFoodCarried(float f);

    /**
     * @return ma quantité transportée par la fourmi
     */
    float getFoodCarried() const ;

    /**
     * @return la quantité maximale qu'une fourmi peut transporter
     */
    float getMaxFoodCarried() const;

    /**
     * @return le pointeur de l'instance de nourriture ciblée
     */
    Food * getTarget() const;

    virtual ~AntBase();
};


#endif //TP_FOURMIS_ANTBASE_H
