#include "Nodo.h"
#include "Edge.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <map>

using namespace std;

template <class T,class V>
class Grafo
{
public:
	Grafo(){};
	map<T,Nodo<T,V> > m_nodos;
	void addNodo(T);
	void prints();
	void addEdge(T,T,V);
	void dijkstra(T);



};



template <class T,class V>
void Grafo<T,V>::addNodo(T dato){
	Nodo<T,V> nuevo(dato);
	m_nodos[dato]= nuevo;
}


template <class T,class V>
void Grafo<T,V>::addEdge(T a,T b,V peso){
  auto p=m_nodos.find(a);
	auto q=m_nodos.find(b);

	Edge<T,V> * nuevo1 = new Edge<T,V>(peso,&(q->second));
	Edge<T,V> * nuevo2 = new Edge<T,V>(peso,&(p->second));


	p->second.m_aristas[q->first]=nuevo1;
	q->second.m_aristas[p->first]=nuevo2;


}


template <class T,class V>
void Grafo<T,V>::prints(){
	auto it= m_nodos.begin();
	//typename std::list<Nodo<T,V> >::iterator it;

	while(it!=m_nodos.end()){
		cout<<(it->first)<<"(";
		auto ite=(it->second).m_aristas.begin();
		while(ite!=(it->second).m_aristas.end()){
			cout<< ((ite->second)->m_pdestino)->m_dato << ", ";
			ite++;
		}
		cout << " )"<<endl;
		it++;
	}

}
