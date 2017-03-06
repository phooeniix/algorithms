/*
 * Autor: Alexandre Carvalho
 * Faça uma matriz 10X3 leia a nota de 10 alunos em 3 provas 
 * Mostre um relatório com o numero dos alunos (linha) 
 * e a prova em que teve a menor nota
 * 
 * */
#include <iostream>
#define alunos 10
#define notas 3
using namespace std;
int main(){
	//Declarando variaveis
	int matriz[alunos][notas], i, j;
	
	//Lendo matriz
	for(i=0;i<alunos;i++){
		for(j=0;j<notas;j++){
			cin>>matriz[i][j];
		}
	}	
	
	//A FUNÇÃO RETORNOU SEM ERROS
	return 0;
}
