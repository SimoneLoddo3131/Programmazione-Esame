#include "timecounter.h"
#include <iostream>

#include <vector>
#include <cstdlib>  
#include <random>  
#include "filler.hpp" 
#include "sorts.hpp"

//file dove testo il merge e il quick sort con le stringhe e valuto la dimensione fino alla 
//quale insertion sort è più veloce
//nel mio caso è 32

int main() {
   
   
   randfiller flr;
   timecounter timer;
   std::cout << "DIM\t| INSERTION\t| MERGE\t\t| QUICKSORT\t| BUBBLE\t| SELECTION" << std::endl;
   
   for(size_t i =2; i < 100; i++) {
        std::cout << i << "\t| ";

      
        std::vector<int> y(i);
		
        flr.fill(y, -8000, 8000); 
        timer.tic();
        insertion_sort(y);    
		float insertion_time=timer.toc();
		
        std::cout <<insertion_time  << "\t| "; 
	
	 
		 std::vector<int> b(i);
        flr.fill(b, -8000, 8000);
        timer.tic();
		
		
        merge_sort(b,0, i-1); 
		float merge_time=timer.toc();
        std::cout << merge_time << "\t|";

       
        std::vector<int> t(i);
		
        flr.fill(t, -8000, 8000);
        timer.tic();
		
        quicksort(t,0,i-1); 
		float quick_time=timer.toc();
		
        std::cout << quick_time << "\t|";
		
		
		
		
		 std::vector<int> g(i);
		
		
        flr.fill(g, -8000, 8000);
        timer.tic();
		
		
        selection_sort(g); 
		float sel_time=timer.toc();
        std::cout << sel_time << "\t|";
		
		
		 std::vector<int> r(i);
		
		
        flr.fill(r, -8000, 8000);
        timer.tic();
		
		
        bubble_sort(r); 
		float bubblesort_time=timer.toc();
        std::cout << bubblesort_time << std::endl;
		
		/*
			if (quick_time>insertion_time){
				   std::cout << "il quicksort ha superato in velocità alla dimensione " << i <<std::endl;
				   
				   
				
				
			}
			linea di codice per capire a che dim il quicksort è piu veloce
		
		*/ 
    }
   
   
   
   
   
   
   
    std::cout << "DIM\t| INSERTION\t| MERGE\t\t| QUICKSORT\t| SORT\t| QUICKSORT MODIFICATO" << std::endl; //ora lo testo anche per i grandi numeri
	
	
    

    
    for(size_t i =4; i < 10000000; i = i * 2) {
        std::cout << i << "\t| ";

       if (i<40000){
        std::vector<int> v(i);
		
        flr.fill(v, -8000, 8000); 
        timer.tic();
        insertion_sort(v);    
		float insertion_time=timer.toc();
		
        std::cout <<insertion_time  << "\t| "; 
	
	   }
	   else{ std::cout <<"NULL\t"  << "\t| ";} //insertion è quadratico quindi non ha senso farlo girare dalla dim 30000 mila in su
	   
        std::vector<int> c(i);
		
		
        flr.fill(c, -8000, 8000);
        timer.tic();
		
		
        merge_sort(c,0, i-1); 
		float merge_time=timer.toc();
        std::cout << merge_time << "\t|";

       
        std::vector<int> p(i);
		
        flr.fill(p, -8000, 8000);
        timer.tic();
		
        quicksort(p,0,i-1); 
		float quick_time=timer.toc();
		
        std::cout << quick_time << "\t|";
		
		
		
		
		 std::vector<int> u(i);
		
		
        flr.fill(u, -8000, 8000);
        timer.tic();
		
		
        std::sort(u.begin(), u.end()); 
		float sort_time=timer.toc();
        std::cout << sort_time << "\t|";
		
		
		 std::vector<int> q(i);
		
		
        flr.fill(q, -8000, 8000);
        timer.tic();
		
		
        quick_mod(q,0,i-1); 
		float modsort_time=timer.toc();
        std::cout << modsort_time << std::endl;
		
		/*
			if (quick_time>insertion_time){
				   std::cout << "il quicksort ha superato in velocità alla dimensione " << i <<std::endl;
				   
				   
				
				
			}
			linea di codice per capire a che dim il quicksort è piu veloce
		
		*/ 
    }
	std::vector<std::string> vettore_stringa={"ciao", "come","stai", "io","sto", "bene","e","tu" };
	std::size_t dim_str=size(vettore_stringa);
	
	for(std::size_t i=0; i<dim_str;i++){
		std::cout<<vettore_stringa[i]<<" ";
		
	}
std::cout<<std::endl;

merge_sort(vettore_stringa, 0, size(vettore_stringa)-1);
if (is_sorted(vettore_stringa)){
	std::cout<<"il vettore stringa è ordinato";
	
}
	
else{std::cout<<"il vettore stringa non è stato ordinato";
}

for(std::size_t i=0; i<size(vettore_stringa);i++ ){
		std::cout<<vettore_stringa[i]<<" ";
		
	}
std::cout<<std::endl;

   
}