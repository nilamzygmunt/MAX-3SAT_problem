//
// Created by Nilam Zygmunt on 17/01/2022.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CINDIVIDUAL_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CINDIVIDUAL_H

#include "CMax3SatProblem.h"
class CIndividual {
private:
    vector<int> v_genotype;
    bool b_currentFitnesss; //temp
    int i_fitness;
    const int HUNDRED = 100;
public:
    vector<int>& vgetGenotype(){return v_genotype;};
    void v_printGenotype();
    void v_initialize(CMax3SatProblem & cProblem);
    void operator=(const CIndividual &pcOther);
    int iFitness(CMax3SatProblem & cProblem);
    vector<CIndividual*> bCrossover(CIndividual &pcOther, double probability);
    bool Mutation(double probability);
};


#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CINDIVIDUAL_H
