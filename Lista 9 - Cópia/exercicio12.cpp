#include <iostream>
using namespace std;
void scanMatriz(int **matriz, int l, int c, int i, int j){
	if(l==i) return;
	cin>>matriz[i][j];
	j++;
	if(j==c){j=0;i++;}
	scanMatriz(matriz, l, c, i, j);
}
void searchValue(int **matriz, int l, int c){
	int valor, res=0;
	cin>>valor;
	for(int i=0;i<l;i++)
		for(int j=0;j<c;j++)
			if(matriz[i][j]==valor)
				res+=1;		
	if(res>=1)
		cout<<true;
	else
		cout<<false;
}
void delMatriz(int **matriz, int l){
	for(int i=0;i<l;i++)
		delete [] matriz[i];
	delete [] matriz;	
}
int main(){
	int l, c, **matriz;
	cin>>l>>c;
	matriz=new int*[l];
	for(int i=0;i<l;i++)
		matriz[i]=new int[c];
	scanMatriz(matriz, l, c, 0, 0);
	searchValue(matriz, l, c);
	
	delMatriz(matriz, l);	
	
	return 0;
}
