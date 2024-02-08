//
// Created by esir on 23/05/23.
//

#ifndef TP_FOURMIS_ORRULE_H
#define TP_FOURMIS_ORRULE_H


#include <vector>
#include "AbstractRule.h"

class OrRule : public AbstractRule {

private:
    std::vector<AbstractRule *> rules; // Tableau de

public:
    OrRule(const std::vector<AbstractRule *> &rules);

    bool condition() override;

    void action() override;
};


#endif //TP_FOURMIS_ORRULE_H
