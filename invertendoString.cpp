/*
 * Autor : Alexandre Carvalho	
 * 
 * */
#include <iostream>
//Incluindo a biblioteca String para utilizar
#include <string>
using namespace std;
int main(){
	//Declarando as variaveis
	string frase;
	//Lendo a string até apertar enter
	getline(cin, frase);
	//Declarando a variavel aqui, pois desejo ter o numero de caracteres do que foi digitado
	int n=frase.length();
	//Disparando um for até a metade da palavra para trocar as posições
	for (int i=0;i<n/2;i++){
		//Declarando a variavel c como caracter para a cada loop receber o ultimo caracter e colocar ele no inicio
		char c = frase[i];
		//pegando o ultimo caracter
		frase[i] = frase[n-1-i];
		//colocando ele no inicio
		frase[n-1-i] = c;
	}
	//Escrevendo a palavra o contrário
	cout<<frase <<endl;
	
	return 0;
}
