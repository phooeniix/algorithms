/*Autor: Alexandre Carvalho
 * Escreva um subprograma que verifica 
 * se um vetor V[0..n-1] está em ordem crescente.
 * 
 * */
#include <iostream>
using namespace std;
bool Verifica(int n, float vet[]){
	for(int i=0;i<n-1;i++){
		if(vet[i]>vet[i+1]) return false;
	}
	return true;
}
float LeVetor(int n, float vet[], int i){
	if(i==n) return 0;
	cin>>vet[i];
	return LeVetor(n, vet, i+1);
}
int main(){
	int n;
	cin>>n;
	float vet[n];
	LeVetor(n, vet, 0);
	int aux = Verifica(n, vet);
	if(aux ==1)
		cout<<"True";
	else
		cout<<"False";
	
	return 0;
}
