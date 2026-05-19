#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
//da problemi, sennò loop di inclusioni con il file contenitore

template <typename T>
class Unidirected_edge{
	public: 
	T from_, to_;
	float weight_;
	
	
		Unidirected_edge(T nodo1, T nodo2, float w=1.0f){
			weight_=w;
			
		if (nodo1<=nodo2){
		from_=nodo1;
		to_=nodo2;}
		else{
			from_=nodo2;
		to_=nodo1;
		}
	}
	
	float weight() const{
		return weight_;
		
		
		
	}
	T from() const{
		
		return from_;
	}
	T to() const{
		return to_;
	}	
	
	bool operator<(const Unidirected_edge& other)const {
		if (from_!=other.from_){
			return from_ < other.from_;
		}
		return to_<other.to_;
	}
	
	bool operator==(const Unidirected_edge& other) const{
		return(other.from_==from_ && other.to_== to_);
	}


	
	
};
	template<typename T>
std::ostream& operator<<(std::ostream& os, const Unidirected_edge<T>& edge) {
    os<<"edge["<<edge.from()<<","<<edge.to()<<"]"<<std::endl;
    return os;
};
template <typename T>
class Unidirected_graph{
	private:
	std::set<Unidirected_edge<T>> archi;
	
	public:
	Unidirected_graph(){}
	Unidirected_graph(const Unidirected_graph<T>& other){
		this->archi=other.archi;
		
	}
	
	std::set<T> neighbours(T n) const{
		std::set<T> nodi_vicini;
		for(const auto& arco : archi){
        if (arco.from() == n  ||  arco.to()== n) {
		if(arco.from() == n ){
			nodi_vicini.insert(arco.to());
		}		
		else{nodi_vicini.insert(arco.from());}				
		
            }	
	}
	return nodi_vicini;
} 

void add_edge(const Unidirected_edge<T>& arco){
	archi.insert(arco);
}

std::set<Unidirected_edge<T>> all_edges(){
	
	return archi;
}

std::set<T> all_nodes(){
	std::set<T> nodi;
	for(const Unidirected_edge<T>& arco:archi) 	{
		nodi.insert(arco.from());
		nodi.insert(arco.to());
	}										//ho chiesto a gemini come fare un for con i set, siccome non sono come i vettori 
											//che posso usare i per esempio
	return nodi;		
}

int edge_number(const Unidirected_edge<T>& arco_da_trovare)const{
	int i=0;
	for(const auto& arco:archi){
		i++;
		if(arco==arco_da_trovare){				// i set vengono messi in ordine utilizzando l'operatore< che abbiamo già creato
			return i;
		}	
		
	}
	return -1;
}


Unidirected_edge<T> edge_at(int num_arco){
	int i=0;
	for(const auto& arco:archi){
	
	if(i==num_arco){
		return arco;
	}
	i++;	
		
	}
	
	//qua bisogna mettere qualcosa per gestire l'errore
	throw std::out_of_range("Indice fuori limite"); 
	//
}
float get_weight(T n1, T n2) {
    for(const auto& arco : archi) {
        
        if ((arco.from() ==n1 && arco.to()== n2) || 
            (arco.from() == n2 &&arco.to() == n1)) {
            return arco.weight();
        }
    }
    // Se i due nodi non sono direttamente collegati da un arco, 
    // restituisci un valore di errore o infinito logico
    throw std::runtime_error("Arco non trovato tra i nodi specificati");
}
Unidirected_graph<T> operator-(const Unidirected_graph<T>& other) const{ 
	Unidirected_graph<T> grafo_sottrazione;
	for(const auto& arco: this->archi){
		bool is_in_the_other_graf=false;
		for(const auto& other_arco:other.archi){
			if(other_arco==arco){
				is_in_the_other_graf=true;
				break;
				
				
			}
		}
		if(!is_in_the_other_graf){
			grafo_sottrazione.add_edge(arco);
			
		}
		
		
		
		
		
	}
	
	return grafo_sottrazione;
	
	
	

	
	
}};

#endif