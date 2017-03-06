/*
receba um numero float que vai ser interpretado como hora
1- exiba as horas em minutos
*/
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float numero, minutos;
int horas, horaMinutos;
cout<<"Escreva um valor real:\n";
//Lendo o valor real que vai ser interpretado como horas
cin>>numero;
//vai pegar só as horas
horas = numero;
//numero menos a parte inteira vai sobrar a parte fracionária
minutos = (numero-horas)*100;
//função de arredondamento, não usei a parte inteira pqe sempre arredonda para baixo
//floor = sempre arredonda para baixo ceil sempre para cima
horaMinutos = (horas*60)+minutos;
//Exibindo resultados
cout<<"A hora equivale a "<<horas<<"h:"<<minutos<<"min"<<endl;
cout<<"Total em minutos é igual a: "<<horaMinutos <<"minutos";
//Função retornou sem erros e funcionando
return 0;
}
