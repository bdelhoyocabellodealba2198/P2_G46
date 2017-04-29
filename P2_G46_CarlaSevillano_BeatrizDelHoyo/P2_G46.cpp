#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>


int main()
{
	//Variables
	int posOfEqual; // "="
	int posOfPlus;  // "+"

	std::string linea; 
	std::string str_value; 
	std::string str_key1;
	std::string str_key2;

	//std::unordered_map<std::pair<std::string, std::string>, std::string> u_Map;

	//Obrir arxiu i copiar les keys i el value en un unordered map
	std::ifstream f_entrada_elements("elements.dat");
	
	while (getline(f_entrada_elements,linea))
	{

		posOfEqual = linea.find("=");
		str_value = linea.substr(0, (posOfEqual - 1));
		
		posOfPlus = linea.find("+");
		str_key1 = linea.substr(posOfEqual+2, (posOfPlus-1 - posOfEqual+2)-4);

		str_key2 = linea.substr(posOfPlus+2);

		std::cout <<"value:"<< str_value << " " << "key1:"<< str_key1 << " " << "key2:"<< str_key2 << " " << std::endl;

		//u_Map.insert({ { str_key1,str_key2 }, { str_value } });

	}

	f_entrada_elements.close();

	return 0;
}