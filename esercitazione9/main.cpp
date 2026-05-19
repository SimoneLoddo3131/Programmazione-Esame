#include <iostream>
#include <fstream>
#include "graph.hpp"   
#include "contenitore.hpp"

int main(){
	Unidirected_graph<int> G;
    G.add_edge(Unidirected_edge<int>(1, 2));
    G.add_edge(Unidirected_edge<int>(1, 3));
    G.add_edge(Unidirected_edge<int>(1, 4));
    G.add_edge(Unidirected_edge<int>(1, 6));
    G.add_edge(Unidirected_edge<int>(2, 4));
    G.add_edge(Unidirected_edge<int>(2, 5));
    G.add_edge(Unidirected_edge<int>(2, 7));
    G.add_edge(Unidirected_edge<int>(4, 7));
    G.add_edge(Unidirected_edge<int>(5, 7));
    G.add_edge(Unidirected_edge<int>(6, 7));
    G.add_edge(Unidirected_edge<int>(6, 8));
    G.add_edge(Unidirected_edge<int>(7, 9));
    G.add_edge(Unidirected_edge<int>(8, 9));
	
	fifo<int>  q;
	auto bfs_res = graph_visit(G, 1, q);
	std::ofstream f_bfs("bfs.dot");
    f_bfs << "graph G {\n";
    for (const auto& e : bfs_res.all_edges()) {
        f_bfs << "  \"" << e.from() << "\" -- \"" << e.to() << "\";\n";
    }
    f_bfs << "}\n";
    f_bfs.close();
    std::cout << "Generato file bfs.dot" << std::endl;
	auto dfs_res = dfs_ricorsivo(G, 1);
	std::ofstream f_dfs("dfs.dot");
    f_dfs << "graph G {\n";
    for (const auto& e : dfs_res.all_edges()) {
        f_dfs << "  \"" << e.from() << "\" -- \"" << e.to() << "\";\n";
    }
    f_dfs << "}\n";
    f_dfs.close();
    std::cout << "Generato file dfs.dot" << std::endl;

    std::cout << "--- ELABORAZIONE COMPLETATA ---" << std::endl;
    return 0;
}