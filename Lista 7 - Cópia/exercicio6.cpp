/*Autor: Alexandre Carvalho
 * Max_Vetor
 * 
 * */
#include <iostream>
using namespace std;
void LeVet(int x, float vet[]){
	for(int i=0;i<x;i++){
		cin>>vet[i];
	}
}
void PrintVet(int x, float vet[]){
	for(int i=0;i<x;i++){
		cout<<vet[i]<<" ";
	}
	
	cout<<endl;
}
float MaxVet(int x, float vet[]){
	float max=-123;
	for(int i=0;i<x;i++){
		if(vet[i]>max){
			max = vet[i];
		}
	}
	return max;
}
int main(){
	int n;
	cin>>n;
	float vetor[n];
	LeVet(n, vetor);
	PrintVet(n, vetor);
	cout<<MaxVet(n, vetor);
	//A função retornou sem erros
	return 0;
}
