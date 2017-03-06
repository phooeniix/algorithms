w/*
 * Autor:Alexandre Carvalho
 *
 * Ler um vetor de 9 posiçoões e verificando todos os primos
 * */
#include <iostream>
#include <cmath>
#define batata 9
using namespace std;

int main(){
	//Declarando variáveis
	int vetor[batata], i, cont;
	//Disparando um for com o número de posições do vetor para ler todos os valores para aloca-los
	for(i=0;i<batata;i++){
		//Lendo o vetor
		cout<<"Posição["<<i<<"]:";
		cin>>vetor[i];
	}
	//Disparando um vetor para escrever na tela
	for(i=0;i<batata;i++){
		//Sempre reinicializando a variavel cont
		cont=0;
		int n = vetor[i];
		n=sqrt(n);
		//Disparando um for de 2 até o numero -1 para saber se ele é primo
		for(int j=2;j<n;j++){

			//Se o número encontrar algum divisor no caminho cont recebe mais um
			//Se cont receber algo quer dizer que ele não é primo
			if(n%j==0){
				//atribuindo valor de cont se encontrar divisor
				cont++;
			}
		}
		//Comparando se a variavel cont indicou algum numero primo
		if(cont==0){
			//Escrevendo a posição do numero primo
			cout<<"Posição["<<i<<"]: "<<vetor[i]<<" é primo.\n";
		}
	}

	//A função retornou sem erros
	return 0;
}
