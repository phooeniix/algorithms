#include <iostream>
#include <cstdlib>
using namespace std;
void Brincar(){
	int r = rand()%50;
	int n;
	bool x = false;
	int cont=0;
	while (x!=true){
		cin>>n;
		cont++;
		if(n==r){
			cout<<"Você conseguiu!!\nCom "<<cont<<" tentativas.\n";
			x=true;
		}else{
			x=false;
			if(n>r){
				cout<<"é -\n";	
			}else{
				cout<<"é +\n";
			}
		}
	}
}
int main(){
	srand(time(NULL));
	Brincar();
	cout<<"De novo ?";
	char res;
	cin>>res;
	if(res=='s'){
		Brincar();
	}else{
		cout<<"Adeus até a próxima\nPau no seu cu\n";	
	}
	return 0;
}