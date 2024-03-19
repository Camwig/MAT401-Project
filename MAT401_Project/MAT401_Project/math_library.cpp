#include "math_library.h"
#include <iostream>
math_library::math_library()
{
}

math_library::~math_library()
{
}

std::vector<double> math_library::Generate_Half_open_interval(double step, double start, double end)
{
	std::vector<double> output;
	for (float i = start; i < end+step; i+=step)
	{
		////std::cout << "Generating values :" << i << "\n";
		output.push_back(i);
	}
	return output;
}

//Need to fix this so it works based of the step size and so on
std::vector<double> math_library::Generate_zeros(double length)
{
	std::vector<double> output;
	for (float i = 1; i <= length; i++)
	{
		//std::cout << "Generating values :" << i << "\n";
		output.push_back(0);
	}
	//std::printf("Done\n");
	return output;
}