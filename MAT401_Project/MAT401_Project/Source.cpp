
#include <iostream>
#include <iomanip>
#include <fstream>

#include <variant>
#include <cassert>


#include "Runge_Kutta.h"
#include "Task_1_and_2.h"

int main()
{
	Runge_Kutta r;
	Task_1_and_2 task_;
	math_library* maths;

	maths = new math_library();

	//std::printf("Hello World\n");

	//int Inertia_Tensor[3][3];

	//Remeber to use a smaller timestep so like 0.01 for example

	double y0 = 0.0,
		x0 = 0.0,
		xe = 20.0/*20.0*/,
		dx = 0.1;

	//std::vector<std::vector<float>> vect;
	//vect = r.RK4(x0, y0, xe, dx);

	double M = 10;
	double R = 1;
	double H = 4;

	double Omega_0x = 3, Omega_0y = 1, Omega_0z = 2;

	std::vector<std::vector<double>> Out_x;
	std::vector<std::vector<double>> Out_y;
	std::vector<std::vector<double>> Out_z;

	task_.Init(M,R,H);
	task_.Solve_Task_1(Out_x,Out_y,Out_z,Omega_0x,Omega_0y,Omega_0z,dx,x0,xe);

	std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::printf("Generated values\n");

	std::cout << std::setprecision(10);

	std::vector<double> Output_1_x = maths->Generate_zeros(xe,dx);
	std::vector<double> Output_2_x = maths->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> Output_1_y = maths->Generate_zeros(xe,dx);
	std::vector<double> Output_2_y = maths->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> Output_1_z = maths->Generate_zeros(xe,dx);
	std::vector<double> Output_2_z = maths->Generate_Half_open_interval(dx, x0, xe);

	for (int i = 0; i < Out_x.size(); i++)
	{
		for (int j = 0; j < Out_x[i].size(); j++)
		{
			std::cout << Out_x[i][j] << " ";

			if (i == 0)
				Output_1_x[j] = Out_x[i][j];

			//else if (i > 0)
			//	Output_2_x[j] = Out_x[i][j];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < Out_y.size(); i++)
	{
		for (int j = 0; j < Out_y[i].size(); j++)
		{
			std::cout << Out_y[i][j] << " ";

			if (i == 0)
				Output_1_y[j] = Out_y[i][j];

			//else if (i > 0)
			//	Output_2_y[j] = Out_y[i][j];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < Out_z.size(); i++)
	{
		for (int j = 0; j < Out_z[i].size(); j++)
		{
			std::cout << Out_z[i][j] << " ";

			if (i == 0)
				Output_1_z[j] = Out_z[i][j];

			//else if (i > 0)
			//	Output_2_z[j] = Out_z[i][j];
		}
		std::cout << std::endl;
	}

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << "Omega X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_1_x.size(); i++)
	{
		my_file << Output_1_x[i] << ",";
		my_file << Output_2_x[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Omega Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_1_y.size(); i++)
	{
		my_file << Output_1_y[i] << ",";
		my_file << Output_2_y[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Omega Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_1_z.size(); i++)
	{
		my_file << Output_1_z[i] << ",";
		my_file << Output_2_z[i] << std::endl;
	}

	//for (int i = 0; i < Out_y.size(); i++)
	//{
	//	for (int j = 0; j < Out_y[i].size(); j++)
	//	{
	//		std::cout << Out_y[i][j] << " ";
	//		my_file << Out_y[i][j] << ",";
	//	}
	//	std::cout << std::endl;
	//	my_file << std::endl;
	//}

	//for (int i = 0; i < Out_z.size(); i++)
	//{
	//	for (int j = 0; j < Out_z[i].size(); j++)
	//	{
	//		std::cout << Out_z[i][j] << " ";
	//		my_file << Out_z[i][j] << ",";
	//	}
	//	std::cout << std::endl;
	//	my_file << std::endl;
	//}

	my_file.close();

	maths = nullptr;
	delete maths;


	//Keep the below as that is for outputting to the csv file

	//std::ofstream my_file("test.csv");

	//my_file << std::setprecision(10);

	//if (my_file.is_open()) {
	//	//my_file << ("Cheese") << "," << ("Bums") <<std::endl;
	//	for (int i = 0; i < vect.size(); i++)
	//	{
	//		for (int j = 0; j < vect[i].size(); j++)
	//		{
	//			my_file << vect[i][j] << ",";
	//		}
	//		my_file << std::endl;
	//	}
	//}

	//my_file.close();
	return 0;
}