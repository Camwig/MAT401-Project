
#include <iostream>
#include <iomanip>
#include <fstream>

#include <variant>
#include <cassert>


#include "Runge_Kutta.h"
#include "Task_1_and_2.h"
#include "Task_3_and_4.h"
#include "Task_5.h"

void Task_2()
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
		xe = /*20.0*/5.0,
		dx = /*0.1;*/1.0;

	//std::vector<std::vector<float>> vect;
	//vect = r.RK4(x0, y0, xe, dx);

	double M = 10;
	double R = 1;
	double H = 4;

	double Omega_0x = 3, Omega_0y = 1, Omega_0z = 2;

	std::vector<std::vector<double>> Out_x;
	std::vector<std::vector<double>> Out_y;
	std::vector<std::vector<double>> Out_z;

	task_.Init(M, R, H);
	task_.Solve_Task_1(Out_x, Out_y, Out_z, Omega_0x, Omega_0y, Omega_0z, dx, x0, xe);

	std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::printf("Generated values\n");

	std::cout << std::setprecision(10);

	std::vector<double> Output_1_x = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_2_x = maths->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> Output_1_y = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_2_y = maths->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> Output_1_z = maths->Generate_zeros(xe, dx);
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
}

void Task_4()
{
	Runge_Kutta r;
	Task_3_and_4 task_;
	math_library* maths;

	maths = new math_library();

	double y0 = 0.0,
		x0 = 0.0,
		xe = /*20.0*/5.0,
		dx = /*0.1;*/1.0;

	std::array<double, 3> Initial_velocity = { 0,0,200 };
	std::array<double, 3> Initial_position = { 0,0,0 };

	std::vector<std::vector<double>> Out_vx;
	std::vector<std::vector<double>> Out_vy;
	std::vector<std::vector<double>> Out_vz;

	std::vector<std::vector<double>> Out_px;
	std::vector<std::vector<double>> Out_py;
	std::vector<std::vector<double>> Out_pz;

	//task_.Init(Initial_velocity,Initial_position);
	task_.Solve_Task_3(Initial_velocity, Initial_position,Out_vx,Out_vy,Out_vz,Out_px,Out_py,Out_pz,dx,x0,xe);


	std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::cout << std::setprecision(10);

	std::vector<double> Output_Vx = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Vy = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Vz = maths->Generate_zeros(xe, dx);

	std::vector<double> Output_Px = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Py = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Pz = maths->Generate_zeros(xe, dx);

	std::vector<double> Output_Time = maths->Generate_Half_open_interval(dx, x0, xe);


	std::printf("Velocity X\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_vx.size(); i++)
	{
		for (int j = 0; j < Out_vx[i].size(); j++)
		{
			std::cout << Out_vx[i][j] << " ";

			if (i == 0)
				Output_Vx[j] = Out_vx[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Velocity Y\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_vy.size(); i++)
	{
		for (int j = 0; j < Out_vy[i].size(); j++)
		{
			std::cout << Out_vy[i][j] << " ";

			if (i == 0)
				Output_Vy[j] = Out_vy[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Velocity Z\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_vz.size(); i++)
	{
		for (int j = 0; j < Out_vz[i].size(); j++)
		{
			std::cout << Out_vz[i][j] << " ";

			if (i == 0)
				Output_Vz[j] = Out_vz[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Displacement X\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_px.size(); i++)
	{
		for (int j = 0; j < Out_px[i].size(); j++)
		{
			std::cout << Out_px[i][j] << " ";

			if (i == 0)
				Output_Px[j] = Out_px[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Displacement Y\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_py.size(); i++)
	{
		for (int j = 0; j < Out_py[i].size(); j++)
		{
			std::cout << Out_py[i][j] << " ";

			if (i == 0)
				Output_Py[j] = Out_py[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Displacement Z\n");
	std::cout << std::endl;

	for (int i = 0; i < Out_pz.size(); i++)
	{
		for (int j = 0; j < Out_pz[i].size(); j++)
		{
			std::cout << Out_pz[i][j] << " ";

			if (i == 0)
				Output_Pz[j] = Out_pz[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	std::printf("Generated values\n");

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << "Velocity X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Vx.size(); i++)
	{
		my_file << Output_Vx[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Velocity Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Vy.size(); i++)
	{
		my_file << Output_Vy[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Velocity Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Vz.size(); i++)
	{
		my_file << Output_Vz[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Px.size(); i++)
	{
		my_file << Output_Px[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Py.size(); i++)
	{
		my_file << Output_Py[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_Pz.size(); i++)
	{
		my_file << Output_Pz[i] << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file.close();

	maths = nullptr;
	delete maths;
}

int main()
{
	Task_2();
	//Task_4();
	return 0;
}