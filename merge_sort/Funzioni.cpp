#include "Funzioni.h"
#include <windows.h>

static LARGE_INTEGER frequency;
static LARGE_INTEGER t1,t2;
static double elapsedTime;

void MergeSort(int A[],int p, int r){
	
	if(p<r){
		int q = p+(r-p)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
	else return;
	
}
void Merge(int A[],int p, int q, int r){
	
	int n1 = q-p+1;
	int n2 = r-q;
	
	int L[n1];
	int R[n2];
	
	for(int i = 0;i<n1;i++){
		L[i]=A[p+i];
	} 
	for(int j = 0;j<n2;j++){
		R[j] = A[q+j+1];
	}
	
	int i = 0;
	int j = 0;
	int k = p;
	
	while (i < n1 && j < n2) {
		if(L[i]<=R[j]){
			A[k] = L[i];
			i = i+1;
		}
		else{
			A[k] = R[j];
			j = j+1;
		}
		k++;
	}
	
	while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
	
	
}
void CountingSort(int A[],int B[],int k,int dim){
	int n = dim;
	
	int C[k+1];
	
	for(int i = 0;i<k+1;i++){
		C[i]= 0;
	}
	
	for(int i = 0;i<n;i++){
		C[A[i]]++;
	}
	
	for(int i = 1;i<k+1;i++){
		C[i]=C[i]+C[i-1];
	}
	
	for(int i =n-1;i>=0;i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

void starttime(){
	static int first = 1;
	if(first){
		QueryPerformanceFrequency(&frequency);
		first = 0;
	}
	QueryPerformanceCounter(&t1);
}

void endtime(){
	QueryPerformanceCounter(&t2);
}

double eltime(){
	return ((double)t2.QuadPart - (double)t1.QuadPart) * 10000000.0/(double)frequency.QuadPart;
}

