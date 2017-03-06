#include <iostream>
#include <cmath>
using namespace std;
int main(){
	unsigned long int totalGraos=1;
	totalGraos=1;
	for (int i=0; i<63;i++){
		totalGraos+=  pow(2,i);
		// cout<<totalGraos;
	}
	
	cout<<"A rainha pagará no total "<<totalGraos;
return 0;
}
