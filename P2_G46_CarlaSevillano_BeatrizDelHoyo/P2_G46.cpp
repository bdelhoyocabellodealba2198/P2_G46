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

void Add(std::vector<std::string> PlayerVector, int accesValue) {

	int counter = 0;
	std::string Element = PlayerVector[accesValue - 1];
	auto it = find(PlayerVector.begin(),PlayerVector.end(),Element);


		if (it == Element) //comprovamso que existe en nuestro vector
		{

			PlayerVector.insert(PlayerVector.begin(), Element);
			std::cout << "You've add the element:" << Element;
			for (auto &it : PlayerVector)
			{

				std::cout << counter << ":" << it << std::endl;
				counter++;
			}
	}
}
	void AddBasics(std::vector<std::string> PlayerVector) //Añadimos los 4 elementos basicos a la lista del jugador
	{
		int counter = 0;
		PlayerVector.insert(PlayerVector.begin(), "Air");
		PlayerVector.insert(PlayerVector.begin(), "Earth");
		PlayerVector.insert(PlayerVector.begin(), "Fire");
	PlayerVector.insert(PlayerVector.begin(), "Water");

		for (auto &it : PlayerVector)
		{

			std::cout << counter << ":" << it << std::endl;
			counter++;

		}

	 
}

	void Delete(std::vector < std::string >PlayerVector, int accesValue ) {
		std::string Element = PlayerVector[accesValue - 1];
		for (auto it = PlayerVector.begin(); it != PlayerVector.end(); it++)
		{

			if (*it == Element) { //comprovamso que existe en nuestro vector

				PlayerVector.erase(it); //eliminamos el elemento
			}
			else
			{
				std::cout << "This element it's not in the PlayerList" << std::endl;
			}
		}
	}

	void Help() {
		std::cout << "-Enter to numbers of the element list to combine them." << std::endl;
		std::cout << "-Enter the word 'Add' and the number of an element to add a new instance of that element" << std::endl;
		std::cout << "-Enter 'Add basics' to add new instance of the 4 basic elements" << std::endl;
		std::cout << "-Enter the word 'delete'and the number of an element to erase it from your list" << std::endl;
		std::cout << "-Enter the word 'info'and the number of an element to get information about it in the explorer" << std::endl;
		std::cout << "-Enter the word 'sort' to scort by alphabetical order the element in the list" << std::endl;
		std::cout << "-Enter the word 'clean' to delete all the instances of repeated elements" << std::endl;
		std::cout << "-Enter the word 'help' to show this tutorial" << std::endl;
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
	

	std::cin >> number >> number2;


	std::string key1 = PlayerVector[number - 1];
	std::string key2 = PlayerVector[number2 - 1];


	auto it = u_Map.find(std::pair<std::string, std::string>{key1, key2});
	std::vector<int>::iterator it2;

	if(number != number2)
	{
		if (it != u_Map.end()) {

			std::string elementInMap = u_Map[std::pair<std::string, std::string>{key1, key2}];

			PlayerVector.push_back(elementInMap);
			std::cout << " new element found:" << " " << elementInMap;

			for (auto &it : PlayerVector) {

				std::cout << couter << ":" << it << std::endl;
				couter++;

			}
			system("pause");
		}
	}
	else {
		
		std::cout << "You can't combine the same element!!" << std::endl;
		system("pause");
	}
	
	std::string function;
	int accesValue;
	std::cin >> function >> accesValue;
	

	if (function == "Add") {

		Add(PlayerVector, accesValue);
		
	}
	else if (function == "Add basics")//Añadimos los 4 elementos basicos a la lista del jugador
			{
				AddBasics(PlayerVector);
		
			}
   else if (function == "Info")
			{

			}
   else if (function == "delete")
		{

		   Delete(PlayerVector, accesValue);

		}
   else if (function == "sort") //ordenamos el vector

	   {

		   std::sort(PlayerVector.begin(), PlayerVector.end());
	   }
   
   else if (function == "clean") //se elmiminan todos los elementos repetidos en la lista
			
		{

    	}
   else if (function == "help")//se muestra un tutorial con todas las acciones que puede hacer el usuario
		{
					Help();
		}
		
	std::cin.clear();	std::cin.ignore(std::cin.rdbuf()->in_avail());			return 0;		}
