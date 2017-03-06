#include <iostream>
using namespace std;
void somaMatriz(double **matriz, int l, int c){
	double soma = 0;
	//~ Calculando a soma de elementos da matriz
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			soma+=matriz[i][j];
		}
	}
	cout<<soma<<endl;
}
void scanMatriz(double **matriz, int l, int c, int i, int j){
	if (i==l) return;
	cin >> matriz[i][j];
	j++;
	if (j==c) { j=0; i++;}
	scanMatriz(matriz,l,c,i,j);
}
void delMatriz(double **matriz, int l){
	for(int i=0;i<l;i++){
		delete [] matriz[i];
	}
	delete [] matriz;	
}

int main(){
	int l, c;
	double **matriz;
	cin>>l>>c;
	
	//~ Alocando um espaço de memória para receber a matriz
	matriz  = new double*[l];
	for(int i=0;i<l;i++){
		matriz[i]= new double[c];
	}
	
	//~ Aqui estou lendo os valores da matriz
	scanMatriz(matriz, l, c, 0, 0);
	
	//~ Chamando o subprograma para somar os elementos da matriz
	somaMatriz(matriz, l, c);
	
	delMatriz(matriz, l);
	
	return 0;
}
