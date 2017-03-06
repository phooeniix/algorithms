#include <iostream>
using namespace std;
void Naturais(int x){
	if(x==0){
		cout<< 0 <<" ";
	}else{
		Naturais(x-1);
		cout<<x<<" ";
	}	
}
int main(){
	int n;
	cin>>n;
	Naturais(n);
	//A função retornou sem erros de compilação
	return 0;
}
