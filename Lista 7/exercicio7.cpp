/*Autor: Alexandre Carvalho
 * Media de dois numeros por parametro por cópia
 * 
 * */
#include <iostream>
using namespace std;
float Media(float x, float y){	
	return (x+y)/2;
}
int main(){
	float a, b;
	cin>>a>>b;
	cout<<Media(a, b);
	//A função retornou sem erros
	return 0;
}
