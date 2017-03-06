#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Declarando as variáveis
	int i, j, a, b, resultado;
	cout<<"Escreva dois número A e B: \n";
	cin>>a>>b;
	for(i=0;i<=a;i++){
		for(j=0;j<=b;j++){
			//~ resultado=((a+b));
			resultado+=((a+b)+pow(j,2)+2*j*i+pow(i,2));
		}	
	}
	cout<<"O resultado do somatório é igual a: " <<resultado;

	//A função retornou normalmente sem erros de compilação
	return 0;
}
