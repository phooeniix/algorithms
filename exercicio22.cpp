/*
receba um numero real
1- exiba parte inteira
2- parte fracionaria
3- arredondamento
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
//declarando variáveis
float numero, fracionaria;
int inteira, arredondamento;
cout<<"Escreva um valor real:\n";
//Lendo o valor real
cin>>numero;
//vai pegar só a parte inteira do numero
inteira = numero;
//numero menos a parte inteira vai sobrar a parte fracionária
fracionaria = numero-inteira;
//função de arredondamento, não usei a parte inteira pqe sempre arredonda para baixo
//floor = sempre arredonda para baixo ceil sempre para cima

cout<<"A parte inteira do numero é igual a: " <<inteira<<endl;
cout<<"A parte fracionaria do numero é igual a: " <<fracionaria<<endl;
//a parte inteira é sempre um a menos que se arredondar para cima
cout<<"O número arredondado para baixo é igual a: " <<inteira<<endl;
//Para não utilizar as funções floor e ceil
cout<<"O número arredondado para cima é igual a: " <<inteira+1<<endl;

//Função retornou sem erros e funcionando
return 0;
}
