#include <iostream>
#include <string>
using namespace std;
struct Pessoas{
	string nome;
	int diaNasc, mesNasc, anoNasc, idade;
};
int main(){
	int n,d=0,m=0,a=0;
	cin>>n;
	Pessoas pessoa[n];
	for (int i=0;i<n;i++){
		cin>>pessoa[i].nome;
		cin>>pessoa[i].diaNasc;
		cin>>pessoa[i].mesNasc;
		cin>>pessoa[i].anoNasc;
	}
	cin>>d>>m>>a;
	for (int i=0;i<n;i++){
		pessoa[i].idade = a-pessoa[i].anoNasc;
		if(pessoa[i].idade<=0){
			cout<<-1;
		}else{
			if((pessoa[i].mesNasc-m)<=0){
				if((pessoa[i].diaNasc-d)<=0){
				}else{
					pessoa[i].idade-=1;
				}
			}else{
				pessoa[i].idade-=1;
			}
		}
		cout<< pessoa[i].nome<<": " <<pessoa[i].idade<<" anos."<<endl;
	}
	
	
	//A função retornou sem erros de compilação
	return 0;
}

