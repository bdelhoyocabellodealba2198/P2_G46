#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

template<>
struct std::hash<std::pair<std::string, std::string>> {
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{
		return((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
	}
};

void Add(int accesValue) {


	 
}


int main()
{
	//Variables
	int posOfEqual; // "="
	int posOfPlus;  // "+"

	std::string linea;
	std::string str_value;
	std::string str_key1;
	std::string str_key2;

	std::unordered_map<std::pair<std::string, std::string>, std::string> u_Map;

	std::vector<std::string>PlayerVector({ "Earth", "Fire ", "Air", "Water" });

	//Obrir arxiu i copiar les keys i el value en un unordered map
	std::ifstream f_entrada_elements("elements.dat");

	while (getline(f_entrada_elements, linea))
	{

		posOfEqual = linea.find("=");
		str_value = linea.substr(0, (posOfEqual - 1));

		posOfPlus = linea.find("+");
		str_key1 = linea.substr(posOfEqual + 2, (posOfPlus - 1 - posOfEqual + 2) - 4);

		str_key2 = linea.substr(posOfPlus + 2);

		//std::cout <<"value:"<< str_value << " " << "key1:"<< str_key1 << " " << "key2:"<< str_key2 << " " << std::endl;

		u_Map.insert({ { str_key1,str_key2 }, { str_value } });

	}

	f_entrada_elements.close();

	int couter = 1;

	//Imprimimos los 4 elementos basicos por pantalla
	for (auto &it : PlayerVector) {

		std::cout << couter << ":" << it << std::endl;
		couter++;
	}


	int number;
	int number2;
	bool elementFind = false;

	std::cin >> number>> number2;
	

	std::string key1 = PlayerVector[number-1];
	std::string key2 = PlayerVector[number2-1];


	auto it = u_Map.find(std::pair<std::string, std::string>{key1, key2});

	if (it != u_Map.end()) {
		PlayerVector.push_back(u_Map[std::pair<std::string, std::string>{key1, key2}]);
		
		std::cout << " El nuevo elemento es:"<<" "<< u_Map[std::pair<std::string, std::string>{key1, key2}];
	} 
	else {
		std::cout << "No existe";
	}
		
	std::string function;
	int accesValue;
	std::cin >> function >> accesValue;
	std::string Element = PlayerVector[accesValue-1];
	
	if (function == "Add") {
		std::vector<int>::iterator it;
		for (auto it = PlayerVector.begin(); it != PlayerVector.end(); it++) {

			if (*it == Element) { //comprovamso que existe en nuestro vector
				
				PlayerVector.push_back(Element);
			}
		}
	}
	else if (function == "Add basics") { //Añadimos los 4 elementos basicos a la lista del jugador
		PlayerVector.push_back("Air");
		PlayerVector.push_back("Earth");
		PlayerVector.push_back("Fire");
		PlayerVector.push_back("Water");
	}
	else if(function == "Info"){

	}
	else if (function =="delete") {
		for (auto it = PlayerVector.begin(); it != PlayerVector.end(); it++) {

			if (*it == Element) { //comprovamso que existe en nuestro vector

				PlayerVector.erase(it); //eliminamos el elemento
			}
			else {
				std::cout << "This element it's not in the PlayerList" << std::endl;
			}
		}

	}
	else if (function =="sort") { //ordenamos el vector

		std::sort(PlayerVector.begin(), PlayerVector.begin() + 4);

	}
	else if (function =="clean") { //se elmiminan todos los elementos repetidos en la lista


	}
	else if (function =="help") { //se muestra un tutorial con todas las acciones que puede hacer el usuario
		
	}

	return 0;
}