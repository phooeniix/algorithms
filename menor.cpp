#include <iostream>
using namespace std;
void LeVetor(int n, float vet[]){
	for(int i=0;i<n;i++){
		cin>>vet[i];
	}
}
float Menor(int n, float vet[]){
	int i =n, menor=123;
	if(n==1) return vet[i-1];
	if(menor>vet[i]) menor=vet[i];
	return Menor(i-1, vet);
	cout<<menor;
}
int main(){
	int x;
	cin>>x;
	float vetor[x];
	LeVetor(x, vetor);
	cout<<Menor(x, vetor);
}
