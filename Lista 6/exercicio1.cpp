/*Ler vários alunos com matricula nome matricula e nota em 3 disciplinas
 * procure o aluno com a maior media e exiba todos os dados do mesmo
 * 
 * */

#include <iostream>
#include <string>
using namespace std;
//Registro de aluno
struct Aluno{
	int matricula;
	string nome;
	string situacao;
	float disciplinas[3];
	float media;
	float soma;
};
//~ return valor == 0;	
//~ //classe principal
int main(){
	int n, posicao;
	int maior = -121312312;
	cin>>n;
	Aluno alunos[n];
	for(int i=0;i<n;i++){
		cin>>alunos[i].matricula;
		cin>>alunos[i].nome;
		cin>>alunos[i].disciplinas[0];
		cin>>alunos[i].disciplinas[1];
		cin>>alunos[i].disciplinas[2];
	}
	for(int i=0;i<n;i++){
		alunos[i].media = (alunos[i].disciplinas[0]+alunos[i].disciplinas[1]+alunos[i].disciplinas[2])/3;
		if(alunos[i].media>=6)
			alunos[i].situacao = "APROVADO";
		else
			alunos[i].situacao = "REPROVADO";
		if(alunos[i].media>=maior){
			maior = alunos[i].media;
			posicao = i;
			
		}
	}
	//(media >=6)? hjjhhj : gjggjjg;
	cout<<"\n\n------Exibindo o aluno com a melhor média-------\n\n";
	cout<<alunos[posicao].matricula<<" ";
	cout<<alunos[posicao].nome<<" ";
	cout<<alunos[posicao].media<<" ";
	cout<<alunos[posicao].situacao<<endl;
	
	//A  função retornou sem erros de compilação
	return 0;
}
