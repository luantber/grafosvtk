#include <iostream>
#include "Grafo.h"

using namespace std;
int main(){

	Grafo<int,int> g;

	g.addNodo(3);
	g.addNodo(7);


	cout << g.find(7)->m_dato ;
	g.addEdge(3,7,10);
	g.prints();
	cout	<< "hola"<<endl;



	return 0;
}