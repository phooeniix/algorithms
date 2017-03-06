/*Autor Alexandre Carvalho
 * 
 * Calcular a médias dos elementos abaixo da diagonal secundária
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variaveis
	int n;
	cin>>n;
	float matriz[n][n];
	//Lendo a matriz
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matriz[i][j];
		}
	}
	//Calculando a média
	int cont=0;
	float soma=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//Tem que ser n -1 porque a matriz começa em 0 uma posiçao a mais portanto tem que ser n-1
			if((i+j)>(n-1)){
				soma+=matriz[i][j];
				cont++;
			}
		}
	}
	cout<<soma/cont<<endl;
	//A função retornou sem erros
	return 0;
}
