#include <iostream>
using namespace std;
struct Ponto{
	int a;
	int b;
};
struct Retangulo{
	Ponto V1;
	Ponto V2;
};
int main(){
	Ponto p;
	cin>>p.a>>p.b;
	int n;
	cin>>n;
	Retangulo ret[n];
	for(int i=0;i<n;i++){
		cin>>ret[i].V1.a;
		cin>>ret[i].V1.b;
		cin>>ret[i].V2.a;
		cin>>ret[i].V2.b;
	}
	int cont=0;
	for(int i=0;i<n;i++){
		if(p.a>ret[i].V1.a and p.b>ret[i].V1.b and p.a<ret[i].V2.a and p.b<ret[i].V2.b)
			cont++;
	}
	cout<<cont;
	return 0;
}
