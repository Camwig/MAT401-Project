
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Runge_Kutta.h"

int main()
{
	Runge_Kutta r;

	std::printf("Hello World\n");

	

	float y0 = 0.0,
		x0 = 0.0,
		xe = 20.0,
		dx = 20.0;

	std::vector<std::vector<float>> vect;

	vect = r.RK2(1,0.1f,37,xe,dx);

	//vect = r.RK4(0.1f, 37, xe, dx);

	std::printf("Generated values\n");

	std::cout << std::setprecision(10);

	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect[i].size(); j++)
		{
			std::cout << vect[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	if (my_file.is_open()) {
		//my_file << ("Cheese") << "," << ("Bums") <<std::endl;
		for (int i = 0; i < vect.size(); i++)
		{
			for (int j = 0; j < vect[i].size(); j++)
			{
				my_file << vect[i][j] << ",";
			}
			my_file << std::endl;
		}
	}

	my_file.close();
	return 0;
}