#pragma once
#include <iostream>
#include <set>
#include <map>
#include "creazione_grafo.hpp"
#include "fifo_lifo.hpp"

template <typename contenitore>
creazione_grafo graph_visit(const creazione_grafo& graph, int n_sorg, contenitore& c){
	
	creazione_grafo albero; //l'albero che deve dare in output
	std::set<int> n_visitati; //inizializzo un set di interi, di nodi che saranno visitati
	c.put(n_sorg); //in particolare metto il nodo sorgente nel contenitore
	n_visitati.insert(n_sorg); //il primo nodo visitato è proprio quello sorgente
	
	while(!c.empty()){ //Visita BFS o DFS in base al contenitore che viene passato
	    int u = c.get();
		for(int nodo : graph.neighbours(u)){
			if(n_visitati.find(nodo) == n_visitati.end()){ //Se il nodo vicino non è presente lo inseriamo nei visitati
			   n_visitati.insert(nodo);
               albero.add_edge(arco_edge(u, nodo));//Costruisco l'albero
			   c.put(nodo);
			};			   
		};
	};
	return albero;
};

bool findpath(const vector<vector<int>>& T, int u, int v, vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u); // Corrisponde a path.push(u)

    // Se abbiamo raggiunto la destinazione, il percorso è completo
    if (u == v) {
        return true;
    }

    // Esploriamo i vicini nel sotto-albero T
    // Corrisponde a: for n in neighbours(u) do
    for (int n : T[u]) {
        // Corrisponde a: if not visited[n] then
        if (!visited[n]) {
            // Chiamata ricorsiva
            if (findpath(T, n, v, visited, path)) {
                return true;
            }
        }
    }

    // Se il percorso non porta a v, rimuoviamo u e torniamo indietro (backtracking)
    path.pop_back(); // Corrisponde a path.pop()
    return false;
};