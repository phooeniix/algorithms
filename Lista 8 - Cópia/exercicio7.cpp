#include <iostream>
using namespace std;
#define batata 6
struct Funcionario{
	int ID;
	float salario;
};
void Merge(Funcionario m[][batata], int inicio, int meio, int fim, Funcionario aux[][batata]){
	int p=inicio;
	int o=meio+1;	
	
	for(int i=inicio;i<fim;i++){
		for(int j=inicio;j<fim;j++){
			aux[i][j]=m[i][j];
		}
	}
	for(int i=inicio;i<fim;i++){
		for(int j=inicio;j<fim;j++){
			if(p>meio) m[i][j]=aux[i][o++];
			else if(o>fim) m[i][j]=aux[i][p++];
			else if(m[i][j].ID>m[i][o].ID) m[i][j]=aux[i][o++];
			else m[i][j]=aux[i][p++];
		}
	}
	
	
	
}

void MergeSort(Funcionario m[][batata], int inicio, int fim, Funcionario aux[][batata]){
	if(fim<=inicio) return;
	int meio=inicio+(fim-inicio)/2;
	MergeSort(m, inicio, meio, aux);
	MergeSort(m, meio+1, fim, aux);
	Merge(m, inicio, meio, fim, aux);
	
}
int main(){
	Funcionario f[batata][batata];
	Funcionario aux[batata][batata];
	for(int i=0; i<batata;i++){
		for(int j=0;j<batata;j++){
			cin>>f[i][j].ID;
			cin>>f[i][j].salario;
		}
	}
	MergeSort(f, 0, batata-1, aux);
	
	
	for(int i =0; i<batata;i++){
		for(int j=0;j<batata;j++){
			cout<<f[i][j].ID<<" ";
			cout<<f[i][j].salario<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
