#include <iostream>
using namespace std;
int main(){
	double a, b;
	double *soma = new double;
	cin>>a>>b;
	*soma = a + b;
	cout<<*soma<<endl;
	delete soma;
	return 0;
}
