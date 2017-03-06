/*Autor: Alexandre Carvalho
 * vetor
 * 
 * */
#include <iostream>
#include <string>
#define batata 9
using namespace std;
void EscreveVetor(float x[batata]){
	for (int i=0;i<batata;i++){
		cout<<x[i]<<" ";
	}
}
void LeVetor(float y[batata]){
	for (int i=0;i<batata;i++){
		cin>>y[i];
	}
}
int main(){
	float vet[batata];
	LeVetor(vet);
	EscreveVetor(vet);
	//A função retornou sem erros
	return 0;
}
