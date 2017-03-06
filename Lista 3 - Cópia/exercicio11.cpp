#include <iostream>
using namespace std;
int main(){
	//Declarando variaveis
	int soldados, n, fila=0;
	cout<<"Escreva o número de soldados";
	cin>>soldados;
	n=soldados;
	while(n>0){
		fila++;
		n-=fila;
	}
	cout<<"O coronel dispos todos os soldados em "<<fila<<" fila(s)."<<endl;
	if(n<0){
		cout<<"Sobraram "<<fila+n<<" soldados na última fila."<<endl;
	}
	return 0;
}
