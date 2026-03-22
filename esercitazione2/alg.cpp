#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
	static const int N=10;
	double arr[N]= {1.2, 4.5, 5.6,4.6, 7.6, 5.6, 3.1, 8.0, 4.5, 8.6};
	double somma=0;
	for (int i=0; i<10; i++){
		somma+=arr[i];
	}

	double media=somma/N;
	double var;
	somma=0;
	for (int j=0; j<10; j++){
		somma+=(media-arr[j])*(media-arr[j]);

	}
	double massimo=arr[0];
	double minimo=arr[0];
	for (int i=1; i<10; i++){
		massimo=std::max(massimo,arr[i]);
		minimo=std::min(minimo,arr[i]);
		
		
	}
	
	
	var=somma/N;
	double dvs=std::sqrt(var);
	cout<<var <<"\n";
	cout << dvs<<"\n";
	cout << massimo <<"\n";
	cout << minimo <<"\n"; //g++ -Werror=vla alg.cpp -o es
	
	
	
	
	
		
		
		
		


	return 0;
	
}
	
	