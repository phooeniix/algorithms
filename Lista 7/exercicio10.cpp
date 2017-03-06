/*Escreva   uma   função   chamada MAX2 , ​que   recebe   um   
 * vetor   de   números   reais,   um  inteiro   ​N   contendo
 * o   tamanho   do   vetor,   e   dois   parâmetros   reais A   e  B , ​
 * passados   por  referência.   A   função   ​MAX2   não   retorna  valor.
 * A   função   deve   encontrar   os   dois   maiores elementos   
 * do   vetor   e   colocar   o   maior   deles   em  A   e   o  
 * segundo   maior   em   ​B . ​  Escreva   um  programa para utilizar esta função. 
 */
#include <iostream>
using namespace std;
void LeVet(int n, float vet[]){
	for(int i=0;i<n;i++){
		cin>>vet[i];
	}
}
void PrintVet(int n, float vet[]){
	for(int i=0;i<n;i++){
		cout<<vet[i]<<" ";
	}
	cout<<endl;
}
void MAX2(int n, float vet[], float &a, float &b){
	for(int i=0;i<n;i++){
		if(vet[i]>a){
			a = vet[i];
		}
	}
}
void MAX2B(int n, float vet[], float &a, float &b){
	int posicao;
	for(int i=0;i<n;i++){
		if(vet[i]==a){
			posicao = i;
		}
		if(i!=posicao){
			if(vet[i]>b){
				b=vet[i];
			}
		}
	}
}

int main(){
	int x;
	cin>>x;
	float vetor[x];
	float pm=-123, sm=-1223;
	LeVet(x, vetor);
	PrintVet(x, vetor);
	MAX2(x, vetor, pm, sm);
	MAX2B(x, vetor, pm, sm);
	cout<<"Primeiro: "<<pm<<endl;
	cout<<"Segundo: "<<sm<<endl;
	
	return 0;
}


