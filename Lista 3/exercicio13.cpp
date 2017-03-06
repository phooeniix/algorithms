/*Autor: Alexandre Carvalho
 * dado uma posição
 * informe qual o numero correspondente na sequencia de fibonacci
 * */
#include <iostream>
using namespace std;
int main(){
	//Declarando as variáveis
	int numero,a, b, aux;
	cout<<"Qual numero de qual posição você deseja saber? \n";
	cin>>numero;
	a=0;
	b=1;
	cout<<" 1 ";
	for(int i=0;i<numero;i++){
		if(numero<2){
			aux=1;
		}else{
			aux = a+b;
			a=b;
			b=aux;
			cout<<aux<<"  ";
		}
	}
	
	//A função retornou sem erros de compilação
	return 0;
}
