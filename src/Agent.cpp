//
// Created by esir on 19/04/23.
//
#include "Agent.h"

std::set<Agent*> Agent::agents;
Agent::Agent(Environment * environment, Vector2<float> position, float radius): Environment::LocalizedEntity(environment, position, radius), state(running) {
    Agent::agents.insert(this); // on ajoute l'agent qu'on vient de créer dans l'ensemble des agents
}

void Agent::update() {}

Agent::Status Agent::getStatus() const {
    return state;
}
void Agent::setStatus(Agent::Status s) {
    state = s;
}

void Agent::toDestroy(){
    setStatus(destroy);
}

void Agent::simulate() {
    std::set<Agent *>::iterator it = Agent::agents.begin();
    while (it != Agent::agents.end()) { // on parcourt tous les agents qui sont dans l'ensemble
        if ((*it)->getStatus() == running) { // it renvoie un pointeur vers un élément de l'ensemble, c'est à dire vers un pointeur sur un agent
            (*it)->update();
            ++it;
        } else {
            Agent * toDelete = *it;
            it = Agent::agents.erase(it); // on supprime l'agent du tableau
            delete toDelete; // on détruit l'agent
        }
    }
}

void Agent::finalize() {
    std::set<Agent*>::iterator it = Agent::agents.begin();
    while(it != Agent::agents.end()){ // on parcourt tous les agents qui sont dans l'ensemble
        Agent * toDelete = *it;
        Agent::agents.erase(it); // on supprime l'agent du tableau
        delete toDelete; // on détruit l'agent
    }
    ++it;
}

Agent::~Agent() = default;
