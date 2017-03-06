/*Autor: Alexandre Carvalho
 * Leia 500 numeros
 * encontre o maior valor
 * calcule a media
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int numero, maior=0, menor, soma=0, media=0, cont;
	for(int i=0;i<5;i++){
		media=0;
		cont++;
		cin>>numero;
		soma+=numero;
		media=soma/cont;
		
		if(numero>maior){
			maior=numero;
		}else{
			if(numero<menor){
				menor=numero;
			}
		}
	}
	cout<<"O maior número é igual a "<<maior<<endl;
	cout<<"O menor número é igual a "<<menor<<endl;
	cout<<"A media dos numeros é igual a "<<media<<endl;
	
	
	//A função retornou sem erros de compilação
	return 0;
}
