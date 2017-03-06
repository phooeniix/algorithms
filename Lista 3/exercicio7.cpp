/*Autor: Alexandre Carvalho
 * Chico tem 1,5 cresce 2cm
 * Zé tem 1,1 cresce 3cm
 * Quantos anos para Ze ser maior
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	float hChico=1.5, hZe=1.1, ano;
	while(hZe<hChico){
		ano++;
		hChico+=0.02;
		hZe+=0.03;
	}
		
	cout<<"Levará "<<ano<<" anos para o Zé ficar maior";
	//A função retornou sem erros de compilação
	return 0;
}
