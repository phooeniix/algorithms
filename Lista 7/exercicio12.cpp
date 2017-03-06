/*Autor: Alexandre Carvalho
 * 0 100 APROVADO REPROVADO
 * 
 * */
#include <iostream>
#include <string>
using namespace std;
void Situacao(float x){
	string a, r, e;
	a = "APROVADO";
	r = "REPROVADO";
	e = "ERRO";
	if(x>=60) 
		cout<<a;
	else
		if(x<60 and x>=0) 
			cout<<r;
		else 
			cout<<e;	
}
int main(){
	float n;
	cin>>n;
	Situacao(n);
	//A função retornou sem erros
	return 0;
}
