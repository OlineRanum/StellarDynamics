#ifndef WRITERESULTS_H
#define WRITERESULTS_H
#include <iostream>
#include <string>

using namespace std;


class WriteResults
{
public:
    void WR_5A(double* t,double* x, double* y, double* z, double* vx, double* vy, double* vz, int N, string filename);

};

#endif // WRITERESULTS_H
