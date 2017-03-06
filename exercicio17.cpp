//receba um salario, dois cheques com juros de 0.38%
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float salario, cheque1, cheque2, imposto;
cout<<"Qual o valor do seu salario : " <<endl;
//Lendo o valor do salário
cin>>salario;
cout<<"Qual o valor do cheque 1 : ";
//Lendo o valor do cheque 1
cin>>cheque1;
cout<<"Qual o valor do cheque 2: ";
//Lendo o valor do cheque 2
cin>>cheque2;
imposto = 0.038;
//Exibindo o valor do imposto do cheque 1
cout<<"O valor do cheque 1 ficou em : R$"<<imposto*cheque1<<endl;
//Exibindo o valor do imposto do cheque 2
cout<<"O valor do cheque 2 ficou em : R$"<<imposto*cheque2 <<endl;
//calculando valor do imposto
imposto = cheque1+(imposto*cheque1) + cheque2 +(imposto*cheque2);
//Exibindo o saldo final da conta salario - imposto
cout<<"Você ainda possui  : R$"<< salario-imposto;
//Função retornou sem erros e funcionando
return 0;
}
