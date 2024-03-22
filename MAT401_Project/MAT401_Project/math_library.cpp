#include "math_library.h"
#include <iostream>
math_library::math_library()
{
}

math_library::~math_library()
{
}

std::vector<double> math_library::Generate_Half_open_interval(double step, double start, double end)
{
	std::vector<double> output;
	for (float i = start; i < end+step; i+=step)
	{
		////std::cout << "Generating values :" << i << "\n";
		output.push_back(i);
	}
	return output;
}

//Need to fix this so it works based of the step size and so on
std::vector<double> math_library::Generate_zeros(double length)
{
	std::vector<double> output;
	for (float i = 1; i <= length; i++)
	{
		//std::cout << "Generating values :" << i << "\n";
		output.push_back(0);
	}
	//std::printf("Done\n");
	return output;
}

std::vector<std::vector<double>> math_library::Matrix_multiplication(std::vector<std::vector<double>>& Matrix_1, std::array<std::array<double, 3>, 3>& Matrix_2, int R1,int C1, int R2,int C2)
{

	std::vector<std::vector<double>> rslt;
	std::vector<double> rslt_1 = Generate_zeros(R1);
	std::vector<double> rslt_2 = Generate_zeros(C2);

	rslt = { rslt_1,rslt_2 };

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += Matrix_1[i][k] * Matrix_2[k][j];
			}
		}
	}

	return rslt;

	//    int rslt[R1][C2];

	/*    int mat1[R1][C1] = { { 1, 1 }, { 2, 2 } };
 
		  int mat2[R2][C2] = { { 1, 1, 1 }, { 2, 2, 2 } };*/



	/*    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
 
            cout << rslt[i][j] << "\t";
        }
 
        cout << endl;
    }*/


	/*int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	  int matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	  int results[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			for (int u = 0; u < 3; u++)
				results[i][j] += matrix1[i][u] * matrix2[u][j];
		}
	*/
}