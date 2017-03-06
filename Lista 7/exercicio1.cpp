#include <iostream>
using namespace std;
int Soma(float x, float y){
	float soma;
	soma = x+y;
	return soma;
}
int main(){
	float a, b;
	cin>>a>>b;
	cout<<Soma(a, b);
	//A função retornou sem erros
	return 0;
}
