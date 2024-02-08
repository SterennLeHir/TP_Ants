//
// Created by esir on 23/05/23.
//

#ifndef TP_FOURMIS_ABSTRACTRULE_H
#define TP_FOURMIS_ABSTRACTRULE_H


class AbstractRule {

public:
    virtual bool condition() = 0; // Méthode virtuelle pure

    virtual void action() = 0; // Méthode virtuelle pure

    virtual ~AbstractRule() = default;
};


#endif //TP_FOURMIS_ABSTRACTRULE_H
