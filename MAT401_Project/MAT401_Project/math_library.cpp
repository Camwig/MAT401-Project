#include "math_library.h"
#include <iostream>
math_library::math_library()
{
}

math_library::~math_library()
{
}

//Generates a vector full of values up to a length increasing by a certain step size
std::vector<double> math_library::Generate_Half_open_interval(double step, double start, double end)
{
	std::vector<double> output;
	for (float i = start; i <= end + step; i+=step)
	{
		output.push_back(i);
	}
	return output;
}

//Generate zeros function up to the length by a set step size of 1
std::vector<double> math_library::Generate_zeros(double length)
{
	std::vector<double> output;
	for (float i = 0; i <= length; i++)
	{
		output.push_back(0);
	}
	return output;
}

//Generate zeros function up to the length by a given step size
std::vector<double> math_library::Generate_zeros(double length,double step)
{
	std::vector<double> output;
	for (float i = 0; i <= length + step; i+= step)
	{
		output.push_back(0);
	}
	return output;
}

//Multiplies one 3 row column matrix and one 3x3 matrix together and then returns the result
std::vector<std::vector<double>> math_library::Matrix_multiplication(std::vector<std::vector<double>>& Matrix_1, std::vector<std::vector<double>>& Matrix_2, int R1,int C1, int R2,int C2)
{

	std::vector<std::vector<double>> rslt;

	rslt = { {0.0},{0.0},{0.0} };

	rslt[0][0] = (Matrix_1[0][0] * Matrix_2[0][0]) + (Matrix_1[1][0] * Matrix_2[0][1]) + (Matrix_1[2][0] * Matrix_2[0][2]);
	rslt[1][0] = (Matrix_1[0][0] * Matrix_2[1][0]) + (Matrix_1[1][0] * Matrix_2[1][1]) + (Matrix_1[2][0] * Matrix_2[1][2]);
	rslt[2][0] = (Matrix_1[0][0] * Matrix_2[2][0]) + (Matrix_1[1][0] * Matrix_2[2][1]) + (Matrix_1[2][0] * Matrix_2[2][2]);

	return rslt;
}