#include <iostream>
#include <string>
using namespace std;
struct Pacientes{
	string nome;
	char sexo;
	float altura, peso, pesoIdeal;
};
int main(){
	int n, posicao;
	float maiorPeso=-123;
	cin>>n;
	Pacientes paciente[n];
	for(int i=0; i<n;i++){
		cin>>paciente[i].nome;
		cin>>paciente[i].sexo;
		cin>>paciente[i].altura;
		cin>>paciente[i].peso;
	}
	for(int i=0;i<n;i++){
		if(paciente[i].sexo == 'M')
			paciente[i].pesoIdeal = ((72.7*paciente[i].altura)-58);
		else
			paciente[i].pesoIdeal = ((62.1*paciente[i].altura)-44.7);
		if(paciente[i].peso>maiorPeso){
			maiorPeso = paciente[i].peso;
			posicao = i;
		}
	}
	cout<<"\n\n"<<paciente[posicao].nome<<endl;
	for(int i=0;i<n;i++){
		if(paciente[i].peso>paciente[i].pesoIdeal){
			cout<<paciente[i].nome<<" ";
			cout<<paciente[i].pesoIdeal<<" ";
			cout<<paciente[i].peso-paciente[i].pesoIdeal<<endl;
		}
		if(paciente[i].peso<paciente[i].pesoIdeal){
			cout<<paciente[i].nome<<" ";
			cout<<paciente[i].pesoIdeal<<" ";
			cout<<"+"<<	paciente[i].pesoIdeal-paciente[i].peso<<endl;
		}
	}
	//A função retornou sem erros de compilação
	
	return 0;
}
