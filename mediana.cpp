#include <iostream>
using namespace std;
void Merge(float vet[], int inicio, int meio, int fim, float aux[]){
	int p=inicio;
	int j=meio+1;
	for(int i=inicio;i<=fim;i++){
		aux[i]=vet[i];
	}
	for(int i=inicio;i<=fim;i++){
		if(p>meio) vet[i]=aux[j++];
		else if(j>fim) vet[i]=aux[p++];
		else if(aux[i]<aux[j]) vet[i]=aux[p++];
		else vet[i]=aux[j++];
	}
}
//~ MergeSort(vet,0, n-1, aux);
//lo é o primeiro elemento do vetor = 0
//hi é a ultima posição do vetor = n-1
void MergeSort(float vet[], int inicio, int fim, float aux[]){
	if (fim<=inicio) return;
	//Dividindo o vetor ao meio	
	int meio=inicio+(fim-inicio)/2;
	//CHAMANDO O VETOR PARA AS DUAS METADES DO MESMO
	//Metade de 0 até o meio
	MergeSort(vet, inicio, meio, aux);
	//Metade de meio até o fim
	MergeSort(vet, meio+1, fim, aux);
	//Jntando as partes ordenadas
	Merge(vet,inicio, meio, fim, aux);
}
void LeVetor(float vet[], int n, int i){
	if(i==n) return;
	cin>>vet[i];
	LeVetor(vet, n, i+1);
}
void PrintVetor(float vet[], int n, int i){
	if(i==n){ 
		cout<<endl;
		return;
	}
	cout<<vet[i]<<" ";
	PrintVetor(vet, n, i+1);
}
void EncontrarMed(float vet[], int n){
	int miolo, mediana;
	if(n>2){
		if(n%2==0){
			miolo = n/2;
			mediana = (vet[miolo-1]+vet[miolo])/2;
			cout<<"A Mediana é :"<<mediana;
		}
		else{
			miolo =n/2;
			mediana = vet[miolo];
			cout<<"A Mediana é :"<<mediana;
		}
	}
}
int main(){
	int n;
	cin>>n;
	float vet[n], aux[n];
	LeVetor(vet, n, 0);
	MergeSort(vet, 0, n-1, aux);
	PrintVetor(vet, n, 0);
	cout<<"\n\n-----------\n\n";
	EncontrarMed(vet, n);
	return 0;
}
