/*Alexandre Carvalho
 * 
 * Implemente quatro versões diferentes do método de ordenação BubbleSort:
 *	 1. A versão mais comum que leva os maiores elementos para o final do vetor.
 *	 2. Uma versão alternativa que leva os menores elementos para o início do vetor.
 *	 3. Ordenação inversa levando os maiores elementos para o início do vetor.
 *	 4. Ordenação inversa levando os menores elementos para o final do vetor.
 * 
 * */
#include <iostream>
using namespace std;
void Troca(float &a, float &b){
	int aux=a;
	a=b;
	b=aux;
}

bool Verifica(int n, float vet[]){
	for(int i=0;i<n-1;i++){
		if(vet[i]>vet[i+1]) return false;
	}
	return true;
}
bool Verifica2(int n, float vet[]){
	for(int i=0;i<n-1;i++){
		if(vet[i]>vet[i+1]) return false;
	}
	return true;
}
float LeVetor(int n, float vet[], int i){
	if(i==n) return 0;
	cin>>vet[i];
	return LeVetor(n, vet, i+1);
}
float PrintVetor(int n, float vet[], int i){
	if(i==n){
		cout<<endl;
		return 0;
	}		
	cout<<vet[i]<<" ";
	return PrintVetor(n, vet, i+1);
}
void BubbleSort1(int n, float vet[]){
	int k=n-1;
	while(!Verifica(n, vet)){	
		for(int i=0;i<k;i++){
			if(vet[i]>vet[i+1]){
				Troca(vet[i], vet[i+1]);
			}
		}
	}
}
void BubbleSort2(int n, float vet[]){
	int k=n-1;
	while(!Verifica(n, vet)){	
		for(int i=0;i<k;i++){
			if(vet[i]<vet[i+1]){
				Troca(vet[i], vet[i+1]);
			}
		}
	}
}
void BubbleSort3(int n, float vet[]){
	int k=n-1;
	while(!Verifica2(n, vet)){	
		for(int i=0;i<k;i++){
			if(vet[i]>vet[i+1]){
				Troca(vet[i+1], vet[i]);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	float vet[n];
	LeVetor(n, vet, 0);
	BubbleSort3(n, vet);
	PrintVetor(n, vet, 0);
	return 0;
}
