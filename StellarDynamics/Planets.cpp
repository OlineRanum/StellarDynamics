#include "Planets.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Planets::Planets(string name, double mass, vector<double> initialConditions, int N_){
    m_name = name;
    m_mass = mass;
    N = N_;
    x = new double [N];
    y = new double [N];
    z = new double [N];
    vx = new double [N];
    vy = new double [N];
    vz = new double [N];
    ax = new double [N];
    ay = new double [N];
    az = new double [N];

    x0  = initialConditions[0];
    y0  = initialConditions[1];
    z0  = initialConditions[2];
    vx0 = initialConditions[3];// *365;                 // Include these if run for NASA initial conditions
    vy0 = initialConditions[4];// *365;
    vz0 = initialConditions[5];// *365;
    x[0]  = x0;
    y[0]  = y0;
    z[0]  = z0;
    vx[0]  = vx0;
    vy[0]  = vy0;
    vz[0]  = vz0;
    r0 = sqrt(x0*x0 + y0*y0 + z0*z0);
    v0 = sqrt(vx0*vx0 + vy0*vy0 + vz0*vz0);

};


