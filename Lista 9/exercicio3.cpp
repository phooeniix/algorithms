#include <iostream>
using namespace std;
void scanVet(int vetor[], int n, int i){
	if(i==n) return;
	cin>>vetor[i];
	scanVet(vetor, n, i+1);
}
int main(){
	int n;
	cin>>n;
	int *vetor = new int[n];
	scanVet(vetor, n, 0);
	
	cout<<&n<<endl;
	cout<<*vetor<<endl;
	int pP = vetor[0];
	cout<<&pP<<endl;
	int uP = vetor[n=1];
	cout<<&uP<<endl;
	
	delete [] vetor;
	return 0;
}
