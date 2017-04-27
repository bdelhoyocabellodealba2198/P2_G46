#include <iostream>
#include <fstream>
#include <string>


int main()
{
	int posOfEqual;
	char arra_value[100];
	

	std::string linea;
	std::string str_value;
	std::ifstream f_entrada_elements("elements.dat");


	while (getline(f_entrada_elements,linea))
	{
		posOfEqual = linea.find("=");
		str_value = linea.substr(0, (posOfEqual - 1));

		posOfEqual = linea.find("+");
		str_value = linea.substr((posOfEqual - 1), (posOfEqual - 1));
	}

	f_entrada_elements.close();

	return 0;
}