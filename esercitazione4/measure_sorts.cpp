#include "timecounter.h"
#include <iostream>
#include "ordinamenti.hpp"
#include <vector>
#include <cstdlib>  
#include <random>  
#include "filler.hpp" 

using namespace std;

int main() {
   
   
   randfiller flr;
   timecounter timer;
    cout << "DIM\t| INSERTION\t| BUBBLE\t| SELECTION" << endl;
    

    for(unsigned int i = 4; i < 8193; i = i * 2) {
        cout << i << "\t| ";

       
        std::vector<int> v(i);
		
        flr.fill(v, -8000, 8000); 
        timer.tic();
        insertion_sort(v);
		
        cout << timer.toc() << "\t| ";

     
        std::vector<int> c(i);
		
		
        flr.fill(c, -8000, 8000);
        timer.tic();
		
		
        bubble_sort(c); 
        cout << timer.toc() << "\t ";

       
        std::vector<int> a(i);
		
        flr.fill(a, -8000, 8000);
        timer.tic();
		
        selection_sort(a); 
		
		
        cout << timer.toc() << endl; 
    }

   
}