#include "Task_1_and_2.h"

Task_1_and_2::Task_1_and_2()
{

}

Task_1_and_2::~Task_1_and_2()
{

}

void Task_1_and_2::Init(float M,float R, float H)
{
	//Inertia_Tensor = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };

	float u = (3 * M) / 20.0f;

	float xx_yy = pow(R, 2) + (pow(H, 2) / 4.0f);

	xx_yy *= u;

	float zz = 2 * R;
	zz *= u;

	Inertia_Tensor = {xx_yy,	0,	0,
					  0,	xx_yy,	0,
					  0,	0,		zz};

	Centre_of_mass = { 0,0,0 };

	Upsilon[0] = (zz - xx_yy) / xx_yy;
	Upsilon[1] = (xx_yy - zz) / xx_yy;
	Upsilon[2] = (xx_yy - xx_yy) / zz;
}