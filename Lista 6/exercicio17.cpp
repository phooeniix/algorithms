#include <iostream>
#define batata 900
using namespace std;
struct Pessoa{
	string nome;
	int dia;
	int mes;
	int ano;
	int idade;
};
int main(){
	int i=0, d, m, a, maiorIdade=0, posicao;
	cin>>d>>m>>a;
	Pessoa pessoa[batata];
	pessoa[i].nome = "abc";
	while(!(pessoa[i].nome == "fim")){
		cin>>pessoa[i].nome;
		cin>>pessoa[i].dia;
		cin>>pessoa[i].mes;
		cin>>pessoa[i].ano;
		i++;
	}
	for(int j=0;j<i;j++){
		pessoa[i].idade = a-pessoa[i].ano;
	}
	for(int j=0;j<i;j++){
		if((pessoa[i].mes-m)<=0){
			if((pessoa[i].dia-d)<=0){
			}else{
				pessoa[i].idade--;
			}
		}else{
			pessoa[i].idade--;
		}
	}
	for(int j=0;j<i;j++){
		if(pessoa[i].idade>maiorIdade){
			maiorIdade = pessoa[i].idade;
			posicao = j;
		}
	}
	cout<<pessoa[posicao].nome<<endl;
	
	return 0;
}
