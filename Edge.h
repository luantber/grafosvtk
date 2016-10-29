template <class T,class V>
#include "Nodo.h"

class Edge
{
public:
	Edge(V peso,Nodo<T,V> * d){
		m_peso = peso;
		m_pdestino = d;
	}

	V m_peso;
	Nodo<T,V> * m_pdestino;
};