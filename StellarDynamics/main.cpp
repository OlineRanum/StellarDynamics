#include <iostream>
#include <list>
#include <ReadFiles.h>
#include <ODESolver.h>
#include <SolarSystem.h>
#include <WriteResults.h>

using namespace std;

int main()
{
    int N = 1e7;
    double t0 = 0; double tf = 20;     // Years
    double h = (tf-t0)/N;
    double * t = new double [N];
    for (int i=0; i <N; i ++){t[i] = t0 + i*h;}


    // Initiate Class Instances
    ReadFiles *rf             = new ReadFiles();

    // Initiate Variables
    vector<double> PlanetMass;
    vector<vector<double>> initialConditions ;
    vector<string> PlanetNames;

    // Read Variables from .txt files
    PlanetNames = rf->Read_Names_from_file();
    PlanetMass = rf->Read_Mass_from_file();
    initialConditions = rf->Read_InitialConditions_from_file();

    ODESolver *ODES        = new ODESolver();
    WriteResults *WR       = new WriteResults();



    // SINGLE PLANET SYSTEM

    double * x = new double [N];
    double * y = new double [N];
    double * z = new double [N];
    double * vx = new double [N];
    double * vy = new double [N];
    double * vz = new double [N];
    double * a = new double [N];
    x[0] = 1;
    y[0] = 0;
    z[0] = 0;
    vx[0] = 0;
    vy[0] = 6.28;
    vz[0] = 0;

    ODES -> Verlet(x, y, z, vx , vy, vz, N, h, a);
    WR -> WR_5A(t, x, y, z, vx, vy, vz, N, "ODESolved");

    cout << "Run Complete"<< "\n";
    delete [] x; delete [] y ; delete [] z; delete [] vx; delete [] vy; delete[] vz; delete [] a;
   }
