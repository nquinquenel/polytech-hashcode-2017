#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include "Point.h"
#include "ProblemData.h"
#include "Object.h"
#include "Graph.h"

using namespace std;

void dump(const char* filename, vector<Point> routers);

void dump(const char* filename, vector<Point> routers) {
	ofstream monFlux(filename);

	if (monFlux) {
		for (auto router : routers) {
			monFlux << router.getCoordX() << " " << router.getCoordY() << endl;
		}
	}
	else {
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}




void parseArgs(int argc)
{
	if (argc != 2) {
		cerr << "Mauvais nombre d'arguments !" << endl;
		exit(-1);
	}
}

int main(int argc, char *argv[])
{
	//parseArgs(argc);
	ProblemData data;
	data.ParseFile("opera.in");
	cout << data(0, 0) << endl;
	cout << "Nombres de points � disposition sur la carte : " << data.calculMaxMoney() << endl;

	vector<Point> routers = data.depotRouter();
	long scoreCellsCovered = data.scoreRouters(routers);

	cout << "On a depose " << routers.size() << " routeurs sur la carte." << endl;
	cout << "Score recuperer pour avoir convert des cellules : " << scoreCellsCovered << endl;

	dump("coordRouters.txt", routers);
	/*Point ptA = Point(0, 1, TARGET);
	Point ptB = Point(5, -10, TARGET);
	vector<Point> liste = ptA.getCablesToB(ptB);
	for (int f = 0; f < liste.size(); f++) {
		cout << liste[f].getCoordX() << " - " << liste[f].getCoordY() << endl;
	}*/
	
	Point backbone(data.getBackboneRow(), data.getBackboneCol(), CABLE);
	Graph cables = Graph(backbone, routers);
	cables.resolve();
	
	vector<Point> listCables = data.getRepartition(routers, cables.parent);
	return 0;
}