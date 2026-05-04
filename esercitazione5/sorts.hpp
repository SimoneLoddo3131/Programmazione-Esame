#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <optional>


template <typename T>
bool is_sorted(const std::vector<T>& vec){
	if (vec.size() < 2) {return true;}
	for(std::size_t i = 0; i<vec.size()-1;i++){
		if(vec[i]>vec[i+1]){
			return false;
	
		}
	
	
}
return true;}







template<typename T>

void merge (std::vector<T>& v, std::size_t p, std::size_t q, std::size_t r){
	size_t n1=q-p+1;
	std::size_t n2=r-q;
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	for(std::size_t i = 0; i<n1;i++){
		L[i]=v[p+i];
}
for(std::size_t j = 0; j<n2;j++){
		R[j]=v[q+j+1];
		
		
		
}
	
std :: size_t i=0;
std :: size_t j=0;	
std:: size_t k=p;
while (i<n1 && j<n2){ 
	if(L[i]<=R[j]){
		v[k]=L[i];
		i++;
		
	}
	else{
		v[k]=R[j];
		j++;	
	}
	k++;
	
	
	
}
while(i<n1){
	v[k]=L[i];
	k++;
	i++;
}
while(j<n2){
	v[k]=R[j];
	k++;
	j++;
}
	
	}
	
template<typename T>
void merge_sort(std::vector<T>& vec, std::size_t p, std::size_t r){
	
if (p<r){
	std::size_t q= std::floor((p+r)/2); 
	merge_sort(vec, p,q);
	merge_sort(vec,q+1,r);
	merge(vec, p, q, r);
	
	
}
}	


template<typename T>
std::size_t partition(std::vector<T>& v, std::size_t p, std::size_t r){
  
	T x=v[r];
	std::size_t i=p;
	for(std::size_t j=p; j<r; j++){
		if(v[j]<=x){
			std::swap(v[i],v[j]);
			i++;
		}
	}
		std::swap(v[i], v[r]);
		return i;
		
		
	}




template<typename T>
void quicksort (std::vector<T>& v,std::size_t p, std::size_t r){
	if (p<r){
		std::size_t q=partition(v,p,r);
		if (q > p) {
            quicksort(v, p, q - 1);
          }
		quicksort(v,q+1,r);
	}	
}





	


template<typename T>
void insertion_sort(std::vector<T>& vec){
	for(std::size_t j=1; j<vec.size(); j++){
		T key=vec[j];
		size_t i =j;
		
		while(i>0 && vec[i-1]>key){
			vec[i]=vec[i-1];
			i--;
		} 
		vec[i]=key;
		
		
	}
}
	
template<typename T>	
void selection_sort(std::vector<T>& vec){
	
	for (std::size_t i = 0; i<vec.size(); i++ ){
		std::size_t min=i;
		for (std::size_t j=i+1; j<vec.size(); j++){
			if (vec[j]<vec[min]){
			min=j;

			}
			
			
		}
		std::swap(vec[i], vec[min]);
	}
		
	}
	
	//g++ -std=c++20 measure_sorts.cpp timecounter.cpp -o pippo
	//g++ -std=c++20 timecheck.cpp timecounter.cpp -o pippo
	
	
	

	
template<typename T>
void quick_mod(std::vector<T>& v,std::size_t p, std::size_t r){
	std::size_t soglia=32; //32 in su dimensione per la quale il quicksort è piu veloce
	std::size_t n=v.size();
	if (n<soglia){
		insertion_sort(v);
		
	}
	else{
		quicksort(v,p,r);
	}
	
}


template<typename T>


void bubble_sort(std::vector<T>& vec){


	for (std::size_t i = 0; i<vec.size(); i++){
		for(std::size_t j=vec.size()-1 ; j>i; j--){
			
			if (vec[j]<vec[j-1]){
				std::swap(vec[j], vec[j-1]);
			}
		}	
	}	
}


