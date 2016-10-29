#include "Nodo.h"
#include <list>

using namespace std;

template <class T,class V>
class Grafo
{
public:
	Grafo(){};
	list<Nodo<T,V> > m_nodos;
	void addNodo(T);
	//void find()
};

template <class T,class V>
void Grafo<T,V>::addNodo(T dato){
	m_nodos.push_back(Nodo<T,V>(dato));
}


