#include "SolarSystem.h"
#include <iostream>
#include <string>
#include <vector>
#include "Planets.h"
#include "ODESolver.h"
#include "WriteResults.h"
#include <cmath>

using namespace std;

void SolarSystem::CreateSolarSystem(vector<string> Names, vector<double> Mass, vector<vector<double>> initialConditions, int N, double h, string mode, int N_planets, double * time){

    vector<Planets*> SolarSystem_planets;
    ODESolver *ODES        = new ODESolver();
    WriteResults *WR          = new WriteResults();
    for (int i = 0; i < N_planets; i++){
        Planets* p = new Planets(Names[i], Mass[i], initialConditions[i], N);
        SolarSystem_planets.push_back(p);
        cout << p->m_name << endl;
    }

    if (mode == "Fix"){
        for (int i = 0; i < N; i++){
            SolarSystem_planets[0]->x[i]  = 0;
            SolarSystem_planets[0]->y[i]  = 0;
            SolarSystem_planets[0]->z[i]  = 0;
            SolarSystem_planets[0]->vx[i] = 0;
            SolarSystem_planets[0]->vy[i] = 0;
            SolarSystem_planets[0]->vz[i] = 0;
            SolarSystem_planets[0]->ax[i]  = 0;
            SolarSystem_planets[0]->ay[i]  = 0;
            SolarSystem_planets[0]->az[i]  = 0; }
    }

    if (mode == "FIXMERC"){
        for (int i = 0; i < N; i++){
            SolarSystem_planets[0]->x[i]  = 0;
            SolarSystem_planets[0]->y[i]  = 0;
            SolarSystem_planets[0]->z[i]  = 0;
            SolarSystem_planets[0]->vx[i] = 0;
            SolarSystem_planets[0]->vy[i] = 0;
            SolarSystem_planets[0]->vz[i] = 0;
            SolarSystem_planets[0]->ax[i]  = 0;
            SolarSystem_planets[0]->ay[i]  = 0;
            SolarSystem_planets[0]->az[i]  = 0; }
    }

}





