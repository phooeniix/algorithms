#include <iostream>
#define tamanho 5
using namespace std;
int main(){
	//Declarando variáveis
	int bingo[tamanho][tamanho], somaL=0, somaC=0,somaS=0, somaD=0;
	for(int i=0;i<tamanho;i++){
		for(int j=0;j<tamanho;j++){
			cin>>bingo[i][j];
		}
	}
	for(int i=0;i<tamanho;i++){
		for(int j=0;j<tamanho;j++){
			if((i+j)==j){
				somaL+=bingo[i][j];
			}
			if((i+j)==i){
				somaC+=bingo[i][j];
			}
			if((i+j)==(tamanho-1)){
				somaS+=bingo[i][j];
			}
			if(i==j){
				somaD+=bingo[i][j];
			}
		}
	}
	if(somaL==5){
		cout<<1<<endl;
	}else{
		if(somaC==5){
			cout<<2<<endl;
		}else{
			if(somaD==5){
				cout<<3<<endl;
			}else{
				if(somaS==5){
					cout<<4<<endl;
				}
			}
		}
	}
	if(somaL!=5 and somaC!=5 and somaD!=5 and somaS!=5){
		cout<<-1;
	}
	
	//A função retornou sem erros de compilação
}
