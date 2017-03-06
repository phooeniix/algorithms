/*
receba o valor do salário minimo
valor do quilowatt é 1/5 do salario minimo
receba a quantidade de quilowatt
calcule:
1-O valor em reais de cada quilowat
2-O valor pago pela residencia
3-O valor a ser pago com desconto de 15%
*/
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float salario, valorQWatt, qtdKWatt, valorTotal, valorDesconto;
cout<<"Escreva o valor do salário minimo:\n";
//Lendo o valor do salário minimo
cin>>salario;
//Calculando o valor do QuiloWatt
valorQWatt = salario/5;
cout<<"Escreva a quantidade de QuiloWatt consumida:\n";
//Lendo a quantidade de quilowatt consumida
cin>>qtdKWatt;
//calculando o valor total a ser pago
valorTotal = valorQWatt*qtdKWatt;
//calculando desconto 100% - 15% é igual a 85
valorDesconto = valorTotal*0.85;
//Exibindo valor QuiloWatt
cout<<"O valor do QuiloWatt é igual a R$"<<valorQWatt<<endl;
//Exibindo o valor pago pela residencia sem desconto
cout<<"O valor pago pela residencia é de R$"<<valorTotal<<endl;
//Exibindo valor pago pela residencia com desconto
cout<<"O valor pago com desconto de 15% foi de R$"<<valorDesconto<<endl;
//Função retornou sem erros e funcionando
return 0;
}
