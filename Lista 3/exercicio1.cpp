/*Autor: Alexandre Carvalho
 * Leia 15 números e veja quantos são negativos
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	float numero=0;
	//Evitar o lixo de memória, coloque varíaveis começando com o valor 0
	int contador=0;
	//Escreva para o usuário o que é para fazer
	cout<<"Digite um número 15 vezes \n";
	//Dispara um for para ler o número 15 vezes
	for(int i=0;i<15;i++){
		cin>>numero;
		//Dispara um if para verificar se o número digitado é negativo
		//Se o número menor que zero acrescente mais um ao contador
		if(numero<0){
			contador++;
		}
		//Senão, quer dizer que o usuário só digitou números positivos
	}
	//Escreva quantos números negativos o usuário digitou
	cout<<"Você digitou " <<contador<<" números negativos!";
	//A função retornou sem erros de compilação
	return 0;
}
