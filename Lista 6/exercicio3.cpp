#include <iostream>
#include <string>
using namespace std;
struct Funcionarios{
	string nome;
	float nHoras, salario;
	char turnoT, categoria;
};
int main(){
	int n;
	cin>>n;
	Funcionarios funcionario[n];
	for (int i=0;i<n;i++){
		cin>>funcionario[i].nome;
		cin>>funcionario[i].nHoras;
		cin>>funcionario[i].turnoT;
		cin>>funcionario[i].categoria;
	}
	for (int i=0;i<n;i++){
		if(funcionario[i].categoria == 'G'){
			if(funcionario[i].turnoT=='N'){
				funcionario[i].salario = (funcionario[i].nHoras*(380*0.18));
			}else{
				funcionario[i].salario = (funcionario[i].nHoras*(380*0.15));
			}
		}else{
			if(funcionario[i].categoria == 'O'){
				if(funcionario[i].turnoT=='N'){
					funcionario[i].salario = (funcionario[i].nHoras*(380*0.13));
				}else{
					funcionario[i].salario = (funcionario[i].nHoras*(380*0.10));
				}
			}
		}
		cout<<"\n\n"funcionario[i].nome<<" - R$"<<funcionario[i].salario<<endl;
	}
	
	//A função retornou sem erros de compilação
	return 0;
}
