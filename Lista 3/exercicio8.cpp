/*Autor: Alexandre Carvalho
 * Recebe o primeiro elemento de uma PG
 * Receba a razão
 * O numero de elementos a serem exibidos
 * */
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Declarando as variáveis
	int primeiroElement, razao, nElements,element;
	//Pedindo para o usuário fornecer os dados
	cout<<"Forneça o primeiro elemento da PG: \n";
	cin>>primeiroElement;
	cout<<"Forneça a razão da PG: \n";
	cin>>razao;
	cout<<"Quantos elementos você quer que apareça na tela: \n";
	cin>>nElements;
	for(int i=0;i<=nElements;i++){
		element=primeiroElement*pow(razao,(i));
		cout<<element<<" ";
	}
	//A função retornou sem erros de compilação
	return 0;
}
