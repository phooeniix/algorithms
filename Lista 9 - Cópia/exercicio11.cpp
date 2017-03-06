#include <iostream>
using namespace std;
void scanMatriz(int **matriz, int l, int c, int i, int j){
	if(l==i) return;
	cin>>matriz[i][j];
	j++;
	if(j==c){j=0;i++;}
	scanMatriz(matriz, l, c, i, j);
}
int somaMatriz(int **matriz, int *vetor, int l, int c){
	int soma=0, k=0;
	for(int i=0;i<l;i++){
		soma=0;
		for(int j=0;j<c;j++){
			soma+=matriz[i][j];
		}
		vetor[k]=soma;
		k++;
	}
	return *vetor;
}
void printVet(int *vet, int n, int i){
	if(i==n){cout<<endl;return;}
	cout<<vet[i]<<" ";
	printVet(vet, n, i+1);
}

int main(){
	int l, c;
	int **matriz;
	int *vetor;
	cin>>l>>c;
	vetor=new int[l];
	matriz=new int*[l];
	for(int i=0;i<l;i++){
		matriz[i]=new int[c];
	}
	scanMatriz(matriz, l, c, 0, 0);
	
	somaMatriz(matriz, vetor, l, c);
	
	printVet(vetor, l, 0);
		
	for(int i=0;i<l;i++){
		delete [] matriz[i];
	}
	delete [] matriz;
	
	return 0;
}
