#ifndef READFILES_H
#define READFILES_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>

using namespace std;

class ReadFiles {
public:
    vector<string>  Read_Names_from_file();
    vector<double>  Read_Mass_from_file();
    vector<vector<double>> Read_InitialConditions_from_file();

    vector<string> names;
    vector<double> mass;
    vector<vector<double>> initialConditions;

};


#endif // READFILES_H
