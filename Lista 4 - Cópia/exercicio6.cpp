/*
 * Autor:Alexandre Carvalho
 * 
 * 
 * */
#include <iostream>
#define batata 5
#define banana 10
using namespace std;
int main(){
	//Declarando variáveis
	int i,vet1[batata], vet2[batata], vet3[banana];
	//Lendo vetor 1
	cout<<"Escreva os valores do vetor 1: \n";
	for(i=0;i<batata;i++){
		cin>>vet1[i];
	}
	//Lendo vetor 2
	cout<<"Escreva os valores do vetor 2: \n";
	for(i=0;i<batata;i++){
		cin>>vet2[i];
	}
	cout<<"*-----------------------------------*\n\n";
	//Escrevendo os vetores
	cout<<"VETOR 1: \n\n";
	for(i=0;i<batata;i++){
		cout<<"Posição["<<i<<"]: "<<vet1[i]<<endl;
	}
	cout<<"VETOR 2: \n\n";
	for(i=0;i<batata;i++){
		cout<<"Posição["<<i<<"]: "<<vet2[i]<<endl;
	}
	cout<<"*-----------------------------------*\n\n";
	for(i=0;i<banana;i++){
		if((i%2)==0){
			vet3[i]=vet1[i];
		}else{
			vet3[i]=vet2[i];
		}
			cout<<"Posição["<<i<<"]: "<<vet3[i]<<endl;
	}
	//A função retornou sem erros de compilação
	return 0;
}
