/*Autor: Alexandre Carvalho
 * Numeros aleatorios
 * 
 * */
#include <iostream>
#include <stdlib.h>
using namespace std;
int Aleatorio(int x){	
	int y;
	srand(time(NULL));
	y = rand()%x;
	return y;
}
int main(){
	int n;
	cin>>n;
	cout<<Aleatorio(n);
	//A função retornou sem erros
	return 0;
}
