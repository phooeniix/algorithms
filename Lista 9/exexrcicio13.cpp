#include <iostream>
using namespace std;
void scanMatriz(int **matriz, int l, int c, int i, int j){
	if(l==i) return;
	cin>>matriz[i][j];
	j++;
	if(j==c){j=0;i++;}
	scanMatriz(matriz, l, c, i, j);
}
int* somaMatriz(int **matriz, int l, int c){
	int soma=0, *vetor;
	vetor = new int[l];
	for(int i=0;i<l;i++){
		soma=0;
		for(int j=0;j<c;j++)
			soma+=matriz[i][j];
		vetor[i]=soma;
	}
	return vetor;
}
void printVet(int *vet, int n, int i){
	if(i==n){cout<<endl;return;}
	cout<<vet[i]<<" ";
	printVet(vet, n, i+1);
}
void delMatriz(int **matriz, int l, int i){
	for(int i=0;i<l;i++)
		delete [] matriz[i];
	delete [] matriz;
}
int main(){
	int l, c, **matriz;
	cin>>l>>c;
	matriz=new int*[l];
	for(int i=0;i<l;i++)
		matriz[i]=new int[c];
	scanMatriz(matriz, l, c, 0, 0);
	int *j = somaMatriz(matriz, l, c);
	printVet(j, l, 0);
	delMatriz(matriz, l, 0);
	delete [] j;	
	return 0;
}
