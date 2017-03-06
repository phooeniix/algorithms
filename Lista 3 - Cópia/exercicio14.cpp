/*Autor: Alexandre Carvalho
 * Obter o MMC de dois numeros
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int num1, num2, mmc, aux;
	//Informe o que o usuário deverá fazer
	cout<<"Escreva dois números para saber o seu MMC: \n";
	//Lendo os dois números
	cin>>num1>>num2;
	//MMC é igual um vezes o outro
	mmc=num1*num2;
	aux=(mmc/2)-1;
	//Agora vamos ver se ele já chegou ao final ou se tem como diminui-lo
	for(int i=0;i<aux;i++){
		if((mmc%2)==0){
			mmc/=2;
		}else{
			if(mmc%3==0){
				mmc/=3;
			}else{
				if(mmc%5==0){
					mmc/=5;
				}
			}
		}
	}
	cout<<mmc;
		
		
		
	//A função retornou sem erros de compilação
	return 0;
}
