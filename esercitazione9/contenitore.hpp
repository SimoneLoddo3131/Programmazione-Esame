
#ifndef CONTENITORE_HPP
#define CONTENITORE_HPP

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include "graph.hpp"
#include <set>
#include <utility>
#include <limits>

template <typename T>
class lifo{
	public:
	std::list<T> coda;
	lifo(){}

void put(T valore){				//inserisce un elemento
	coda.push_front(valore);
}
T get(){
	if(!coda.empty()){
	T v=coda.front();
	coda.pop_front();
	return v;}
	else{return T();}
}	//rimuove un elemento

bool empty(){
	
	return coda.empty();
}  //booleinano per vedere se il contenitore è vuoto
	
	
	
	
};
template <typename T>
class fifo{
	public:
	std::list<T> coda;
	fifo(){}

void put(T valore){				//inserisce un elemento
	coda.push_front(valore);
}
T get(){
	if(!coda.empty()){
	T v=coda.back();
	coda.pop_back();
	return v;}
	else{return T();}
	}
							//rimuove un elemento

bool empty(){
	
	return coda.empty();
}  //booleinano per vedere se il contenitore è vuoto
	
	
	
	
};

template <typename T, typename U>
Unidirected_graph<T> graph_visit(const Unidirected_graph<T>& G, T v, U& s){
	std::set<T> nodi_visitati;
	nodi_visitati.insert(v);
	Unidirected_graph<T> albero;
	s.put(v);
	
	while(!s.empty()){
		T u = s.get();
		auto vicini=G.neighbours(u);
		for(const auto& nod:vicini){
			if(nodi_visitati.find(nod)==nodi_visitati.end()){
			nodi_visitati.insert(nod);
			Unidirected_edge<T> arco(u,nod);
			albero.add_edge(arco);
			
			s.put(nod);
			
		}}
	}
	
	return albero;
};
template <typename T>
void dijkstra(const Unidirected_graph<T>& graph, T nodo_inizio){
	std::set<T> unvisited_nodi=graph.all_nodes();
	std::set<std::pair<float, T>> PQ;
	const float INF = std::numeric_limits<float>::infinity();
	
	std::map<T, T> pred;
	std::map<T,float> dist;
	std::set<T> tutti_nodi = graph.all_nodes();
	for(const T& nodo:tutti_nodi){
		pred[nodo]=T();
		dist[nodo]=INF;	
	}
	
	dist[nodo_inizio]=0.0f;
	pred[nodo_inizio]=nodo_inizio;
	
	for(const T& nodo:tutti_nodi){
		PQ.insert({dist[nodo], nodo});

	}
	

	while(!PQ.empty()){
		auto [p, u] = *PQ.begin();   //Pq.begin è un iteratore, a differenza del puntatore se fai PQ.begin+1 ti porta al secondo elemento e non alla cella di memoria sucessiva
		PQ.erase(PQ.begin());
		
		std::set<T> vicini = graph.neighbours(u);
		for(const T& w:vicini){
			float peso_arco=graph.get_weight(u,w);
			if(dist[w]>dist[u]+peso_arco){
				auto vecchio=PQ.find({dist[w], w});
				if(vecchio!=PQ.end()){
					PQ.erase(vecchio);
				}
				dist[w]=dist[u]+peso_arco;
				pred[w]=u;
				PQ.insert({dist[w], w});
				
				
				
			}
			
			
		}
		
    }

	
		std::cout << nodo_inizio << std::endl;
    for (const T& nodo : tutti_nodi) {
        std::cout << "Nodo: " << nodo;
       
       
		
        std::cout << "Predecessore: " << pred[nodo] <<std::endl; 
	
	
}
}


template <typename T, typename U>
void dfs__r(const Unidirected_graph<T>& G, U& s, std::set<T>& visitati, Unidirected_graph<T>& albero){
	
	if(s.empty()){
		return;
	}
		T u=s.get();
		auto vicini=G.neighbours(u);
		
		
	for (const auto& nod : vicini){
		if(visitati.find(nod)==visitati.end()){
			
			visitati.insert(nod);   // ci serve per evitare che entri in un loop inf serve per controllare che non ci siamo mai andati
Unidirected_edge<T>arco(u,nod);

		albero.add_edge(arco);
		s.put(nod);
		
		
		dfs__r(G,s,visitati, albero);
		}
		
		
		
	}
		
		}
		
		
		template <typename T>
		Unidirected_graph<T> dfs_ricorsivo(const Unidirected_graph<T>& G, T v){
			std::set<T> nodi_visitati;
			Unidirected_graph<T> albero;
			lifo<T> s;
			
			nodi_visitati.insert(v);
			s.put(v);
			dfs__r(G,s, nodi_visitati,albero);
			
			return albero;
			
		}
			
			
		
		#endif
		
		
	


