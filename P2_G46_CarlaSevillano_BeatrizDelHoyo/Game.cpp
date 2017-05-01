#include "Game.h"


Game::Game():score{0} //Constructor
{ 

	//Variables
	
	int posOfEqual; // "="
	int posOfPlus;  // "+"

	std::string linea;
	std::string str_value;
	std::string str_key1;
	std::string str_key2;
	std::ifstream f_entrada_elements("elements.dat"); //Lectura del fichero
	
	while (getline(f_entrada_elements, linea))
	{

		posOfEqual = linea.find("=");
		str_value = linea.substr(0, (posOfEqual - 1));

		posOfPlus = linea.find("+");
		str_key1 = linea.substr(posOfEqual + 2, (posOfPlus - 1) - (posOfEqual + 2));

		str_key2 = linea.substr(posOfPlus + 2);



		u_Map.insert({ { str_key1,str_key2 },{ str_value } });

		//std::cout << "value:" << str_value << " " << "key1:" << str_key1 << " " << "key2:" << str_key2 << " " << std::endl;

	}
	AddBasics();

}

Game::~Game() {}

void Game::AddBasics(void)
{
	PlayerVector.push_back("Air");
	PlayerVector.push_back("Earth");
	PlayerVector.push_back("Fire");
	PlayerVector.push_back("Water");
	
}

void Game::Add(int elementIndex)
{
	if (elementIndex-1<PlayerVector.size())
	{
		PlayerVector.push_back(PlayerVector[elementIndex-1]);

	}
}

void Game::Help(void)
{
	std::cout << std::endl << std::endl;
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element  to add a new instance of that element." << std::endl;
	std::cout << "- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	std::cout << "- Enter the word 'exit' to leave the game." << std::endl << std::endl;
	std::cout << "\nYour current score: " << std::endl;
	std::cout << "You have this elements:" << std::endl;
}

void Game::Sort(void)
{
	sort(PlayerVector.begin(),PlayerVector.end()); 
}

void Game::Delete(int elementIndex)
{
	if (elementIndex-1<PlayerVector.size()) 
	{
		PlayerVector.erase(PlayerVector.begin()+(elementIndex-1));
	}
}

void Game::Clean(void)
{
	std::set<std::string>playerSeta(PlayerVector.begin(), PlayerVector.end());
	PlayerVector.assign(playerSeta.begin(), playerSeta.end());
}

void Game::PrintElements(void)
{
	int counter1{ 1 };
	for (auto counter = PlayerVector.begin(); counter != PlayerVector.end(); counter++) 
	{
		std::cout << counter1 << ":" << " " << *counter << std::endl;
		counter1++;
	}
}

void Game::CombineElement(int elementIndex1, int elementIndex2)
{
	if (elementIndex1 < PlayerVector.size() && elementIndex2 < PlayerVector.size()) {
		if (elementIndex1 != elementIndex2) {

			std::string key1 = PlayerVector[elementIndex1 - 1];
			std::string key2 = PlayerVector[elementIndex2 - 1];

			auto it1 = u_Map.find({ key1,key2 });
			auto it2 = u_Map.find({ key2,key1 });
			bool finded{ false };
			auto it = it1;
			if (it1 != u_Map.end())
			{

				finded = true;
			}
			else if (it2 != u_Map.end()) {

				it = it2;
				finded = true;

			}
			if (finded) {

				if (find(AuxVector.begin(), AuxVector.end(), it->second) == AuxVector.end()) {
					std::cout << "New element found:" << it->second << std::endl;
					score++;
					AuxVector.push_back(it->second);
				}
				PlayerVector.push_back(it->second);


			}
		}
		else {
			std::cout << "You can't combine the same element!" << std::endl;
		}
	}


}

int Game::GetPoits() {
	return score;
}

void Game::Info(int elementIndex)
{

}
