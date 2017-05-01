
#include "Game.h"


bool IsNumber(std::string substring)
{
	int posOfEndl;
	posOfEndl = substring.find('\0');
	for (int i = 0; i < posOfEndl; i++) 
	{
		if (!isdigit(substring[i]))
		{
			return false;
		}
		return true;
	}

}

int main()
{

	Game myGame;

	myGame.Help();
	std::string userInput;
	do {

		myGame.PrintElements();
		getline(std::cin, userInput);

		if (userInput == "help")
		{
			myGame.Help();
		}
		else if (userInput == "add basics")
		{
			myGame.AddBasics();
		}
		else if (userInput == "sort")
		{
			myGame.Sort();
		}
		else if (userInput == "clean")
		{
			myGame.Clean();
		}
		else if (userInput == "info")
		{
			//myGame.Info();
		}
		else if (userInput.substr(0, userInput.find(' ') - 1) == "add" && IsNumber(userInput.substr(userInput.find(' ') + 1)))
		{


			myGame.Add(stoi(userInput.substr(userInput.find(' ') + 1)));
		}

	

	}while (userInput!= "ESC");

	return 0;
}
