/*Autor: Alexandre Carvalho 
 *  Crie uma função recursiva que retorne a média 
 * dos elementos de um vetor de números de inteiros.
 * */
#include <iostream>
using namespace std;
void LeVet(int e, int vet[]){
	for(int i=0;i<e;i++){
		cin>>vet[i];
	}
}
void PrintVet(int e, int vet[]){
	for(int i=0;i<e;i++){
		cout<<vet[i]<<" ";
	}
	cout<<endl;
}
int Media(int x, int vet[]){
	if(x==1){
		return x;
	}
	else{	
		(Media((x-1), vet) +  vet[x-1]);
	}
}
int main(){
	int n, aux;
	cin>>n;
	int vetor[n];
	LeVet(n, vetor);
	PrintVet(n, vetor);
	aux = Media(n, vetor);
	cout<< aux/n;
	//A função retornou sem erros de compilação
	return 0;
}
