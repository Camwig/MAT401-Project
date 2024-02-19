
#include <iostream>
#include <fstream>

int main()
{
	std::printf("Hello World\n");

	std::ofstream my_file("test.csv");

	if (my_file.is_open()) {
		my_file << ("Cheese") << "," << ("Bums") <<std::endl;
	}

	my_file.close();
	return 0;
}