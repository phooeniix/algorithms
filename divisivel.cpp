#include <iostream>
using namespace std;
int main(){
	int numero;
	cout<<"Escolha o número: \n";
	cin>>numero;
	for(int i=0;i<numero;i++){
		if((i%3)==0){
			cout<<i<<" é divisivel por 3.\n";
		}
	}
	cout<<"--------------------------------------\n";
	for(int j=0;j<numero;j++){
		if((j%4)==0){
			cout<<j<<" é divisivel por 4.\n";
		}
	}
return 0;
}
