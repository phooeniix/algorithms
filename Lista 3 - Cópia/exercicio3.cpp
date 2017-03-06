/*Autor: Alexandre Carvalho
 * faça uma tabuada de 1 até 10
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int i,j;
	
	//Dispara um for para rodar de 0 até 10
	for(i=0;i<=10;i++){
		cout<<"*--------------------------------------------*\n";
		cout<<endl;
		cout<<"A tabuada de " <<i<< " é igual a : \n";
		//Aqui dentro ele vai rodar de 1 até 10 vai ser o "número" a ser multiplicado
		for(j=0;j<=10;j++){
			cout<<i<<" * "<<j<<" = "<<i*j<<"\n";
			cout<<endl;
		}
	}
	
	//A função retornou sem erros de compilação
	return 0;
}
