#include <iostream>
using namespace std;
float Divisao(int i, int n, float vet[]){
	if(i==(n-1)) return vet[i]; 
	return Divisao(i+1, n, vet)/(float)vet[i];
}
void LeVetor(int i, int n, float vet[]){
	if(i==n) return;
	cin>>vet[i];
	LeVetor(i+1, n, vet);
}
void PrintVetor(int i, int n, float vet[]){
	if(i==n){
		cout<<endl;
		return;
	}
	cout<<vet[i]<<" ";
	PrintVetor(i+1, n, vet);

}
int main(){
	int x;
	cin>>x;
	float vetor[x];
	LeVetor(0,x, vetor);
	//~ PrintVetor(0,x, vetor);
	cout<<Divisao(0, x, vetor);
	return 0;
}
