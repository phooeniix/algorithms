/*Autor Alexandre Carvalho
 * 
 * Calcular a moda
 * */
#include <iostream>
#define tamanho 10
using namespace std;
int main(){
	//Declarando as variaveis
	int vetor[tamanho], maior=-1000000;
	//Lendo o vetor
	for(int i=0;i<tamanho;i++){
		cin>>vetor[i];
	}
	//Pegando o maior número do vetor escrito
	for(int i=0;i<tamanho;i++){
		if(maior<vetor[i]){
			maior=vetor[i];
		}
	}
	//Declarando um vetor do tamanho do maior numero do vetor para fazer o freq
	int freq[maior];
	for(int i=0;i<maior;i++){
		freq[i]=0;
	}
	
	for(int i=0;i<tamanho;i++){
		int n=vetor[i];
		freq[n]++;
	}
	int maiorFreq=0, posicao;
	//Vendo o valor mais digitado
	for(int i=0;i<maior;i++){
		if(maiorFreq<freq[i]){
			maiorFreq=freq[i];
			posicao=i;
		}
	}
	cout<<"\n\n----------\n\n";
	cout<<"O valor mais digitado foi o "<<posicao<<" digitado ";
	cout<<maiorFreq<<" vezes."<<endl;
	
	//A função retornou sem erros
	return 0;
}
