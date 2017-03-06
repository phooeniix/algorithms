#include <iostream>
using namespace std;
int main() {
  int colunas,anterior, linha;  
  do {
	cin>>linha;
  } while (linha < 2);
  
  for(int i=0;i<linha;i++){
	  colunas = i+1;
	  anterior = 1;
	  cout<<anterior<<" ";

	  for(int j=1;j<colunas;j++) {
		 anterior =anterior*(i-j+1)/j;
		 cout<<anterior <<" ";
	  }
	  cout<<endl;
  }
  return 0;
}
