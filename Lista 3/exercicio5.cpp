#include <iostream>
using namespace std;
int main(){
	//Declarando variaveis
	float salario,mediaSalario=0, mediaFilho=0, maiorSalario;
	int pessoas=0,nFilhos;
	
	
	do{
		cout<<"Qual o seu salário: \n";
		cin>>salario;
		maiorSalario=salario;
		cout<<"Número de filhos: \n";
		cin>>nFilhos;
		pessoas++;
		mediaSalario=salario/pessoas;
		mediaFilho=nFilhos/pessoas;
		if(salario>maiorSalario){
			maiorSalario=salario;
		}
	}while(salario>0);
	cout<<"A média dos salários é "<<mediaSalario<<endl;
	cout<<"A média dos filhos é "<<mediaFilho<<endl;
	cout<<"O maior salário"<<maiorSalario<<endl;
	
	
	//A função  retornou sem erros
	return 0;
}
