#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int i, j, cont;
	cont=0;
	for(i=0;i<=6;i++){
		for (j=0;j<6;j++){
			if((i+j)==7){
				cout<<i<<" com "<<j<<endl;
				cont++;
			}
		}
	}
	cout<<"O numero de combinações é "<<cont-1;

	//A função retornou normalmente sem erros de compilação
	return 0;
}
