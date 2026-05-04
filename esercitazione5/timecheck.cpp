#include "timecounter.h"
#include <iostream>

#include <vector>
#include <cstdlib>  
#include <random>  
#include "filler.hpp" 
#include "sorts.hpp"

//in questo file
int main(){

std::size_t dim;
std::cout<<"inserisci la dimensione dei 100 vettori: ";
std::cin>>dim;

randfiller flr;
   timecounter timer;
   std::cout << "SORT\t| QUICKSORT MODIFICATO\t" << std::endl;
   timer.tic();
   
/*for(std::size_t i=0; i<100; i++){
	
	 std::vector<int> v(dim);
	flr.fill(v, -8000, 8000);
	insertion_sort(v);	
	
}
		double insertion_time=timer.toc();
		double media_insert=insertion_time/100;
		
		
		std::cout<<media_insert<<"\t";
		timer.tic();*/ //eliminato perchè ci mette troppo tempo, comparo solo il quick modificato con l'insertion e sort

for(std::size_t i=0; i<100; i++){//media per il sort 
	 std::vector<int> v(dim);
	flr.fill(v, -8000, 8000);
	std::sort(v.begin(), v.end());	
	
}
		double sort_time=timer.toc();
		double media_sort=sort_time/100;
		
		std::cout <<media_sort<< "\t";
timer.tic();
for(std::size_t i=0; i<100; i++){ //media per il quicksort modificato
	 std::vector<int> v(dim);
	flr.fill(v, -8000, 8000);
	quick_mod(v,0,dim-1); 	
	
}
		double modsort_time=timer.toc();
		double media_modsort=modsort_time/100;
		std::cout<<media_modsort<<"\t";
		
}


		


		








//g++ -std=c++20 timecheck.cpp timecounter.cpp -o pippo
