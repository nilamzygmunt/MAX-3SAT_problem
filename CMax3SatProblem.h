//
// Created by Nilam Zygmunt on 25/12/2021.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CMAX3SATPROBLEM_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CMAX3SATPROBLEM_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class CMax3SatProblem {
private:
    vector<vector<int>> v_conditions;
    const int NUMBER_OF_ELEMENTS = 6;
    int i_varNum;
    int conditionsNum;
    int i_quality;
public:
    bool bLoad(string file);
    int iCompute(vector<int>& solution);
    void v_print();
    int i_getVarNum(){return i_varNum;};
    int getConditionsNumber(){return conditionsNum;};





};


#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA_6_CMAX3SATPROBLEM_H
