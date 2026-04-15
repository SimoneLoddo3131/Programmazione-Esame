#include <iostream>
#include <vector>
#include <cstdlib>  
#include <random>    
#include "ordinamenti.hpp"
#include "filler.hpp"

 

int main() {
	std::random_device rd;

	
		std::vector<std::string> v(5);
	v[0]="luna";
	v[1]="carciofo";
	v[2]="giallo";
	v[3]="uncinetto";
	v[4]="nuvola";
	insertion_sort(v);
	
	std::cout << "Contenuto del vettore: ";
	for (int r=0; r<=4; r++){
		std::cout<<v[r]<< std::endl;
		
	}

	
	if (!is_sorted(v)){
			std::cout<<"test non superato insertion sort\n";
 
	
	
	randfiller flr;
	for (int i=0; i<100; i++ ){
		 std::vector<int> d((rd()%100));
	
	
		
		flr.fill(d, 1, 100);
		
		
		insertion_sort(d);
		
		if (!is_sorted(d)){
			std::cout<<"test non superato per insertsort\n";
		return EXIT_FAILURE;
		}
		
	
		
		
		
		
   
		
	}
	std::cout<<"test superato per insert sort\n";
	
	return EXIT_SUCCESS;
   
}

}
	
	
	


   