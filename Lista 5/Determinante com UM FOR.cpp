#include<iostream>
using namespace std;
int main(){
	float m[3][3];
	float aux1=0,aux2=0, positivo=0, negativo=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>m[i][j];
		}
	}
	for(int i=0;i<3;i++){
		aux1=1;
		aux2=1;
		for(int j=0;j<3;j++){
			aux1*=m[j][(j+i)%3];
			aux2*=m[2-j][(j+i)%3];
		}
		positivo+=aux1;
		negativo+=aux2;
	}
	cout<<"O determinante é igual a "<< positivo - negativo <<endl;
	return 0;
}
