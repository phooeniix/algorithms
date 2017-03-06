/*receba a altura do degrau e a altura que o usuario quer alcançar
calcule quantos degrais o usuário terá que subir
*/
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float alturaDegrau, alturaDesejada;
int nDegraus;
cout<<"Escreva a altura dos degraus em centimetros:\n";
//Lendo altura do degrau em centimetros
cin>>alturaDegrau;
//calculando a altura em metros do centimetro para metros
alturaDegrau/=100;
cout<<"Qual altura deseja alcançar em metros :\n";
cin>>alturaDesejada;
//Calculando o numero de degraus, variavel inteira, não exite meio degrau
nDegraus = alturaDesejada/alturaDegrau;
cout<<"Para atingir seu objetivo deverás subir ";
cout<<nDegraus<<" degraus";
//Função retornou sem erros e funcionando
return 0;
}
