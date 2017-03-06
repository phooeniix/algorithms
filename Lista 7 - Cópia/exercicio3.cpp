/*Autor: Alexandre Carvalho
 * Retornar o (true)maior e o menor(false)
 * 
 * */
#include <iostream>
using namespace std;
float Maior(float x, float y){
	if(x>y)
		return true;
	else return false;
}
int main(){
	float a, b;
	cin>>a>>b;
	cout<<Maior(a, b);
	//A função retornou sem erros
	return 0;
}
