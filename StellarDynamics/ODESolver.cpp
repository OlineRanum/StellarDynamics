#include "ODESolver.h"
#include <iostream>
#include <cmath>
#include <Planets.h>

using namespace std;


double ODESolver::Newtonian(double r){
    double G = 4*M_PI*M_PI;
    double M_BH = 4.15*pow(10, 6);                  // M-BH = 4.10*10^6 M-Sun, units in solar units
    double M_S = M_BH;
    double c = 63198;
    return -G*M_S/(r*r*r);
}

double ODESolver::k_v_newtonian(double r_i, double h, double r){
    double k1 = Newtonian(r)*r_i;
    double k2 = Newtonian(r + k1*h/2)*r_i;
    double k3 = Newtonian(r + k2*h/2)*r_i;
    double k4 = Newtonian(r + k3*h)*r_i;
    return h*(k1+2*k2+2*k3+k4)/6;
}


double ODESolver::k_r_newtonian(double v_i, double h){
    double k1 = v_i;
    double k2 = v_i*k1*h/2;
    double k3 = v_i*k2*h/2;
    double k4 = v_i*k3*h;
    return h*(k1+2*k2+2*k3+k4)/6;
}

void ODESolver::RK4_Newtonian(double* x, double* y, double* z,  double*vx , double* vy, double* vz, int N, double h, double* a){
    double G = 4*M_PI*M_PI;
    double M_BH = 4.15*pow(10, 6);                  // M-BH = 4.10*10^6 M-Sun, units in solar units
    double M_S = M_BH;
    double c = 63198;


    double r0 = sqrt(x[0]*x[0] + y[0]*y[0] + z[0]*z[0]);
    a[0] = Newtonian(r0);
    double r;

    for (int i = 1; i < N; i++ ){
        r = sqrt(x[i-1]*x[i-1] + y[i-1]*y[i-1] + z[i-1]*z[i-1]);
        vx[i] = vx[i-1]+ k_v_newtonian(x[i-1], h, r);
        vy[i] = vy[i-1]+ k_v_newtonian(y[i-1], h, r);
        vz[i] = vz[i-1]+ k_v_newtonian(z[i-1], h, r);

        x[i] = x[i-1] +h*vx[i];
        y[i] = y[i-1] +h*vy[i];
        z[i] = z[i-1] + h*vz[i];
    }
}

double ODESolver::PostNewtonian_pos(double r, double v){
    double G = 4*M_PI*M_PI;
    double M_BH = 4.15*pow(10, 6);                  // M-BH = 4.10*10^6 M-Sun, units in solar units
    double M_S = M_BH;
    double c = 63198;

    return -G*M_S/(pow(c,2)*pow(r,4))*(r*(pow(c,2)-4*G*M_S/r+pow(v,2)));
}

double ODESolver::PostNewtonian_vel(double r, double v, double rdotv){
    double G = 4*M_PI*M_PI;
    double M_BH = 4.15*pow(10, 6);                  // M-BH = 4.10*10^6 M-Sun, units in solar units
    double M_S = M_BH;
    double c = 63198;

    return -G*M_S/(pow(c,2)*pow(r,4))*(4*v*rdotv);
}


double ODESolver::k_v_postnewtonian(double r_i, double v_i, double h, double r, double v, double rdotv){
    double k1 = PostNewtonian_pos(r, v)*r_i + PostNewtonian_vel(r,v,rdotv)*v_i;
    double k2 = PostNewtonian_pos(r + k1*h/2, v + k1*h/2)*r_i + PostNewtonian_vel(r + k1*h/2, v + k1*h/2, rdotv + k1*h/2)*v_i;
    double k3 = PostNewtonian_pos(r + k2*h/2, v + k2*h/2)*r_i + PostNewtonian_vel(r + k2*h/2, v + k2*h/2, rdotv + k2*h/2)*v_i;
    double k4 = PostNewtonian_pos(r + k3*h, v + k3*h)*r_i + PostNewtonian_vel(r + k3*h, v + k3*h, rdotv + k3*h)*v_i;
    return h*(k1+2*k2+2*k3+k4)/6;
}


void ODESolver::RK4_PostNewtonian(double* x, double* y, double* z,  double*vx , double* vy, double* vz, int N, double h, double* a){
    double G = 4*M_PI*M_PI;
    double M_BH = 4.15*pow(10, 6);                  // M-BH = 4.10*10^6 M-Sun, units in solar units
    double M_S = M_BH;
    double c = 63198;
    double const1;


    double r0 = sqrt(x[0]*x[0] + y[0]*y[0] + z[0]*z[0]);
    double v0 = sqrt(vx[0]*vx[0] + vy[0]*vy[0] + vz[0]*vz[0]);
    double r0dotv0 = x[0]*vx[0] + y[0]*vy[0] + z[0]*vz[0];

    a[0] = Newtonian(r0);
    double r; double v; double rdotv_;
    clock_t st, fi;
    st = clock();

    for (int i = 1; i < N; i++ ){
        r = sqrt(x[i-1]*x[i-1] + y[i-1]*y[i-1] + z[i-1]*z[i-1]);
        v = sqrt(vx[i-1]*vx[i-1] + vy[i-1]*vy[i-1] + vz[i-1]*vz[i-1]);
        rdotv_ = x[i-1]*vx[i-1] + y[i-1]*vy[i-1] + z[i-1]*vz[i-1];

        vx[i] = vx[i-1]+ k_v_postnewtonian(x[i-1], vx[i-1], h, r, v,rdotv_);
        vy[i] = vy[i-1]+ k_v_postnewtonian(y[i-1], vy[i-1], h, r, v,rdotv_);
        vz[i] = vz[i-1]+ k_v_postnewtonian(z[i-1], vz[i-1], h, r, v,rdotv_);

        x[i] = x[i-1] +h*vx[i];
        y[i] = y[i-1] +h*vy[i];
        z[i] = z[i-1] + h*vz[i];

    }




    fi = clock();
    double tottime = ( ( fi - st ) / static_cast<double> CLOCKS_PER_SEC );
    cout << "Verlet time: " << tottime << endl;


}
