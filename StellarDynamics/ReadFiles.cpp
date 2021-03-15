#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

#include "ReadFiles.h"


using namespace std;

using std::fstream;


vector<string> ReadFiles::Read_Names_from_file()
{
    string line;
      ifstream myfile ("Names.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
            names.push_back(line.c_str());
        }
        myfile.close();
      }

      else cout << "Unable to open name file\n";
      return names;
}

vector<double> ReadFiles::Read_Mass_from_file()
{
    string line;
      ifstream myfile ("Mass.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {

            mass.push_back(atof(line.c_str()));
        }
        myfile.close();
      }

      else cout << "Unable to open Mass file\n";
      return mass;
}


vector<vector<double>> ReadFiles::Read_InitialConditions_from_file()
{
    vector<vector<double>> initialConditions;

    string a, b, c, d, e, f;

    ifstream myfile ("InitialConditions.txt");
    while(myfile >> a >> b >> c >> d >> e >> f){
        vector<double> temp = {stof(a), stof(b), stof(c), stof(d), stof(e), stof(f)};
        initialConditions.push_back(temp);
    }
    return initialConditions;
}


