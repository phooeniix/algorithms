#include <iostream>
using namespace std;
void Troca(int &a, int &b){
	float aux = a;
	a=b;
	b=aux;
}
void Selection(int vet[], int n){
	int menor=0;
	for(int i=0;i<n-1;i++){
		menor=i;
		for(int j=i+1;j<n;j++){
			if(vet[i]>vet[j]){
				menor =j;
			}
		}
		Troca(vet[i], vet[menor]);
	}
}
void LeVetor(int vet[], int n, int i){
	if(i==n) return;
	cin>>vet[i];
	LeVetor(vet, n, i+1);
}
void PrintVetor(int vet[], int n, int i){
	if(i==n){cout<<endl;return;}
	cout<<vet[i]<<" ";
	PrintVetor(vet, n, i+1);
}
int main(){
	int n;
	cin>>n;
	int vet[n];
	LeVetor(vet, n, 0);
	for(int i=0; i<n;i++){
		if(vet[i]%2!=0){
			Selection(vet, n);
		}
	}
	
	PrintVetor(vet, n, 0);
	
	return 0;
}
