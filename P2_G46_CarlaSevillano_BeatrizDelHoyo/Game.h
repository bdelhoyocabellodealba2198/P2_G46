#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include "Hashoverload.h"
#pragma once

class Game {
public:
	
	//Constructor
	Game();

	//destructor
	~Game();

	
	//Funciones
	void AddBasics(void); //Añade los 4 elementos basicos a la lista del Player
	void Add(int elementIndex); //Añade la copia de uno de los elementos ya existentes en la lista Player
	void Help(void); //Imprime la información del juego 
	void Sort(void); //Ordena los elementos alfabeticamente de la lista Player
	void Delete(int elementIndex); //Eliminamos un elemento concreto de la lista Player
	void Clean(void); //Elimina los elementos que esten repetidos en la lista Player
	void PrintElements(void); //Imprime la lista del Player
	void CombineElement(int elementIndex1, int elementIndex2);
	void Info(int elementIndex);

private:
	int score;
	std::unordered_map<std::pair<std::string, std::string>, std::string> u_Map;
	std::vector<std::string>PlayerVector;


	


};