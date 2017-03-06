/*Autor: Alexandre Carvalho
 * Leia valores ideterminados na tela
 * calcule a media
 * conte quantos negativos e positivos 
 * e o percentual de valores positivos e negativos
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int numero,aux, cont=0, contPositivo=0, contNegativo=0;
	float media=0;
	char valorDigitado;
	cout<<"Escreva quantos números quiser\n";
	cout<<"Para deixa o programa digite (s)\n";
	do{
		cont++;
		cin>>valorDigitado;
		aux=(int)valorDigitado;
		numero+=aux;
		media=numero/cont;
		//~ cout<<media<<endl<<numero;
		if(numero>0){
			contPositivo++;
		}else{
			contNegativo++;
		}
	}while(!(valorDigitado=-1));
	
	cout<<"A Média dos valores digitados é igual a: "<<media<<endl;
	
	cout<<"O usuário digitou "<<contPositivo<<"Valores positivos"<<endl;
	cout<<"O usuário digitou "<<contNegativo<<"Valores negativos"<<endl;
	
	cout<<"O usuário digitou "<<(contPositivo/cont)*100<<"% de valores positivos;"<<endl;
	cout<<"O usuário digitou "<<(contNegativo/cont)*100<<"% de valores negativos;"<<endl;
	
	
	
	//A função retornou sem erros de compilação
	return 0;
}
