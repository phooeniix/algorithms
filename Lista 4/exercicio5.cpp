/*
 * Autor:Alexandre Carvalho
 * 
 * 
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando variáveis
	int nPosicoes, nPRemover, delPosicao;
	cout<<"Quantas posições?\n";
	cin>>nPosicoes;
	int vetor[nPosicoes];
	for (int i=0;i<nPosicoes;i++){
		cout<<"Posição["<<i+1<<"]: ";
		cin>>vetor[i];
	}
	for (int i=0;i<nPosicoes;i++){
		cout<<"Posição["<<i<<"]: "<<vetor[i]<<"\n";
	}
	cout<<"Quantas posições para remover?\n";
	cin>>nPRemover;
	if(nPosicoes<nPRemover){
		cout<<"Queres remover até os valores que não existe?\n";
	}else{
	cout<<"Quer remover quais posições : ";
		for(int j=0;j<nPosicoes;j++){
			for(int i=0;i<nPRemover;i++){
				cin>>delPosicao;
			}
			if(delPosicao==j){
				//A posição que o carinha removeu vai receber o proximo
				//E o próximo vai receber o anterior e assim até chegar o ultimo que vai valer zero
				vetor[j]=vetor[j+1];
				vetor[nPosicoes-1]=0;
			}
		}
		for (int i=0;i<=nPosicoes-nPRemover;i++){
		cout<<"Posição["<<i<<"]: "<<vetor[i]<<"\n";
	}
	}

	//A função retornou sem erros de compilação
	return 0;
}
