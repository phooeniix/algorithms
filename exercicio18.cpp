/*receba o peso do saco de raço para gatos em KG transforme para gramas
receba a quantidade de ração para os gatos
e mostre quanto restara daqui 5 dias
*/
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float pesoSacoKg, pesoSacog, quantidade, resto, qtdDia;
cout<<"Qual o peso do saco de ração : " <<endl;
//Lendo o peso do saco de ração
cin>>pesoSacoKg;
//Calculando peso em gramas
pesoSacog = pesoSacoKg *1000;
cout<<"Qual a quantidade que cada gato come por dia: "<<endl;
//Lendo quantidade por 1 gato
cin>>quantidade;
//Por ser dois gatos pega a quantidade e multiplica por 2
quantidade*=2;
//Calculando a quantidade em um determinado dia
qtdDia =quantidade*5;
//Calculando o resto
resto= pesoSacog - qtdDia;
cout<<"No quinto dia sobraram "<<resto<<"Gramas\n";
cout<<"Ou melhor dizendo "<<(resto/1000)<<" Quilogramas";
//Função retornou sem erros e funcionando
return 0;
}
