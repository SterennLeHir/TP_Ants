//
// Created by esir on 19/04/23.
//

#ifndef TP_FOURMIS_AGENT_H
#define TP_FOURMIS_AGENT_H
#include "Environment.h"
#include "Vector2.h"
class Agent : public Environment::LocalizedEntity {

private :
    static std::set<Agent*> agents ; // ensemble de pointeurs sur tous les agents déjà créés
protected:
    typedef enum { // running signifie que l'agent est en cours d'execution et destroy qu'il peut être détruit
        running, destroy
    } Status;
    Status state;
public:
    Agent(Environment * environment, Vector2<float> position, float radius = defaultRadius());

    /**
     * Met à jour les informations sur l'agent (durée de vie restante, déplacement à effectuer, changement d'état...)
     */
    virtual void update();

    /**
     * @return le status (state) de l'agent
     */
    Status getStatus() const;
    /**
     * Modifie le statut de l'agent
     * @param s le nouveau statut de l'agent
     */
    void setStatus(Status s);

    /*
     * Change  le statut en destroy
     */
    void toDestroy();

    /**
     * Parcourt tous les agents créés et met à jour la liste
     * Si un agent est en cours d'exécution, on appelle update(), sinon on le détruit
     */
    static void simulate();

    /**
     * Détruis tous les agents à la fin de la simulation
     */
    static void finalize();

    virtual ~Agent();
};


#endif //TP_FOURMIS_AGENT_H
