#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Point.h"
#include "ProblemData.h"
#include "Object.h"




void parseArgs(int argc)
{
	if (argc != 3) {
		std::cerr << "Mauvais nombre d'arguments !" << std::endl;
		exit(-1);
	}
}

int main(int argc, char *argv[])
{

	//A titre de debug pour le moment
	const char *input;
	const char *output;
	if (argc == 3) {
		input = argv[1];
		output = argv[2];
	}
	else {
		input = "lets_go_higher.in"; //lets_go_higher, rue_de_londres, opera
		output = "..//Output//higher67b.out";
	}

	//parseArgs(argc);
	ProblemData data;
	const char* filename(input);
	data.ParseFile(filename);

	//Pour pas pourrir les performances vis � vis de l'arbitre
#ifdef DEBUG
	std::cout << data(0, 0) << std::endl;
	std::cout << "Nombres de points � disposition sur la carte : " << data.calculMaxMoney() << std::endl;
#endif 
	
	std::cout << "Debut du depot des routeurs" << std::endl;
	data.depotRouter();
	long scoreCellsCovered = data.scoreRouters();

#ifdef DEBUG
	std::cout << "On a depose " << data.getNbRouters() << " routeurs sur la carte." << std::endl;
	std::cout << "Score recuperer pour avoir convert des cellules : " << scoreCellsCovered << std::endl;
#endif 

	data.dumpInFile(output);
	return 0;
}