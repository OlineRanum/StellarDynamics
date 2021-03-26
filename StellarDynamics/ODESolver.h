#ifndef ODESOLVER_H
#define ODESOLVER_H
#include "Planets.h"


class ODESolver
{
public:
    void Verlet(double* x, double* y, double* z, double*vx , double* vy, double* vz, int N, double h, double* a);
    double Newtonian(double r);
    double PostNewtonian(double r, double v);
};

#endif // FORWARDEULER_H
