#include "Task_3_and_4.h"

Task_3_and_4::Task_3_and_4()
{
	maths_ = new math_library();
}

Task_3_and_4::~Task_3_and_4()
{
	maths_->~math_library();
	maths_ = nullptr;
	delete maths_;
}

void Task_3_and_4::Init(std::array<float, 3> Initial_velocity, std::array<float, 3> Initial_position)
{
	velocity[0] = Initial_velocity[0];
	velocity[1] = Initial_velocity[1];
	velocity[2] = Initial_velocity[2];

	position[0] = Initial_position[0];
	position[1] = Initial_position[1];
	position[2] = Initial_position[2];
}

//Do the same kind of setup as task_1 but use the semi-implicit euler method instead of runga-kutta