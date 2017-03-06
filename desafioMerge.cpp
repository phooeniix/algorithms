#include <iostream>
using namespace std;
void Merge(int vet[], int inicio, int meio, int fim, int pt2[]){
    int p=inicio;
    int j=meio+1;
    for(int i=inicio;i<=fim;i++){
        pt2[i]=vet[i];
    }
    for(int i=inicio;i<=fim;i++){
        if(p>meio) vet[i]=pt2[j++];
        else if(j>fim) vet[i]=pt2[p++];
        else if(pt2[i]<pt2[j]) vet[i]=pt2[p++];
        else vet[i]=pt2[j++];
    }
}
void MergeSort(int vet[], int inicio, int fim, int pt2[]){
    if (fim<=inicio) return;
    int meio=inicio+(fim-inicio)/2;
    MergeSort(vet, inicio, meio, pt2);
    MergeSort(vet, meio+1, fim, pt2);
    Merge(vet,inicio, meio, fim, pt2);
}
void scanVet(int pt[], int n, int i){
	if(n==i) return;
	cin>>pt[i];
	scanVet(pt, n, i+1);
}
void printVet(int pt[], int n, int i){
	if(n==i){ cout<<endl;return;}
	cout<<pt[i]<<" ";
	printVet(pt, n, i+1);
}
int main(){
	int n;
	cin>>n;
	int *pt = new int[n];
	int *pt2 = new int[n];
	scanVet(pt, n, 0);
	MergeSort(pt,0, n-1, pt2);
	printVet(pt, n, 0);
	
	
	delete [] pt;
	delete [] pt2;
	return 0;
}
