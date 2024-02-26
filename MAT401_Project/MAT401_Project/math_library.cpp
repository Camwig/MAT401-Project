#include "math_library.h"
#include <iostream>
math_library::math_library()
{
}

math_library::~math_library()
{
}

std::vector<float> math_library::Generate_Half_open_interval(float step, float start, float end)
{
	std::vector<float> output;
	for (float i = start; i < end+step; i+=step)
	{
		////std::cout << "Generating values :" << i << "\n";
		output.push_back(i);
	}
	return output;
}

std::vector<float> math_library::Generate_zeros(float length)
{
	std::vector<float> output;
	for (float i = 1; i <= length; i++)
	{
		//std::cout << "Generating values :" << i << "\n";
		output.push_back(0);
	}
	//std::printf("Done\n");
	return output;
}