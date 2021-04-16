#include "Funzioni.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
void mergeSortTesting();
void countingSortTestingBestCase();
void countingSortTestingWorstCase();


int main(int argc, char** argv) {
	
	int scelta;
	
	
	do{
	
		cout<<"TESINA ASD - 2020/2021 - BENITO VISONE M63001177"<<endl;
		cout<<"1. MERGE-SORT TESTING	2. COUNTING-SORT BEST CASE TESTING	3. COUNTING-SORT WORST CASE TESTING"<<endl;
		cin>>scelta;
		if(scelta<1 || scelta>3){
			cout<<"Errore, inserire 1 o 2.\n";
		}
	}while(scelta<1||scelta>3);
	
		if(scelta == 1){
			mergeSortTesting();
		}
		else if(scelta == 2){
			countingSortTestingBestCase();
		}
		else if(scelta ==3){
			countingSortTestingWorstCase();
		}
	
	return 0;
}
void mergeSortTesting(){
	
	int x = -1;
	int contatore = 0;
	float somma = 0.00;
	std::ofstream myfile;
    myfile.open ("measurements.csv");
	srand(time(NULL));
	double measurements_vector[100000];
	
for(int dim = 1;dim<=10000;dim++){
		int A[dim];
		x = -1;
	
		for(int j = 0;j<dim;j++){
			x = rand() % 3000+1;
			A[j] = x;
		}
	
		starttime();
			MergeSort(A,0,dim-1);
		endtime();
		measurements_vector[dim-1]=eltime();
		myfile << measurements_vector[dim-1]<<"\n";
	}
	myfile.close();
	
}

void countingSortTestingBestCase(){
	
	int x = -1;
	int contatore = 0;
	int k = 0;
	float somma = 0.00;
	std::ofstream myfile;
    myfile.open ("measurements_counting_sort_best_case.csv");
	srand(time(NULL));
	double measurements_vector[10000];
	
for(int dim = 1;dim<=10000;dim++){
		int A[dim];
		int* B = new int[dim];
		k = rand() % 99 +1;
		x = -1;
	
		for(int j = 0;j<dim;j++){
			if(k>dim) x = rand() % dim;
			else x = rand() % k;
			A[j] = x;
		}
		starttime();
			CountingSort(A,B,k,dim);
		endtime();
		measurements_vector[dim-1]=eltime();
		myfile << measurements_vector[dim-1]<<"\n";
		delete[] B;

}
	myfile.close();
	
}

void countingSortTestingWorstCase(){
	
	int x = -1;
	int contatore = 0;
	int k = 0;
	float somma = 0.00;
	std::ofstream myfile;
    myfile.open ("measurements_counting_sort_worst_case.csv");
	srand(time(NULL));
	double measurements_vector[10000];
	
for(int dim = 1;dim<=10000;dim++){
		int A[dim];
		int* B = new int[dim];
		//WORST CASE, PER BEST CASE FACCIAMO VARIARE K SOLO TRA 1 E 99 
		k = rand() % dim + dim;
		//k = rand() % dim + dim;
		x = -1;
	
		for(int j = 0;j<dim;j++){
			x = rand() % dim;
			A[j] = x;
		}
		starttime();
			CountingSort(A,B,k,dim);
		endtime();
		measurements_vector[dim-1]=eltime();
		myfile << measurements_vector[dim-1]<<"\n";
		
		delete[] B;
	
}
	myfile.close();
	
}


