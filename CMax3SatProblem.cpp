//
// Created by Nilam Zygmunt on 25/12/2021.
//
#include <math.h>
#include "CMax3SatProblem.h"

/*
bool CMax3SatProblem::bLoad(string file) {
    ifstream File;
    File.open(file);
    char brackets;
    int i_row = 0, i_column =0;
    i_varNum = 0;
    int num;
    File >> brackets;
    while(!File.eof()) {
        vector<int> vec;
        v_conditions.push_back(vec);
        while (i_column < NUMBER_OF_ELEMENTS) {
            File>>num;
            v_conditions[i_row].push_back(num);
            i_column++;
            if(abs(num)+1 >= i_varNum)
            {
                i_varNum = abs(num) +1;
            }
        }
        File >> brackets >> brackets;
        i_row++; i_column = 0;
    }
    conditionsNum =i_row;
    File.close();
    return 1;
}
 */

bool CMax3SatProblem::bLoad(string file) {
    ifstream File;
    File.open(file);
    char brackets;
    int i_row = 0, i_column =0;
    i_varNum = 0;
    int i_num;
    File >> brackets;
    while(!File.eof()) {
        vector<int> vec;
        v_conditions.push_back(vec);
        while (i_column < NUMBER_OF_ELEMENTS) {
            File >> i_num;
            v_conditions[i_row].push_back(i_num);
            i_column++;
            if(abs(i_num) + 1 >= i_varNum)
            {
                i_varNum = abs(i_num) + 1;
            }
            if(v_conditions[i_row].size() == NUMBER_OF_ELEMENTS/2)
            {
                File >> brackets >>brackets;
            }
        }
        File >> brackets >>brackets;
        i_row++; i_column = 0;
    }
    conditionsNum =i_row;
    File.close();
    v_print();
    return 1;
}
/*
bool CMax3SatProblem::bLoad(string file) {
    ifstream File;
    File.open(file);
    char brackets;
    int i_row = 0, i_column =0;
    int line = 0;
    i_varNum = 0;
    int num;
    File >> brackets;
    vector<int> vec;
    v_conditions.push_back(vec);
    while(!File.eof()) {
        line++;
        while (i_column < NUMBER_OF_ELEMENTS) {
            File>>num;
            v_conditions[i_row].push_back(num);
            i_column++;
            if(abs(num)+1 >= i_varNum)
            {
                i_varNum = abs(num) +1;
            }
        }
        File >> brackets >> brackets;
        if(line !=0 && line%2 == 0)
        {
            cout<<"iteration "<<line<<endl;
            i_row++;
            vector<int> vec;
            v_conditions.push_back(vec);
        }
        i_column = 0;
    }
    conditionsNum =i_row;
    v_conditions.pop_back();
    File.close();
    v_print();
    return 1;
}
*/
int CMax3SatProblem::iCompute(vector<int>& solution)
{
    //cout<<"Compute"<<endl;
    i_quality = 0;
    int i_row = 0, i_column =0;
    while(i_row< v_conditions.size())
    {
        if(v_conditions[i_row][i_column]>= 0)
        {
            if(solution[v_conditions[i_row][i_column]]==1)
            {
                i_quality++;
                i_column = v_conditions[i_row].size() - 1;
            }
        }
        else
        {
            if(solution[-1*(v_conditions[i_row][i_column])]==0)
            {
                i_quality++;
                i_column = v_conditions[i_row].size() - 1;
            }
        }
        i_column++;
        if(i_column%v_conditions[i_row].size()==0)
        {
            i_row++; i_column=0;
        }
    }
    return i_quality;
}
void CMax3SatProblem ::v_print() {
    for(int j = 0; j < v_conditions.size(); j++)
    {
        for (int i = 0; i < v_conditions[j].size(); i++) {
            cout << v_conditions[j][i] << ' ';
        }
        cout<<endl;
    }
}