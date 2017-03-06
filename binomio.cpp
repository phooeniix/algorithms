#include <iostream>
using namespace std;
int Binomio(int x, int y){
	if(y==0) return 1;
	if(x==y) return 1;
	return Binomio(x-1, y-1)+ Binomio(x-1, y);
}
int main(){
	int a, b;
	cin>>a>>b;
	cout<<Binomio(a,b);
	return 0;
}
