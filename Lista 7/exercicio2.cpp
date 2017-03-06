/*Autor: Alexandre Carvalho
 * Somar 2 números utilizando parametros por referencia
 * 
 * */
#include <iostream>
using namespace std;
void Soma(float x, float y, float &somar){
	somar = x+y;
	cout<<somar;
}
int main(){
	float a, b, c=0;
	cin>>a>>b;
	Soma(a, b, c);
	//A função retornou sem erros
	return 0;
}
