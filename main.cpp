#include <iostream>
#include <string>
#include <time.h>
#include "CGAOptimizer.h"


using namespace std;
using namespace std::chrono;

int main() {

    CGAOptimizer *cga = new CGAOptimizer(10, 0.3, 0.3);
    cga->bInitialize("m3s_50_0.txt");
    clock_t t;
    t = clock();
    int i = 0;
   // while((double)((clock()-t)/CLOCKS_PER_SEC)<=100)
    while(i<3)
    {
       // if(i%5000 == 0)
       //cout<<"----------------------"<<i<<"-------------"<<endl;
       cga->bRunIteration();
       i++;

    }
    cout<<cga->bestFitnessInPopulation()<<endl;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_taken<<endl;
    delete cga;
}
