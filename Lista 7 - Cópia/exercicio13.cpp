/*Autor: Alexandre Carvalho
 * vetor
 * 
 * */
#include <iostream>
#include <string>
#define batata 5
using namespace std;
void EscreveVetor(float x[batata]){
	for (int i=0;i<batata;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void LeVetor(float y[batata]){
	for (int i=0;i<batata;i++){
		cin>>y[i];
	}
}
void Buscar(float z[batata], float b){
	for (int i=0;i<batata;i++){
		if(z[i]==b){
			cout<<"Posicao : "<<i+1<<endl;
		}
	}
	
}
int main(){	
	float vet[batata], busca;
	LeVetor(vet);
	EscreveVetor(vet);
	cin>>busca;
	Buscar(vet,busca);
	//A função retornou sem erros
	return 0;
}
