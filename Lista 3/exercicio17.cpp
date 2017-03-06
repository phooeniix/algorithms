/*Autor: Alexandre Carvalho
 * Eleições
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int opcao=0, candidato1=0,candidato2=0, candidato3=0, candidato4=0, nulo=0, branco=0, soma=0;
	//Informe o que o usuário deverá fazer
	cout<<"Eleições Exercicio 17: \n";
	cout<<"Digite o número das opções abaixo para votar\n";
	cout<<"1 - Para votar no candidato 1.\n";
	cout<<"2 - Para votar no candidato 2.\n";
	cout<<"3 - Para votar no candidato 3.\n";
	cout<<"4 - Para votar no candidato 4.\n";
	cout<<"5 - Para votar nulo.\n";
	cout<<"6 - Para votar em branco.\n";
	cout<<"7 - Parar o programa.\n";
	cout<<"*----------------------------*\n";
	do{
		cin>>opcao;
		switch(opcao){
			case 1:
				candidato1++;
			break;
			case 2:
				candidato2++;
			break;
			case 3:
				candidato3++;
			break;
			case 4:
				candidato4++;
			break;
			case 5:
				nulo++;
			break;
			case 6:
				branco++;
			break;
			default:
				cout<<"Por favor jumento, eu quero um valor válido.\nTenha santa Paciência!\n";
			break;
		}
		//O programa vai sair quando o usuário digitar 7
	}while(!(opcao==7));
	//somando o total de votos
	soma = candidato1+candidato2+candidato3+candidato4+nulo+branco;
	//Escrevendo os resultados das opcoes
	
	//Escrevendo o total de votos de cada candidato
	
	cout<<"O total de votos para o candidato 1 foi de: "<<candidato1<<endl;
	cout<<"O total de votos para o candidato 2 foi de: "<<candidato2<<endl;
	cout<<"O total de votos para o candidato 3 foi de: "<<candidato3<<endl;
	cout<<"O total de votos para o candidato 4 foi de: "<<candidato4<<endl;
	cout<<"*------------------------------------------------------*\n";
	cout<<"O total de votos nulos foi de: "<<nulo<<endl;
	cout<<"O total de votos em branco foi de: "<<branco<<endl;
	cout<<"*------------------------------------------------------*\n";
	//Porcentagem dos nulos
	cout<<"A porcentagem de votos nulos foi de: "<<(nulo*100)/soma<<"%"<<endl;
	//Porcentagem dos brancos
	cout<<"A porcentagem de votos brancos foi de: "<<(branco*100)/soma<<"%"<<endl;
	cout<<"*------------------------------------------------------*\n";
	// Votos válidos sem os nulos e brancos
	cout<<"O número de votos válidos:"<<soma-(nulo+branco)<<endl;
	
	//A função retornou sem erros de compilação
	return 0;
}
