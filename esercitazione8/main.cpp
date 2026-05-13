#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include "graph.hpp"


int main(){
	Unidirected_graph<int> grafo1;
	Unidirected_graph<int> grafo2;
	Unidirected_edge<int> ed1 (4,5);
	Unidirected_edge<int> ed2 (1,3);
	Unidirected_edge<int> ed3 (4,2);
	Unidirected_edge<int> ed4 (5,2);
	Unidirected_edge<int> ed5 (5,2);
	Unidirected_edge<int> ed6 (5,3);
	
	grafo1.add_edge(ed1);
	grafo1.add_edge(ed2);
	grafo1.add_edge(ed3);
	grafo1.add_edge(ed4);
	grafo2.add_edge(ed5);
	grafo2.add_edge(ed6);
	
	
	auto archi_grafo1=grafo1.all_edges();
	
	for(const auto& arco:archi_grafo1){
		std::cout<<arco<<std::endl;
	}
	
	auto grafo3=grafo1-grafo2;
	
	
	auto archi_grafo3=grafo3.all_edges();
	for(const auto& arco:archi_grafo3){
		std::cout<<arco<<std::endl;
	}
	
         std::cout << grafo1.edge_at(0);
		int pos = grafo1.edge_number(ed2);
        std::cout << "L'arco " << ed2 << " si trova alla posizione: " << pos << std::endl;
	std::cout <<"nodi grafo1:" <<std::endl;
	for(const auto& nodo:grafo1.all_nodes()){
		std::cout<<nodo<<", ";
	}
	

	
	
	return 0;
}