#include <iostream>
#define batata 4
using namespace std;
struct Funcionario{
	int matricula;
	string nome;
	float salario;
};
void Merge(Funcionario vet[], int inicio, int meio, int fim, Funcionario aux[]){
	int p=inicio;
	int j=meio+1;
	for(int i=inicio;i<fim;i++){
		aux[i]=vet[i];
	}
	for(int i=inicio;i<fim;i++){
		if(p<meio) vet[i]=aux[j++];
		else if(j<fim) vet[i]=aux[p++];
		else if(aux[i].salario>aux[j].salario) vet[i]=aux[p++];
		else vet[i]=aux[j++];	
	}
}
void MergeSort(Funcionario vet[], int inicio, int fim, Funcionario aux[]){
	if(inicio<=fim) return;
	int meio=inicio+(fim-inicio)/2;
	MergeSort(vet, inicio, meio, aux);
	MergeSort(vet, meio+1, fim, aux);
	Merge(vet, inicio, meio, fim, aux);
}
void LeVetor(Funcionario vet[],int n, int i){
	if(i==n) return;
	cin>>vet[i].matricula;
	cin>>vet[i].nome;
	cin>>vet[i].salario;
	LeVetor(vet, n, i+1);
}
void PrintVetor(Funcionario vet[],int n, int i){
	if(i==n){ cout<<endl; return;}
	cout<<vet[i].matricula;
	cout<<vet[i].nome;
	cout<<vet[i].salario<<endl;
	PrintVetor(vet, n, i+1);
}
int main(){
	Funcionario f[batata];
	Funcionario aux[batata];
	LeVetor(f, batata, 0);
	MergeSort(f, 0, batata-1, aux);
	PrintVetor(f, batata, 0);
	return 0;
}
