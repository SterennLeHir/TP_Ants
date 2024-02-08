//
// Created by esir on 23/05/23.
//

#include "OrRule.h"

OrRule::OrRule(const std::vector<AbstractRule *> & rules) : rules(rules) {}

bool OrRule::condition() {
    for (AbstractRule * ar : rules) {
        if (ar->condition()) return true;
    }
    return false;
}

void OrRule::action() { // On effectue l'action de la première règle vraie
    if (condition()) {
        bool find = false;
        for (AbstractRule * ar : rules) {
            if (find) break;
            if (ar->condition()) {
                ar->action();
                find = true;
            }
        }
    }
}