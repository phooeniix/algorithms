#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	ifstream arqin("palavras.txt");
	ifstream arquin2("numeros.txt");
	ifstream arquiout("frase.txt");
	
	arquiout.close();
	
	return 0;
}
