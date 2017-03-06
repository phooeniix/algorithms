#include <iostream>
using namespace std;
void scanMatriz(double **matriz, int l, int c, int i, int j){
	if(i==l)return;
	cin>>matriz[i][j];
	j++;
	if(j==c){j=0;i++;}
	scanMatriz(matriz, l, c, i, j);
}
int main(){
	int l, c;
	cin>>l>>c;
	double **matriz;
	matriz = new double*[l];
	for(int i=0;i<l;i++){
		matriz[i] = new double[c];
	}
	scanMatriz(matriz, l, c, 0, 0);	
	for(int i=0;i<l;i++){
		delete [] matriz[i];
	}
	delete [] matriz;
	return 0;
}
