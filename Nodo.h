#include <list>

using namespace std;

template <class T,class V>
class Edge;

template <class T,class V>
class Nodo
{
public:
	Nodo(T dato){
		m_dato = dato;
	}

	T m_dato;
	list<Edge<T,V > * >  m_aristas;
};

template <class T,class V>
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
