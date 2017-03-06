#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Declarando as variáveis
	int numero=0, fatorial=1;
	cout<<"Escreva qual número você deseja fatorar: \n";
	cin>>numero;
	for (int i=1; i<=numero; i++){
		fatorial*=i;
	}
	if(numero==0){
		cout<<"Fatorial de "<<numero<<" é = a 1" ;
	}else{
		cout<<"Fatorial de "<<numero<<" é = "<<fatorial ;
	}

	//A função retornou normalmente sem erros de compilação
	return 0;
}
