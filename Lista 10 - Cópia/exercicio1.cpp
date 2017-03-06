/* Autor: Alexandre Carvalho
 * Faça   um   programa   que   lê   um   nome   de   arquivo   e   uma 
 * frase   qualquer.   O   programa   deve  criar   o   arquivo   
 * indicado   (apagar   seu   conteúdo,   caso   já   exista)   e   
 * escreva   a   frase   no  arquivo.
 * 
 * */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	int n=0;
	string aux1, aux2;
	ifstream arquin("exercicio1IN.txt");
	ofstream arquiout("saida1.txt");
	while(arquin.good()){
		n++;
	}
	cout<<n;
	//~ for(int i=0; i<n;i++){
		//~ getline(arquin, aux1);
		//~ for(int j=0;j<n;j++){
			//~ getline(arquin, aux2);
			//~ if(aux1!=aux2){
				//~ arquiout<<aux1<<endl;
				//~ cout<<aux1<<endl;
			//~ }
		//~ }
	//~ }
	//~ arquiout.close();
	
	return 0;
}
