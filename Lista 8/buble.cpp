#include <iostream>
#include <stdlib.h>
using namespace std;
void Troca(int &a, int &b){
	int aux =a;
	a = b;
	b=aux;
}
int cont=0;
void BubleSort(int vet[], int N){
	for(int i=0;i<N-1;i++){
		cont++;
		if(vet[i]>vet[i+1]){
			Troca(vet[i], vet[i+1]);
		}
	}
	
}
bool Teste (int vet[], int N){
	for(int i=0;i<N-1;i++){
		cont++;
		if(vet[i]>vet[i+1]) return false;
	}
	return true;
}

void Imprime(int vet[], int N){
	for(int i=0;i<N;i++){
		cout<<vet[i]<<" ";
	}
	cout<<endl;
}

void Ordena(int vet[], int N){
	while(!Teste(vet, N)){
		BubleSort(vet, N);
	}
}

int main(){
	int n;
	cin>>n;
	int vet[n];
	for(int i=0;i<n;i++){
		cin>>vet[i];
	}
	//~ cout<<"#--------------------#\n\n";
	//~ Imprime(vet, n);
	cout<<"#--------------------#\n\n";
	Ordena(vet, n);
	Imprime(vet, n);
	cout<<cont;
	
	
	return 0;
}
