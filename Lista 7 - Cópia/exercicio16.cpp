/* Autor: Alexandre Carvalho
 * 
 * Faça um programa que tem uma função para procurar um elemento
 * numa matriz 2D. A função deve retornar um booleano que indica
 * se o elemento foi encontrado, além dos índices 
 * indicando a posição do elemento.
 * 
 * */
#include <iostream>
using namespace std;
void LeMatriz(int x,int y,int m[][]){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>m[i][j];
		}
	}
}
void PrintMatriz(int x,int y,int m[][]){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<m[i][j];
		}
	}
}
int Busca(int x, int y,int m[][], int b){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(b==m[i][j]){
				cout<<i<<" "<<j<<endl;
				return true;
			}
		}
	}
}
int main(){
	int l, c, busca;
	cin>>l>>c;
	int matriz[l][c];
	LeMatriz(l, c, matriz[l][c]);
	PrintMatriz(l, c, matriz[l][c]);
	cin>>busca;
	Busca(l, c, matriz[l][c], busca);
	return 0;
}
