//
// Created by Nilam Zygmunt on 17/01/2022.
//

#include "CIndividual.h"
using namespace std;


void CIndividual ::v_initialize(CMax3SatProblem & cProblem) {
    for (int ii = 0; ii < cProblem.i_getVarNum(); ii++) {
        int num = rand() % 2;
        vgetGenotype().push_back(num);
    }
    //v_printGenotype();
    b_currentFitnesss = false;
}
vector<CIndividual*> CIndividual:: bCrossover(CIndividual &pcOther, double probability)
{
    double i_random = (rand()%HUNDRED)/(double)HUNDRED;
    vector<CIndividual*> v_newChildren;
    CIndividual* child1;
    CIndividual* child2;
    if(i_random <probability)
    {
        child1 = new CIndividual();
        child2 = new CIndividual();
        for(int i=0; i<vgetGenotype().size(); i++)
        {
            i_random = rand()%2;
            if(i_random ==0)
            {
                child1->vgetGenotype().push_back(vgetGenotype()[i]);
                child2->vgetGenotype().push_back(pcOther.vgetGenotype()[i]);
            }
            else
            {
                child1->vgetGenotype().push_back(pcOther.vgetGenotype()[i]);
                child2->vgetGenotype().push_back(this->vgetGenotype()[i]);
            }
        }
    }
    else
    {
        child1 = new CIndividual(*this);
        child2 = new CIndividual(pcOther);
    }
    v_newChildren.push_back(child1);
    v_newChildren.push_back(child2);
    child1 = NULL; child2 = NULL;
    return v_newChildren;
}
int CIndividual ::iFitness(CMax3SatProblem & cProblem)
{
    if(!b_currentFitnesss)
    {
       i_fitness =  cProblem.iCompute(vgetGenotype());
       b_currentFitnesss = true;
    }
    return i_fitness;
}
bool CIndividual::Mutation(double probability)
{
    double num;
    for (int j = 0; j < vgetGenotype().size(); j++) {
        num = (rand()%HUNDRED)/(double)HUNDRED;
        if (num <= probability)
        {
            if (vgetGenotype()[j] == 0)
            {
                vgetGenotype()[j] = 1;
            }
            else vgetGenotype()[j] = 0;
        }
    }
    b_currentFitnesss = false;
    return 1;
}
void CIndividual::v_printGenotype()
{
    cout<<endl;
    for (int i = 0; i < v_genotype.size(); i++) {
        cout << v_genotype[i];
    }
    cout<<endl;

}