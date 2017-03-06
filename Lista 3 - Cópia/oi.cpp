/*
	*Fazer um menu SWITCH
	*1 - Executar calculos básicos matemáticos
	*2 - Exibir a tabuada de um número
	*3 - Receba 10 números e veja quantos são negativos e quantos são positivos
	*4 - Terminar o programa
	*
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Declarando variaveis
	int opcaoMenu, opcaoMath;
	float num1, num2;

	//CRIANDO MENU
	cout<<"Escolha uma opção : \n";
	cout<<"1 - Executar cálculos básicos da matemática. \n";
	cout<<"2 - Exibir a tabuada de um número. \n";
	cout<<"3 - Escreva 10 valores e veja quantos foram (+) e quantos (-). \n";
	cout<<"4 - Saia do programa. \n";
	//Fim do Menu

	//Lendo opção digitada do menu
	cin>>opcaoMenu;

	switch(opcaoMenu){
		case 1:
			//Criando Menu
			cout<<"Escolha uma opção que deseja efetuar: \n";
			cout<<"1 - Somar\n";
			cout<<"2 - Subtrair. \n";
			cout<<"3 - Didivir. \n";
			cout<<"4 - Multiplicar. \n";
			cout<<"5 - Baskara. \n";
			cout<<"6 - Ao quadrado. \n";
			cout<<"7 - Saia do programa. \n";
			//Fim Menu

			//Lendo opção matemática desejada
			cin>>opcaoMath;

			cout<<"Escreva os dois numeros a qual irá realizar a";
			cout<<" operação desejada.\n";
			cin>>num1>>num2;

			switch(opcaoMath){
				case 1:
					//declarando variavel
					/*variavel declarada aqui para não alocar na memória
					 * caso não precise
					 */

					float soma;
					//Realizando soma
					soma = num1 + num2;
					//Escrevendo resultado
					cout<<"A soma dos dois números é igual a "<<soma;
				break;
				case 2:
					float subtracao;
					//Realizando subtração
					subtracao = num1 - num2;
					//Escrevendo resultado
					cout<<"A subrtação dos dois números é igual a "<<subtracao;
				break;
				case 3:
					float divisao;
					//Realizando divisão
					divisao = num1 / num2;
					//Escrevendo resultado
					cout<<"A divisão dos dois números é igual a "<<divisao;
				break;
				case 4:
					float multiplicacao;
					//Realizando multiplicacao
					multiplicacao = num1 * num2;
					//Escrevendo resultado
					cout<<"A multiplicacao dos dois números é igual a ";
					cout<<multiplicacao;
				break;
				case 5:
					//Realizando baskara
					cout<<"Escreva os valores de A, B, C";
					//Declarando variaveis
					int x1, x2, a,b, c;
					//Lendo valores
					cin>>a>>b>>c;
					x1 = -b + sqrt(pow(b,2)*4*a*c)/2;
					x2 = -b - sqrt(pow(b,2)*4*a*c)/2;
					//Escrevendo resultado
					cout<<"As raizes são iguais a  \n"<<"X1: "<<x1<<"\n";
					cout<<"X2: "<<x2;
				break;
				case 6:
					float quadrado;
					//Realizando potenciacao
					quadrado = pow(num1,num2);
					//Escrevendo resultado
					cout<<num1<<" elevado a "<<num2<<" é igual a ";
					cout<<quadrado;

				break;
				case 7:
					//~ continue;
				break;
				default:
					cout<<"Opção errada";
				break;
			}

		break;
		case 2:
			//Escreva a introdução
			cout<<"Qual número você deseja ver a tabuada?\n";
			//Leia a variavel
			cin>>num1;
			for (int i=0; i<=10;i++){
				cout<<num1<<" * "<<i<<" = "<<num1*i<<"\n";
			}
		break;
		case 3:
			cout<<"Escreva 10 números para verificar quantos foram + e - : \n";
			//Declarando contadores
			int contPositivo, contNega;
			contPositivo=0;
			contNega=0;
			for(int i=0;i<10;i++){
				cin>>num1;
				if(num1>=0){
					contPositivo++;
				}else{
					if(num1<0){
						contNega++;
					}
				}
			}
			//ERRO SEMPRE ESCREVE UM NUMERO MUITO ALTO, O CONTADOR NÃO FUNCIONA
			//Apenas o positivo NÚMERO 4198581
			cout<<"Você escreveu "<<contPositivo<<" números positivos.\n";
			cout<<"Você escreveu "<<contNega<<" números negativos.\n";
		break;
		case 4:
		    cout<<"Você saiu do programa com sucesso !!";
		break;
	}
	//A função retornou sem erros
	return 0;
}
