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
	void prints();
	void addEdge(T,T,V);
	Nodo<T,V> * find(T b){
		typename list<Nodo<T,V> >::iterator it = m_nodos.begin();
		
		for(;it!=m_nodos.end();++it){
			if(it->m_dato == b){
				return &(*it);
			}
		}
		return 0;
	}
};

template <class T,class V>
void Grafo<T,V>::addNodo(T dato){
	m_nodos.push_back(Nodo<T,V>(dato));
}


template <class T,class V>
void Grafo<T,V>::addEdge(T a,T b,V peso){
	Nodo<T,V> * p = find(a);
	Nodo<T,V> * q = find(b);

	Edge<T,V> * nuevo = new Edge<T,V>(peso,q);
	p->m_aristas.push_back(nuevo);

}





template <class T,class V>
void Grafo<T,V>::prints(){
	typename std::list<Nodo<T,V> >::iterator it;
	
	for ( it = m_nodos.begin();it!=m_nodos.end();++it){
		cout << (*it).m_dato << "( ";

		if((*it).m_aristas.size() != 0){
			typename list<Edge<T,V >* >::iterator it_ar = (*it).m_aristas.begin();
			
			
			for(;it_ar!=((*it).m_aristas).end();++it_ar){
				cout << ((*it_ar)->m_pdestino->m_dato)<< ",";
			}
		}
			cout << " )";

	}
}






