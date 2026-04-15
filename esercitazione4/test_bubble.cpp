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
	std::cout << "Contenuto del vettore: ";
	if (!is_sorted(v)){
			std::cout<<"test non superato bubble sort\n";
 
	

	
	
	
	randfiller flr;
	for (int i=0; i<100; i++){
		 std::vector<int> d((rd()%100));
	
	
		
		flr.fill(d, 0, 100);
		
		
		bubble_sort(d);
	
		if (!is_sorted(d)){
			
		return EXIT_FAILURE;}
		
		
	
		
		
		
		
   
		
	}
	std::cout<<"test superato per bubble sort\n";
	
	return EXIT_SUCCESS;
   
}
	
	
	

}
   