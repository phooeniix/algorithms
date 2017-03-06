#include <iostream>
using namespace std;
float Harmonia(float n){
	if(n==1) return 1;
	return (1/n)+Harmonia(n-1);
}
int main(){
	int m;
	cin>>m;
	//~ cout<<Harmonia(m);
	float matriz[m][m];
	float vetor[(m*m)];
	for(int i=0;i<(m*m);i++){
		vetor[i]=Harmonia(float (i+1));
	}
	//~ for(int i=0;i<(m*m);i++){
		//~ cout<<vetor[i]<<" ";
	//~ }
	for(int z=0;z<m*m;z++){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				matriz[i][j]=vetor[z] ;
			}
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	float SomaP=0, SomaD=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j) SomaD+=matriz[i][j];
			if(i+j==(m-1)) SomaP+=matriz[i][j];	
		}
	}
	cout<<(SomaD-SomaP);
	return 0;
}
