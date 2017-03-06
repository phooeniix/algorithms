/*Autor: Alexandre Carvalho
 * Calcule a tabuada de um número
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int numero;
	cout<<"Digite um número para saber a sua tabuada: \n";
	cin>>numero;
	cout<<"A tabuada do número "<<numero<<" é igual a : \n";
	//Dispara um for de 0 até 10 para realizar a tabuada
	for (int i=0;i<=10;i++){
		cout<<numero<<" * "<<i<<" = "<<numero*i<<endl;
	}
	//A função retornou sem erros de compilação
	return 0;
}
