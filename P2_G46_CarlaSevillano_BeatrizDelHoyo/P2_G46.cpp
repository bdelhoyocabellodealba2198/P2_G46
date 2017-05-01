
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
		system("cls");
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
		
		else if (userInput.substr(0, userInput.find(' ')) == "add" && IsNumber(userInput.substr(userInput.find(' ') + 1)) && userInput.substr(userInput.find(' ') + 1)!= "0")
		{
			myGame.Add(stoi(userInput.substr(userInput.find(' ') + 1)));
		}
		
		else if (userInput.substr(0, userInput.find(' ')) == "delete" && IsNumber(userInput.substr(userInput.find(' ') + 1)) && userInput.substr(userInput.find(' ') + 1) != "0")
		{
			myGame.Delete(stoi(userInput.substr(userInput.find(' ') + 1)));
		}
			
		else if (IsNumber(userInput.substr(0, userInput.find(' '))) && IsNumber(userInput.substr(userInput.find(' ') + 1)) && userInput.substr(0, userInput.find(' '))!="0" && userInput.substr(userInput.find(' ') + 1)!="0" && userInput.size()>=3) {
			myGame.CombineElement(stoi(userInput.substr(0, userInput.find(' '))), stoi(userInput.substr(userInput.find(' ') + 1)));
		}

		else if (userInput.substr(0, userInput.find(' ')) == "info" && IsNumber(userInput.substr(userInput.find(' ') + 1)) && userInput.substr(userInput.find(' ') + 1) != "0")
		{
			myGame.Info(stoi(userInput.substr(userInput.find(' ') + 1)));
		}

	}while (userInput!= "ESC");

	return 0;
}
