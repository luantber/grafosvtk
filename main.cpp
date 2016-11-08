#include <iostream>
#include "Grafo.h"

using namespace std;
int main(){

	Grafo<int,int> g;

	for(int i=0;i<10;++i){
		g.addNodo(i);
	}
	
	//cout << g.find(7)->m_dato ;
	g.addEdge(3,7,10);
	g.addEdge(3,4,10);
	g.prints();
	cout	<< "hola"<<endl;



	return 0;
}