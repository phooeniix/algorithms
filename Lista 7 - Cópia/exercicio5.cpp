/*Autor: Alexandre Carvalho
 * Retornar o maior ou menor
 * 
 * */
#include <iostream>
using namespace std;
float Max(float x, float y){
	if(x>y)
		return x;
	else return y;
}
int main(){
	float a, b;
	cin>>a>>b;
	cout<<Max(a, b);
	//A função retornou sem erros
	return 0;
}
