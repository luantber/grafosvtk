#include <map>

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
	Nodo(){}

	T m_dato;
	map<T,Edge<T,V > * >  m_aristas;
};
