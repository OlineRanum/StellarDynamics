#ifndef PLANETS_H
#define PLANETS_H

#include <iostream>
#include <vector>

using namespace std;


class Planets
{
public:
    Planets(string name, double mass, vector<double> initialConditions, int N_);
    string m_name;
    double m_mass;
    int N;
    double x0, y0, z0, vx0, vy0, vz0, r0, v0;
    /*
    double * x = new double [N];
    double * y = new double [N];
    double * z = new double [N];
    double * vx = new double [N];
    double * vy = new double [N];
    double * vz = new double [N];
    double * a = new double [N];
    */
    double * x;
    double * y;
    double * z;
    double * vx;
    double * vy;
    double * vz;
    double * ax;
    double * ay;
    double * az;
    double velocity_magnitude();

private:
};

#endif // PLANETS_H
