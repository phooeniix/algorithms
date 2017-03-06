/*
receba o angulo de inclinação entre a escada e o chao
receba a altura da parede até a ponta da escada
calcule o tamanho da escada
*/
#include <iostream>
#include <cmath>
using namespace std;
float pi=3.14;
int main(){
//declarando variáveis
float angulo, hEscada, hParede;
cout<<"Escreva o angulo entre a escada e o chão:\n";
//Lendo o angulo entre a escada e o chão
cin>>angulo;
cout<<"Escreva a altura da parede até a ponta da escada:\n";
//Lendo a altura da parede
cin>>hParede;
//calculando o angulo, angulo vezes pi dividido por 180
angulo = (angulo*pi)/180;


//Calculando altura da escada
hEscada = hParede/sin(angulo);
cout<<"A altura da escada é igual a "<<hEscada<<"unidades";
//Função retornou sem erros e funcionando
return 0;
}
