#include <iostream>
using namespace std;
int main(){
	int n, pRemover, novoValor, remove;
	cin>>n;
	int vetor[n];
	for (int i=0;i<n;i++){
		cout<<i<<" = ";
		cin>>vetor[i];
	}
	for(int i=0;i<n;i++){
		cout<<vetor[i] <<" ";
	}
	cout<<endl;
	cout<<"Quantos valores você quer modificar?\n";
	cin>>pRemover;
	
	for(int i=0;i<pRemover;i++){
		cout<<"Qual posição você quer remover?\n";
		cin>>remove;
		if(remove<=(n)){
			cout<<"Escreva o novo valor.\n";
			cin>>novoValor;
			vetor[remove]=novoValor;
		}else{
			cout<<"Você digitou uma posição superior ao tamanho do vetor. \n";
		}
	}
	
	
	for(int i=0;i<n;i++){
		cout<<vetor[i] <<" ";
	}
	cout<<endl;
	return 0;
}
