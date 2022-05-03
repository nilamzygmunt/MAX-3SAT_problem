//
// Created by Nilam Zygmunt on 25/12/2021.
//

#include "CGAOptimizer.h"
CGAOptimizer::~CGAOptimizer()
{
    vDeletePopulation(v_individuals);
    delete v_individuals;
    delete pc_Max3SatProblem;
    cout<<"destr"<<endl;
}
CGAOptimizer ::CGAOptimizer(int populationSize, double crossingProbability, double mutationProbability)
{
    i_populationSize = populationSize;
    d_crossingProbability = crossingProbability;
    d_mutationProbability = mutationProbability;
    v_individuals = new vector<CIndividual*>;
    parent1= NULL;
    parent2 = NULL;
    child1 = NULL;
    child2 = NULL;
    pc_Max3SatProblem = new CMax3SatProblem();

}
bool CGAOptimizer::bInitialize(string file)
{
    pc_Max3SatProblem->bLoad(file);
    //cout<<pc_Max3SatProblem->i_getVarNum()<<endl;
    for (int i = 0; i < i_populationSize; i++)
    {
        (*v_individuals).push_back(new CIndividual());
        (*v_individuals).at(i)->v_initialize(*pc_Max3SatProblem);
    }
    return 1;
}
bool CGAOptimizer::bRunIteration() {

    v_newPopulation = new vector<CIndividual*>;
    while((*v_newPopulation).size()<(*v_individuals).size())
    {
        parent1 = chooseParent(v_individuals);
        parent2 = chooseParent(v_individuals);
        crossing(parent1, parent2);
        mutate(*child1);
        mutate(*child2);
        addIndividual(v_newPopulation, child1, child2);
    }
    vDeletePopulation(v_individuals);
    v_individuals = v_newPopulation;
    v_newPopulation = NULL;
    //delete v_newPopulation;
    return 1;
}

CIndividual* CGAOptimizer::chooseParent(vector<CIndividual*>* v_population)
{
    int iRand = rand()%v_population->size();
    CIndividual* first  = v_population->at(iRand);
    iRand = rand()%v_population->size();
    CIndividual* second  = v_population->at(iRand);
    if(first->iFitness(*pc_Max3SatProblem) >= second->iFitness(*pc_Max3SatProblem))
    {
        return first;
    }
    else
    {
        return second;
    }
}
void CGAOptimizer::crossing(CIndividual* parent1, CIndividual* parent2)
{
    v_Children = parent1->bCrossover(*parent2, d_crossingProbability);
    child1 = v_Children[0];
    child2 = v_Children[1];
    v_Children.pop_back(); v_Children.pop_back();
}
bool CGAOptimizer::mutate(CIndividual &v_child)
{
    v_child.Mutation(d_mutationProbability);
    return 1;
}
bool  CGAOptimizer::addIndividual(vector<CIndividual*>* v_population, CIndividual* child1, CIndividual* child2)
{
    v_population->push_back(child1);
    v_population->push_back(child2);
    return 1;
}

double  CGAOptimizer::bestFitnessInPopulation()
{
    double bestFitness=0;
    for(int ii = 0; ii<(*v_individuals).size(); ii++)
    {
        if(bestFitness < (*v_individuals).at(ii)->iFitness(*pc_Max3SatProblem))
        {
            bestFitness = (*v_individuals).at(ii)->iFitness(*pc_Max3SatProblem);
            i_bestInPopulation = ii;
        }
    }
    cout<<"Fit: "<<bestFitness<<" Cond num "<<pc_Max3SatProblem->getConditionsNumber()<<endl;
    return bestFitness/(double) pc_Max3SatProblem->getConditionsNumber();
}
void CGAOptimizer::vDeletePopulation(vector<CIndividual *>* v_population)
{
    for (int ii = 0; ii < v_population->size(); ii++)
    {
        delete v_population->at(ii);
    }
    v_population->clear();
}
vector<int>  CGAOptimizer::bestGenotypeInPopulation()
{
    return (*v_individuals).at(i_bestInPopulation)->vgetGenotype();
}