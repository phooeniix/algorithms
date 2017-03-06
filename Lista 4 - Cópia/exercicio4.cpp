/*
 * Autor:Alexandre Carvalho
 * Faça um programa para remover um valor do vetor dada a posição desejada
 * 
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando variáveis
	int i, delPosicao, tamanho;
	
	cout<<"Tamanho do vetor: \n";
	cin>>tamanho;
	
	//Declarando vetor de tamanho recebido
	int vetor[tamanho];
	//Lendo os valores inseridos no vetor
	cout<<"Escreva os valores do vetor : \n";
	for(i=0;i<tamanho;i++){
	cin>>vetor[i];
	}
	cout<<endl;
	//Escrevendo na tela o vetor recebido
	for(i=0;i<tamanho;i++){
		cout<<"Posição ["<<i<<"]: "<<vetor[i]<<endl;
	}
	//Lendo qual valor o carinha vai digitar
	cout<<"Qual posição você deseja remover : \n";
	cin>>delPosicao;
	cout<<endl;
	//Apagando o valor
	for(i=0;i<tamanho;i++){
		if(delPosicao==i){
			//A posição que o carinha removeu vai receber o proximo
			//E o próximo vai receber o anterior e assim até chegar o ultimo que vai valer zero
			vetor[i]=vetor[i+1];
			vetor[tamanho-1]=0;
		}
		cout<<"Posição ["<<i<<"]: "<<vetor[i]<<endl;
	}
	//A função retornou sem erros de compilação
	return 0;
}
