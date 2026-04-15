#include <iostream>
#include <vector>
#include <algorithm>

#include <optional>
template<typename T>
std::optional<T>
max_elem(const std::vector<T>& vec)
{
if (vec.size() == 0) {
return {};
}
T vec_max = vec[0];
for (std::size_t i  = 1; i < vec.size(); i++) {
vec_max = std::max(vec_max, vec[i]);
}
return vec_max;
}

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


void bubble_sort(std::vector<T>& vec){


	for (std::size_t i = 0; i<vec.size(); i++){
		for(std::size_t j=vec.size()-1 ; j>i; j--){
			
			if (vec[j]<vec[j-1]){
				std::swap(vec[j], vec[j-1]);
			}
		}	
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
	
	
	
	

	




