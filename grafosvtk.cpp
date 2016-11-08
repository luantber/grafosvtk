#include <iostream>
#include "Grafo.h"

using namespace std;
int main(){



	Grafo<double *,int> g;

	double datos[3] = {1,1,1};
	g.addNodo(datos);
	
	g.prints();


	return 0;
}