#include <iostream>
using namespace std;
struct MegaSena{
	int mega[5];
};

int* soma(int **matriz, int nSorteios){
	int soma=0, maior=0, aux;
	for(int i=0;i<nSorteios;i++){
		soma=0;
		for(int j=0;j<6;j++){
			soma += matriz[i][j];
			if(soma>maior){
				maior = soma;
				aux = nSorteios;
			}
		}
	}
	int *vetor;
	vetor = new int[5];
	for(int i=0;i<6;i++)
		vetor[i]=matriz[aux][i];
	
	return vetor;
}

void scanMatriz(int **matriz, int nSorteios, int k, int i, int j ){
	if(i==nSorteios) return;
	cin>>matriz[i][j];
	j++;
	if(j==k){j=0;i++;}
	scanMatriz(matriz, nSorteios, k, i, j);
	
}
void delMatriz(int **matriz, int l){
	for(int i=0;i<l;i++)
		delete [] matriz[i];
	delete [] matriz;
}
void printVet(int *vet, int n, int i){
	if(i==n){cout<<endl;return;}
	cout<<vet[i]<<" ";
	printVet(vet, n, i+1);
}
int main(){
	int nSorteios, k=5;
	cin>>nSorteios;
	//~ MegaSena Maior;
	int **matriz;
	matriz = new int *[nSorteios];
	for(int i=0;i<nSorteios;i++)
		matriz[i]=new int[k];
		
	scanMatriz(matriz, nSorteios, 6, 0, 0);
	int *f = soma(matriz, nSorteios);
	
	printVet(f, 6, 0);
	
	//~ for(int i=0;i<=k;i++)
		//~ cout<<Maior.mega[i];
	

	delMatriz(matriz, nSorteios);
	delete [] f;

	return 0;
}
