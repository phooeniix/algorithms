/*Autor: Alexandre Carvalho
 * 
 * Ler infomações: nº voo, origem ; destino ; nº de lugares; p/ 12 aviões
 * exiba um mennu
 * 
 * Consultar
 * 		Por Número do voo
 * 		Por Origem
 * 		Por Destino
 * Efetuar Reserva
 * 		Qual voo
 * 		Reserva Confirmada
 * 		VOO lotado
 * 		Voo Inexistente
 * Sair A unica que pode sair do programa
 * 
 * */
#include <iostream>
#include <string>
#define tamanho 5
using namespace std;
int main(){
	//Declarando variaveis
	char origem[tamanho], destino[tamanho]; 
	string consDestino, consOrigem;
	int menu, numeroVoo[tamanho];
	cout<<"Escreva o número dos voos. \n";
	//Lendo os voo
	for(int i=0;i<tamanho;i++){
		cout<<"Voo["<<i+1<<"] ";
		cin>>numeroVoo[i];
	}
	//Lendo as cidades de Origem
	for(int i=0;i<tamanho;i++){
		//~ cout<<"Origem["<<i+1<<"]  do voo ["<<i+1<<"]"<<endl;
		getline(cin, origem[i]);
	}
	//Lendo os Destinos de cada voo
	for(int i=0;i<tamanho;i++){
		//~ cout<<"Destino["<<i+1<<"]  do voo ["<<numeroVoo[i]<<"]";
		getline(cin, destino[i]);
	}
	//Escrevendo o menu
	cout<<"\n\n*--------------------------------------------*\n";
	cout<<"[1] Para consultar.\n[2] Para Efetuar Reserva. \n[3] Sair\n";
	cout<<"*--------------------------------------------*\n";
	cin>>menu;
	//Enquanto o menu for diferente da opção de sair faça
	while(menu!=3){
		switch(menu){
			case 1:
			cout<<"\n\n*--------------------------------------------*\n\n";
			cout<<"[1] Por nº do voo.\n [2] Por origem. \n [3] Por Destino\n [4] Voltar ao Menu Principal. \n";
			cout<<"\n\n*--------------------------------------------*\n\n";
			int menuConsultar;
			cin>>menuConsultar;
			while(menuConsultar!=4){
				switch(menuConsultar){
					case 1:
						//Declarando variavel
						int nVoo, aux;
						aux=0;
						//A variável aux vai pegar a posição do voo para mostrar tudo sobre aquele voo a Origem e o destino
						cout<<"Digite o número do voo:\n";
						cin>>nVoo;
						for(int i=0;i<tamanho;i++){
							if(nVoo==numeroVoo[i]){
								aux=i;
							}else{
								cout<<"Voo Inexistente. \n";
							}
						}
							cout<<"Voo "<<numeroVoo[aux]<<" de ";
							cout<< origem[aux]<< " para " << destino[aux];
							cout<<endl;
					break;
					case 2:
						//Declarando variavel
						aux=0;
						//A variável aux vai pegar a posição do voo para mostrar tudo sobre aquele voo a Origem e o destino
						cout<<"Digite o número do voo. \n";
						getline(cin, consOrigem);
						for(int i=0;i<tamanho;i++){
							if(consOrigem==origem[i]){
								aux=i;
								continue;
							}else{
								cout<<"Voo Inexistente. \n";
							}
						}
							cout<<"Voo "<<numeroVoo[aux]<<" de ";
							cout<< origem[aux]<< " para " << destino[aux];
							cout<<endl;
					break;
					case 3:
						//Declarando variavel
						//A variável aux vai pegar a posição do voo para mostrar tudo sobre aquele voo a Origem e o destino
						cout<<"Digite o número do voo";
						getline(cin, consDestino);
						for(int i=0;i<tamanho;i++){
							if(consDestino==destino[i]){
								aux=i;
								continue;
							}else{
								cout<<"Voo Inexistente. \n";
							}
						}
							cout<<"Voo "<<numeroVoo[aux]<<" de ";
							cout<< origem[aux]<< " para " << destino[aux];
							cout<<endl;
					break;
					case 4:
						cout<<"Você saiu do menu de consulta. \n";
					break;
					default:
						cout<<"Digite uma opção valida. \n";
					break;
				}
			}
			break;
			case 2:
			break;
		}
	}
	
	//A função retornou sem erros
	return 0;
}
