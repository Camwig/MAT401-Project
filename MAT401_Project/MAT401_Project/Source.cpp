
#include <iostream>
#include <iomanip>
#include <fstream>

#include <variant>
#include <cassert>


#include "Runge_Kutta.h"
#include "Task_1_and_2.h"
#include "Task_3_and_4.h"
#include "Task_5.h"

math_library* maths;

void Task_2(double x0,double xe,double dx, double M, double R, double H, double Omega[3])
{
	//Runge_Kutta r;
	Task_1_and_2* task_;
	//math_library* maths;

	//maths = new math_library();
	task_ = new Task_1_and_2();

	//std::printf("Hello World\n");

//int Inertia_Tensor[3][3];

//Remeber to use a smaller timestep so like 0.01 for example

	//double y0 = 0.0,
	//	x0 = 0.0,
	//	xe = 20.0,
	//	dx = 0.1;;

	//std::vector<std::vector<float>> vect;
	//vect = r.RK4(x0, y0, xe, dx);

	//double M = 10;
	//double R = 1;
	//double H = 4;

	//double Omega_0x = 3, Omega_0y = 1, Omega_0z = 2;

	std::vector<std::vector<double>> Out_x;
	std::vector<std::vector<double>> Out_y;
	std::vector<std::vector<double>> Out_z;

	task_->Init(M, R, H);
	task_->Solve_Task_1(Out_x, Out_y, Out_z, Omega[0], Omega[1], Omega[2], dx, x0, xe);

	std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::printf("Generated values\n");

	//std::cout << std::setprecision(10);

	//std::vector<double> Output_Time = maths->Generate_Half_open_interval(dx, x0, xe);

	//for (int i = 0; i < Out_x.size(); i++)
	//{
	//	for (int j = 0; j < Out_x[i].size(); j++)
	//	{
	//		std::cout << Out_x[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < Out_y.size(); i++)
	//{
	//	for (int j = 0; j < Out_y[i].size(); j++)
	//	{
	//		std::cout << Out_y[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < Out_z.size(); i++)
	//{
	//	for (int j = 0; j < Out_z[i].size(); j++)
	//	{
	//		std::cout << Out_z[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << "Omega X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_x[0].size(); i++)
	{
		my_file << Out_x[0][i] << ",";
		my_file << Out_x[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Omega Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_y[0].size(); i++)
	{
		my_file << Out_y[0][i] << ",";
		my_file << Out_y[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Omega Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_z[0].size(); i++)
	{
		my_file << Out_z[0][i] << ",";
		my_file << Out_z[1][i] << std::endl;
	}

	my_file.close();

	Out_x[0].empty();
	Out_x[1].empty();

	Out_y[0].empty();
	Out_y[1].empty();

	Out_z[0].empty();
	Out_z[1].empty();

	//maths = nullptr;
	//delete maths;

	task_ = nullptr;
	delete task_;
}

void Task_4(double x0, double xe, double dx, std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_position)
{
	Task_3_and_4* task_;
	task_ = new Task_3_and_4();

	//std::array<double, 3> Initial_velocity = { 0,0,200 };
	//std::array<double, 3> Initial_position = { 0,0,0 };

	std::vector<std::vector<double>> Out_vx;
	std::vector<std::vector<double>> Out_vy;
	std::vector<std::vector<double>> Out_vz;

	std::vector<std::vector<double>> Out_px;
	std::vector<std::vector<double>> Out_py;
	std::vector<std::vector<double>> Out_pz;

	//task_.Init(Initial_velocity,Initial_position);
	task_->Solve_Task_3(Initial_velocity, Initial_position,Out_vx,Out_vy,Out_vz,Out_px,Out_py,Out_pz,dx,x0,xe);


	//std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::cout << std::setprecision(10);

	//std::vector<double> Output_Vx = maths->Generate_zeros(xe, dx);
	//std::vector<double> Output_Vy = maths->Generate_zeros(xe, dx);
	//std::vector<double> Output_Vz = maths->Generate_zeros(xe, dx);

	//std::vector<double> Output_Px = maths->Generate_zeros(xe, dx);
	//std::vector<double> Output_Py = maths->Generate_zeros(xe, dx);
	//std::vector<double> Output_Pz = maths->Generate_zeros(xe, dx);

	//std::vector<double> Output_Time = maths->Generate_Half_open_interval(dx, x0, xe);

	//FUCKING IVEISCERATE THIS WRITING AND PRINTING PLEASE!!!!

	//std::printf("Velocity X\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_vx.size(); i++)
	//{
	//	for (int j = 0; j < Out_vx[i].size(); j++)
	//	{
	//		std::cout << Out_vx[i][j] << " ";

	//		if (i == 0)
	//			Output_Vx[j] = Out_vx[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;
	//std::printf("Velocity Y\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_vy.size(); i++)
	//{
	//	for (int j = 0; j < Out_vy[i].size(); j++)
	//	{
	//		std::cout << Out_vy[i][j] << " ";

	//		if (i == 0)
	//			Output_Vy[j] = Out_vy[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;
	//std::printf("Velocity Z\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_vz.size(); i++)
	//{
	//	for (int j = 0; j < Out_vz[i].size(); j++)
	//	{
	//		std::cout << Out_vz[i][j] << " ";

	//		if (i == 0)
	//			Output_Vz[j] = Out_vz[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;
	//std::printf("Displacement X\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_px.size(); i++)
	//{
	//	for (int j = 0; j < Out_px[i].size(); j++)
	//	{
	//		std::cout << Out_px[i][j] << " ";

	//		if (i == 0)
	//			Output_Px[j] = Out_px[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;
	//std::printf("Displacement Y\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_py.size(); i++)
	//{
	//	for (int j = 0; j < Out_py[i].size(); j++)
	//	{
	//		std::cout << Out_py[i][j] << " ";

	//		if (i == 0)
	//			Output_Py[j] = Out_py[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;
	//std::printf("Displacement Z\n");
	//std::cout << std::endl;

	//for (int i = 0; i < Out_pz.size(); i++)
	//{
	//	for (int j = 0; j < Out_pz[i].size(); j++)
	//	{
	//		std::cout << Out_pz[i][j] << " ";

	//		if (i == 0)
	//			Output_Pz[j] = Out_pz[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;


	std::printf("Generated values\n");

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << "Velocity X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_vx[0].size(); i++)
	{
		my_file << Out_vx[0][i] << ",";
		my_file << Out_vx[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Velocity Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_vy[0].size(); i++)
	{
		my_file << Out_vy[0][i] << ",";
		my_file << Out_vy[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Velocity Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_vz[0].size(); i++)
	{
		my_file << Out_vz[0][i] << ",";
		my_file << Out_vz[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_px[0].size(); i++)
	{
		my_file << Out_px[0][i] << ",";
		my_file << Out_px[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_py[0].size(); i++)
	{
		my_file << Out_py[0][i] << ",";
		my_file << Out_py[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Out_pz[0].size(); i++)
	{
		my_file << Out_pz[0][i] << ",";
		my_file << Out_pz[1][i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file.close();

	task_ = nullptr;
	delete task_;
}

void Task_5_(double x0, double xe, double dx, std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_Com_position, std::array<double, 3> Initial_position_, double Omega[3], double M, double R, double H)
{
	//Runge_Kutta r;
	Task_1_and_2* task_1;
	Task_3_and_4* task_2;
	Task_5* task_3;
	//math_library* maths;

	//maths = new math_library();

	task_1 = new Task_1_and_2();
	task_2 = new Task_3_and_4();
	task_3 = new Task_5;

	//double y0 = 0.0,
	//	x0 = 0.0,
	//	xe = 20.0/*5.0*/,
	//	dx = 0.1;/*1.0*/;

	//double M = 10;
	//double R = 1;
	//double H = 4;

	//double Omega_0x = 3, Omega_0y = 1, Omega_0z = 2;

	std::vector<std::vector<double>> Out_Omx;
	std::vector<std::vector<double>> Out_Omy;
	std::vector<std::vector<double>> Out_Omz;

	//std::array<double, 3> Initial_velocity = { 0,0,200 };
	//std::array<double, 3> Initial_position = { 0,0,0 };
	//Will need to give this to Task 5
	//std::array<double, 3> Initial_position_2 = { 0,(3*R)/4,0 };

	std::vector<std::vector<double>> Out_vx;
	std::vector<std::vector<double>> Out_vy;
	std::vector<std::vector<double>> Out_vz;

	std::vector<std::vector<double>> Out_px;
	std::vector<std::vector<double>> Out_py;
	std::vector<std::vector<double>> Out_pz;

	std::array<std::vector<double>, 3> Final_Out;

	task_1->Init(M, R, H);
	task_1->Solve_Task_1(Out_Omx, Out_Omy, Out_Omz, Omega[0], Omega[1], Omega[2], dx, x0, xe);
	task_2->Solve_Task_3(Initial_velocity, Initial_Com_position, Out_vx, Out_vy, Out_vz, Out_px, Out_py, Out_pz, dx, x0, xe);
	//Something seems off with the omega values
	task_3->Solve_Task_5(Out_Omx, Out_Omy, Out_Omz, Out_px, Out_py, Out_pz, Out_vx, Out_vy, Out_vz,dx,x0,xe, Final_Out,Initial_position_);

	//std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::cout << std::setprecision(10);

	std::vector<double> Output_Px = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Py = maths->Generate_zeros(xe, dx);
	std::vector<double> Output_Pz = maths->Generate_zeros(xe, dx);

	std::vector<double> Output_Time = maths->Generate_Half_open_interval(dx, x0, xe);


	std::printf("Displacement X\n");
	std::cout << std::endl;

	for (int i = 0; i < Final_Out[0].size(); i++)
	{
		std::cout << Final_Out[0].at(i) << " ";
		Output_Px[i] = Final_Out[0].at(i);

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Displacement Y\n");
	std::cout << std::endl;

	for (int i = 0; i < Final_Out[1].size(); i++)
	{
		std::cout << Final_Out[1].at(i) << " ";
		Output_Py[i] = Final_Out[1].at(i);

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::printf("Displacement Z\n");
	std::cout << std::endl;

	for (int i = 0; i < Final_Out[2].size(); i++)
	{
		std::cout << Final_Out[2].at(i) << " ";
		Output_Pz[i] = Final_Out[2].at(i);

		std::cout << std::endl;
	}

	std::cout << std::endl;


	std::printf("Generated values\n");

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

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

	//maths = nullptr;
	//delete maths;

	task_1 = nullptr;
	delete task_1;

	task_2 = nullptr;
	delete task_2;

	task_3 = nullptr;
	delete task_3;

}

int main()
{
	//FUCKING IVEISCERATE THIS WRITING AND PRINTING PLEASE!!!!

	maths = new math_library();

	double x0 = 0.0,
	xe = 20.0,
	dx = 0.1;;


	//Task 1 and 2

	double M = 10;
	double R = 1;
	double H = 4;

	//double Omega_0x = 3, Omega_0y = 1, Omega_0z = 2;
	double Omega[3] = { 3,1,2 };

	//Task_2(x0,xe,dx,M,R,H,Omega);

	//Task 3 and 4

	std::array<double, 3> Initial_velocity = { 0,0,200 };
	std::array<double, 3> Initial_Com_position = { 0,0,0 };

	//Task_4(x0,xe,dx, Initial_velocity, Initial_Com_position);

	Task_5_();

	maths = nullptr;
	delete maths;

	return 0;
}