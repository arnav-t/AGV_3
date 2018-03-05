/*
Applying 1D kalman filter seperately to x and y directions. 
The velocity "measurements" will be determined calculated according to timestep as
V_k = (x_k - x_{k-1})/dT
*/

#include <iostream>
#include <fstream>
#include <string>

#ifndef Localization_HPP
#include "Localization.hpp"
#endif

using namespace std;
using namespace Eigen;

#define DEFAULT_DATASET "Landmarks.txt"

int main(int argc, char *argv[])
{
	char path[32];
	if(argc == 2)
		strcpy(path, argv[1]);
	Localization l(path);
	return 0;
}