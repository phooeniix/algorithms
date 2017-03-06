/*
 * Autor: Alexandre Carvalho
 * Faça uma matriz que leia todos os valores pegue o maior e multiplique todos
 * os elementos da matriz pelo maior valor da mesma
 * 
 * */
#include <iostream>
#define batata 2
using namespace std;
int main(){
	//Declarando variaveis
	int matriz[batata][batata], matrizR[batata][batata];
	//Lendo a Matriz
	for (int i=0;i<batata;i++){
		for(int j=0;j<batata;j++){
			cout<<"Posição["<<i<<"]["<<j<<"]: ";
			cin>>matriz[i][j];
		}
	}
	
	//Escrevendo a Matriz escrita
	for (int i=0;i<batata;i++){
		for(int j=0;j<batata;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	//Terminando de escrever
	
	cout<<"\n\n*-----------------------------------*\n\n";
	
	//Vendo o maior elemento da Matriz
	int maior=matriz[0][0];
	for (int i=0;i<batata;i++){
		for(int j=0;j<batata;j++){
			if(maior<matriz[i][j]){
				maior=matriz[i][j];
			}
		}
	}
	//FIM de ver qual o maior
	
	
	//Multiplicando os valores da matriz pelo maior
	for (int i=0;i<batata;i++){
		for(int j=0;j<batata;j++){
			matrizR[i][j]=matriz[i][j]*maior;
		}
	}
	//FIM MULTIPLICAÇÃO
	
	//ESCREVENDO MATRIZ RESULTANTE
	for (int i=0;i<batata;i++){
		for(int j=0;j<batata;j++){
			cout<<matrizR[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
