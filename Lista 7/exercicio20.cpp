#include <iostream>
using namespace std;
int SomaN(int x){
	if(x<10){
		return x;
	}else{
		int aux1 = x%10;
		int aux2 = x/10;
		return aux1 + SomaN(aux2);
	}	
}
int main(){
	int n;
	cin>>n;
	cout<<SomaN(n);
	//A função retornou sem erros de compilação
	return 0;
}
