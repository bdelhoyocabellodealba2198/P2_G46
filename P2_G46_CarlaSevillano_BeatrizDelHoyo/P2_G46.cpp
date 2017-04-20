#include <iostream>
#include <fstream>
#include <string>





int main()
{
	int counter = 0;
	char aux[100];
	std::string element {"hola"};
	std::ifstream f_entrada_elements("elements.dat");

	std::cout << element << std::endl;
	char line[400];

	while (f_entrada_elements.getline(line, 400))
	{
		do
		{
			aux[counter] = line[counter];
			counter++;
		} while (line[counter] != '=');
		aux[counter] = '\0';
		
		element = "hola";
		
	};	f_entrada_elements.close();
	return 0;
}