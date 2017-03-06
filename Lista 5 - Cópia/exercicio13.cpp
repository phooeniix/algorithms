/*Autor: Alexandre Carvalho
 * 
 * Receba: 
 * 	Um vetor com o nome de 5 produtos
 * 	Uma matriz 5x4 com os preços dos cinco produtos em quatro lojas diferentes
 * 	outro vetor com o custo do transporte dos cinco produtos
 * 	Uma matriz com o valor coms os impostos de cada produto
 * TABELA :
 * ATÉ 50R$ 5
 * De de 50,1 até 100  é 10
 * acima de 100 é 20
 * 
 * */
#include <iostream>
#include <string>
#define produto 5
#define loja 4
using namespace std;
int main(){
	//Declaram variáveis
	char vetProduto[produto][100];
	float valorProduto[produto][loja], comImposto[produto][loja], imposto=0;
	for(int i=0;i<produto;i++){
		cout<<"Produto ["<<i+1<<"] ";
		cin>>vetProduto[i];
	}
	for(int i=0;i<produto;i++){
		for(int j=0;j<loja;j++){
			cout<<"Produto ["<<vetProduto[i]<<"] "<<"Loja ["<<j+1<<"]: ";
			cin>>valorProduto[i][j];
		}
	}
	cout<<"\n Tabela de valores: \n";
	for(int i=0;i<produto;i++){
		//~ cout<<"Produto ["<<vetProduto[i]<<" ] ";	
		for(int j=0;j<loja;j++){
			cout<<"["<<valorProduto[i][j]<<"] ";
		}
		cout<<endl;
	}
	for(int i=0;i<produto;i++){
		for(int j=0;j<loja;j++){
			int n = valorProduto[i][j];
			if((n<=50)and(n>=0)){
				imposto = 0.05;
				comImposto[i][j] = (n*(1+imposto));
			}else{
				if((n<=100)and(n>50)){
					imposto = 0.1;
					comImposto[i][j] = (n*(1+imposto));	
				}else{
					if(n>100){
						imposto=0.2;
						comImposto[i][j] = (n*(1+imposto));
					}
				}
			}
		}
	}
	cout<<"\n\n*----------------------------------*\n\n";
	cout<<" Tabala com os impostos :\n";
	for(int i=0;i<produto;i++){
		//~ cout<<"Produto ["<<vetProduto[i]<<" ] ";ng
		for(int j=0;j<loja;j++){
			cout<<"["<<comImposto[i][j]<<"] ";
		}
		cout<<endl;
	}
	
	

	return 0;
}
