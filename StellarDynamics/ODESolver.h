#ifndef ODESOLVER_H
#define ODESOLVER_H
#include "Planets.h"


class ODESolver
{
public:
    void RK4_Newtonian(double* x, double* y, double* z, double*vx , double* vy, double* vz, int N, double h, double* a);
    void RK4_PostNewtonian(double* x, double* y, double* z, double*vx , double* vy, double* vz, int N, double h, double* a);
    double k(double v, double h);
    double k_r_newtonian(double v, double h);
    double k_v_newtonian(double r_i, double h, double r);
    double Newtonian(double r);
    double k_v_postnewtonian(double r_i, double v_i, double h, double r, double v, double rdotv);
    double PostNewtonian_pos(double r, double v);
    double PostNewtonian_vel(double r, double v, double rdotv);
};

#endif // FORWARDEULER_H
