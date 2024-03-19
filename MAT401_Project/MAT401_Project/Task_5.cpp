#include "Task_5.h"

Task_5::Task_5()
{

}

Task_5::~Task_5()
{

}

//Will need to fill this out but I can do that later I just need to make sure I get the basics correct first

void Task_5::Set_rotation_matrix(double alpha, double beta, double gamma, double theta)
{
	Rotation_Matrix = { (pow(alpha,2))*(1 - cos(theta)) + cos(theta),	0,	0,
					    0,	0,	0,
					    0,	0,  0 };
}

void Task_5::Solve_Task_5()
{
	//omega = {alpha,beta,gamma}

	//Before any of this will need to use Task 1 and 3 for those values

	//1. Centre of mass position at time step point Courtesy of task 3

	//2. Theta value = maginitude of omega * the timestep point omega courtesy of task 1.

	//3.alpha beta and gamma are equal to the omega values(x,y,z) each divided by the magnitude for a unit vector

	//4. Rotation matrix * alpha ,beta and gamma vector
}