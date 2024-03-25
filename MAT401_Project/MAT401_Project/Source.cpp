
#include <iostream>
#include <iomanip>
#include <fstream>

#include <variant>
#include <cassert>


#include "Runge_Kutta.h"
#include "Task_1_and_2.h"
#include "Task_3_and_4.h"
#include "Task_5.h"

#include "Printer.h"

math_library* maths;
Printer* print_;

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

	print_->Write_to_file(Out_x[0],std::string("Omega X"), Out_y[0], std::string("Omega Y"), Out_z[0], std::string("Omega Z"),Out_x[1]);

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

	print_->Write_to_file(Out_vx[0], std::string("Velocity X"), Out_vy[0], std::string("Velocity Y"), Out_vz[0], std::string("Velocity Z"), Out_px[0], std::string("Diplacement X"), Out_py[0], std::string("Diplacement Y"), Out_pz[0], std::string("Diplacement Z"), Out_vx[1]);

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

	std::printf("Generated values\n");

	print_->Write_to_file(Final_Out[0], std::string("Diplacement X"), Final_Out[1], std::string("Diplacement Y"), Final_Out[2], std::string("Diplacement Z"), Out_Omx[1]);

	task_1 = nullptr;
	delete task_1;

	task_2 = nullptr;
	delete task_2;

	task_3 = nullptr;
	delete task_3;

}

int main()
{

	maths = new math_library();
	print_ = new Printer();

	double x0 = 0.0,
	xe = 20.0,
	dx = 0.1;


	//Task 1 and 2

	double M = 10;
	double R = 1;
	double H = 4;

	double Omega[3] = { 3,1,2 };

	//Task 3 and 4

	std::array<double, 3> Initial_velocity = { 0,0,200 };
	std::array<double, 3> Initial_Com_position = { 0,0,0 };
	std::array<double, 3> Initial_position_ = { 0,(3*R)/4,0 };

	int input;
	bool Setup = false;

	std::cout << "Which Task would you like to solve : ";
	std::cin >> input;

	while (!Setup)
	{

		if (input > 0 && input < 6)
		{
			Setup = true;
		}
		else
		{
			std::cout << "Please re-enter a task between 1 and 5 Task would you like to solve : ";
			std::cin >> input;
		}
	}

	switch (input)
	{
	case 1:
		Task_2(x0, xe, dx, M, R, H, Omega);
		break;
	case 2:
		Task_2(x0, xe, dx, M, R, H, Omega);
		break;
	case 3:
		Task_4(x0, xe, dx, Initial_velocity, Initial_Com_position);
		break;
	case 4:
		Task_4(x0, xe, dx, Initial_velocity, Initial_Com_position);
		break;
	case 5:
		Task_5_(x0, xe, dx, Initial_velocity, Initial_Com_position, Initial_position_, Omega, M, R, H);
		break;
	}

	//Task_2(x0, xe, dx, M, R, H, Omega);

	//Task_4(x0,xe,dx, Initial_velocity, Initial_Com_position);

	//Task_5_(x0,xe,dx,Initial_velocity,Initial_Com_position,Initial_position_,Omega,M,R,H);

	maths = nullptr;
	delete maths;

	print_ = nullptr;
	delete print_;

	return 0;
}