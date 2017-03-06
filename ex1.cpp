#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	int mat[3][3], dp=1, ds=1, coluna=1, linha=1, ganhador=0;
	ifstream arquin("entrada.txt");
	//Lendo Matriz
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			arquin>>mat[i][j];
	//Diagonais
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int n = mat[i][j];
			if(i==j){
				dp*=n;
				if(dp==8)
					ganhador=2;
				if(dp==1)
					ganhador=1;	
			}
			if(i+j==2){
				ds*=n;
				if(ds==8)
					ganhador=2;
				if(ds==1)
					ganhador=1;
			}
		}
	}
	// Linhas Colunas
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int n = mat[i][j];
			if(i+j==i){
				linha*=n;
				if(linha==1)
					ganhador = 1;
				if(linha==8)
					ganhador = 2;
			}
			if(i+j==j)
				coluna*=n;
				if(coluna==1)
					ganhador=1;
				if(coluna==8)
					ganhador=2;
		}
	}
	cout<<ganhador<<endl;
	
	return 0;
}
