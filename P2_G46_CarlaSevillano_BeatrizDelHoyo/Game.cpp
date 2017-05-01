#include "Game.h"

Game::Game(){



}

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
	for (auto counter = PlayerVector.begin(); counter != PlayerVector.end(); counter++) {
		std::cout << counter1 << ":" << " " << *counter << std::endl;
		counter1++;
	}
}

void Game::CombineElement(int elementIndex1, int elementIndex2)
{

}
