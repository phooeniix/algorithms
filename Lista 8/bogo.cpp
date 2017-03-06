#include <iostream>
#include <stdlib.h>
using namespace std;
void Troca(int &a, int &b){
	int aux =a;
	a = b;
	b=aux;
}
void Embaralha(int vet[], int N){
	for(int i=0;i<N;i++){
		int sorteio = rand()%N;
		Troca(vet[i], vet[sorteio]);
	}
}
bool Teste (int vet[], int N){
	for(int i=0;i<N-1;i++){
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
		Embaralha(vet, N);
	}
}

int main(){
	srand(time(0));
	int n;
	cin>>n;
	int vet[n];
	for(int i=0;i<n;i++){
		cin>>vet[i];
	}
	cout<<"#--------------------#\n\n";
	Imprime(vet, n);
	cout<<"#--------------------#\n\n";
	Ordena(vet, n);
	Imprime(vet, n);
	
	
	return 0;
}
