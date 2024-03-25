
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
	Task_1_and_2* task_;

	task_ = new Task_1_and_2();

	std::vector<std::vector<double>> Out_x;
	std::vector<std::vector<double>> Out_y;
	std::vector<std::vector<double>> Out_z;

	task_->Init(M, R, H);
	task_->Solve_Task_1(Out_x, Out_y, Out_z, Omega[0], Omega[1], Omega[2], dx, x0, xe);

	std::variant <std::vector<std::array<double, 3>>, std::vector<double>> Output;

	std::printf("Generated values\n");

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

	task_ = nullptr;
	delete task_;
}

void Task_4(double x0, double xe, double dx, std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_position)
{
	Task_3_and_4* task_;
	task_ = new Task_3_and_4();

	std::vector<std::vector<double>> Out_vx;
	std::vector<std::vector<double>> Out_vy;
	std::vector<std::vector<double>> Out_vz;

	std::vector<std::vector<double>> Out_px;
	std::vector<std::vector<double>> Out_py;
	std::vector<std::vector<double>> Out_pz;

	task_->Solve_Task_3(Initial_velocity, Initial_position,Out_vx,Out_vy,Out_vz,Out_px,Out_py,Out_pz,dx,x0,xe);

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
	Task_1_and_2* task_1;
	Task_3_and_4* task_2;
	Task_5* task_3;

	task_1 = new Task_1_and_2();
	task_2 = new Task_3_and_4();
	task_3 = new Task_5;

	std::vector<std::vector<double>> Out_Omx;
	std::vector<std::vector<double>> Out_Omy;
	std::vector<std::vector<double>> Out_Omz;

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
	task_3->Solve_Task_5(Out_Omx, Out_Omy, Out_Omz, Out_px, Out_py, Out_pz,dx,x0,xe, Final_Out,Initial_position_);

	std::cout << std::setprecision(10);

	std::vector<double> Output_Time = maths->Generate_Half_open_interval(dx, x0, xe);

	std::printf("Generated values\n");

	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << "Diplacement X";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Final_Out[0].size(); i++)
	{
		my_file << Final_Out[0].at(i) << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Y";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Final_Out[1].size(); i++)
	{
		my_file << Final_Out[1].at(i) << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << "Diplacement Z";

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Final_Out[2].size(); i++)
	{
		my_file << Final_Out[2].at(i) << ",";
		my_file << Output_Time[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file.close();

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
	dx = 0.1;


	//Task 1 and 2

	double M = 10;
	double R = 1;
	double H = 4;

	double Omega[3] = { 3,1,2 };

	//Task_2(x0,xe,dx,M,R,H,Omega);

	//Task 3 and 4

	std::array<double, 3> Initial_velocity = { 0,0,200 };
	std::array<double, 3> Initial_Com_position = { 0,0,0 };
	std::array<double, 3> Initial_position_ = { 0,(3*R)/4,0 };

	//Task_4(x0,xe,dx, Initial_velocity, Initial_Com_position);

	Task_5_(x0,xe,dx,Initial_velocity,Initial_Com_position,Initial_position_,Omega,M,R,H);

	maths = nullptr;
	delete maths;

	return 0;
}