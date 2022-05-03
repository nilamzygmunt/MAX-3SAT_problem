//
// Created by Nilam Zygmunt on 25/12/2021.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CGAOPTIMIZE_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CGAOPTIMIZE_H
#include "CIndividual.h"
#include "CMax3SatProblem.h"
class CGAOptimizer {
private:
    int i_populationSize;
    double d_crossingProbability;
    double d_mutationProbability;
    vector<CIndividual*> v_Children;
    vector<CIndividual*>* v_newPopulation;
    vector<CIndividual*>* v_individuals;
    CIndividual* parent1;
    CIndividual* parent2;
    CIndividual* child1;
    CIndividual* child2;
    CMax3SatProblem * pc_Max3SatProblem ;
    int i_bestInPopulation;
public:
    CGAOptimizer(int populationSize, double crossingProbability, double mutationProbability);
    ~CGAOptimizer();
    void vDeletePopulation(vector<CIndividual*>* v_individuals);
    bool bInitialize(string file);
    bool bRunIteration();
    CIndividual* chooseParent(vector<CIndividual*>*  v_population);
    void crossing(CIndividual* parent1, CIndividual* parent2);
    bool mutate(CIndividual &v_child);
    bool addIndividual(vector<CIndividual*>* v_population, CIndividual* child1, CIndividual* child2) ;
    double bestFitnessInPopulation();
    vector<int> bestGenotypeInPopulation();
};


#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CGAOPTIMIZE_H
