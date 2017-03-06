#include <iostream>
using namespace std;
int main(){
	float valor;
	int cont=0;
	cout<<"Digite um valor :";
	cin>>valor;
	//Transformando o valor em centavos;
	valor*=100;
	//Fazendo um for para cada tipo de moeda
	
	/*for para a moeda de real
	 *Ele tem que dividir pelo valor da moeda até atingir o valor digitado	
	*/
	for(int real=0;real<(valor/100.0);real++){
		/*
		 * Este for tem que ser o valor do real vezes 100 para voltar ao 
		 * valor principal mais a estrutura de 20 centavos dividido pelo valor da moeda
		 *
		*/
		for(int cinq=0;cinq<valor/50.0;cinq++){
			for(int vinte=0;vinte<valor/25.0;vinte++){
				for(int dez=0;dez<valor/10.0;dez++){
					for(int cinco=0;cinco<valor/5.0;cinco++){
						cont++;
						cout<<"R: "<<real<<" Cq: "<<cinq<<" V: "<<vinte;
						cout<<" D: "<<dez<<" C: "<<cinco<<"\n";
					}
				}
			}
		}
	}
	//Escrevendo o numero de combinações
	
	cout<<"O numero de combinações foi de :"<<cont;
	//A função retornou sem erros funcionando corretamente
	return 0;
}
