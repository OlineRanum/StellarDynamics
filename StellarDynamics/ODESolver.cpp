#include "ODESolver.h"
#include <iostream>
#include <cmath>
#include <Planets.h>

using namespace std;

void ODESolver::Verlet(double* x, double* y, double* z,  double*vx , double* vy, double* vz, int N, double h, double* a){
    // To run the velocity Verlet ODESolver for a 2-body system
    double G = 4*M_PI*M_PI;
    double M_BH = 1;
    double M_S = 1;
    double c = 1;

    double r0 = sqrt(x[0]*x[0] + y[0]*y[0] + z[0]*z[0]);
    double v0 = sqrt(vx[0]*vx[0] + vy[0]*vy[0] + vz[0]*vz[0]);
    cout << x[0] << " " << y[0] << " " << z[0] << "\n";
    a[0] = -G*M_S/(r0*pow(r0,2));
    //a[0] = G*M_S/(pow(c, 2)*pow(r0,3))*(pow(c, 2) + pow(v0, 2) + );
    clock_t st, fi;
    st = clock();
    for (int i = 1; i < N; i++ ){

        x[i]  = x[i-1] +  h*vx[i-1] + h*h/2*a[i-1]*x[i-1];
        y[i]  = y[i-1] +  h*vy[i-1] + h*h/2*a[i-1]*y[i-1];
        z[i]  = z[i-1] +  h*vz[i-1] + h*h/2*a[i-1]*z[i-1];

        double r = sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i]);
        a[i] = -G*M_S/(r*pow(r,2));

        vx[i] = vx[i-1]+h/2*(a[i]*x[i] + a[i-1]*x[i-1]);
        vy[i] = vy[i-1]+h/2*(a[i]*y[i] + a[i-1]*y[i-1]);
        vz[i] = vz[i-1]+h/2*(a[i]*z[i] + a[i-1]*z[i-1]);
   //     cout << x[i] << " " << y[i] << " " << z[i] << "\n";
    }
    fi = clock();
    double tottime = ( ( fi - st ) / static_cast<double> CLOCKS_PER_SEC );
    cout << "Verlet time: " << tottime << endl;


}