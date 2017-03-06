/* Autor Alexandre Carvalho
 * Faça um programa que cadastre as idades de 5 famílias 
 * de 3 membros cada (idade do pai, da mãe e do filho). 
 * Ordene as famílias em função da idade do pai (do mais velho ao mais novo). 
 * Feito isso, imprima a ordenação e a idade do pai e da mãe que possuam 
 * filhos da mesma idade. Caso não haja correspondentes , imprima -1.
 * Exercício elaborado pelo GAP (Grupo de Ajuda a Programação) da UFLA.
 * */
#include <iostream>
#define batata 5
int c=0;
using namespace std;
struct Familia{
	int idadePai;
	int idadeMae;
	int idadeFilho;
};
void Merge(Familia vet[], int inicio, int meio, int fim, Familia aux[]){
	int p=inicio;
	int j=meio+1;
	for(int i=inicio;i<=fim;i++){
		aux[i]=vet[i];
	}
	for(int i=inicio;i<=fim;i++){
		if(p>meio) vet[i]=aux[j++];
		else if(j>fim) vet[i]=aux[p++];
		else if (aux[i].idadePai>aux[j].idadePai) vet[i]=aux[p++];
		//~ else if(Maior(aux[i], aux[j])){ 
				//~ vet[i]=aux[p++];
			//~ }
		else vet[i]=aux[j++];
	}
}
void MergeSort(Familia vet[], int inicio, int fim, Familia aux[]){
	if(fim<=inicio) return;
	int meio = inicio+(fim -inicio)/2;
	MergeSort(vet, inicio, meio, aux);
	MergeSort(vet, meio+1, fim, aux);
	Merge(vet, inicio, meio, fim, aux);
}

void LeVetor(Familia vet[], int n, int i){
	if(i==n) return;
	cin>>vet[i].idadePai;
	cin>>vet[i].idadeMae;
	cin>>vet[i].idadeFilho;
	LeVetor(vet, n, i+1);
}
void PrintVetor(Familia vet[], int n, int i){
	if(i==n){ 
		cout<<endl;
		return;
	}
	cout<<vet[i].idadePai<<" ";
	cout<<vet[i].idadeMae<<" ";
	cout<<vet[i].idadeFilho<<endl;
	
	PrintVetor(vet, n, i+1);
}
int main(){
	Familia membros[batata];
	Familia aux[batata];
	
	LeVetor(membros, batata, 0);
	cout<<"\n\n ----------------------------- \n\n";
	MergeSort(membros, 0, batata-1, aux);
	PrintVetor(membros, batata, 0);
	for(int i=0;i<batata-1;i++){
		for(int j=i+1;j<batata;j++){
			if(membros[i].idadeFilho==membros[j].idadeFilho){
				cout<<membros[i].idadePai<<" "<<membros[i].idadeMae<<" ";
				cout<<membros[j].idadePai<<" "<<membros[j].idadeMae<<" ";
				c++;
			} 	
		}
	}
	
	return 0;
}
