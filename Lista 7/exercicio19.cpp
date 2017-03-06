/*Autor: Alexandre Carvalho
 * 
 * A multiplicação de dois números inteiros pode ser feita através
 * de somas sucessivas (por exemplo, 2 * 3 = 2 + 2 + 2).
 * Crie uma função recursiva que calcule a multiplicação
 * por somas sucessivas de dois números inteiros.
 * 
 * */
#include <iostream>
 using namespace std;
int Mult(int a, int b){
	if(b==0)
		return 0;
	else
		return a+ Mult(a, b-1);
}
 int main(){
	 int x, y;
	 cin>>x>>y;
	 cout<<Mult(x, y);
	return 0;
}
