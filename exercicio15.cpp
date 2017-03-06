//receba o preço de fábrica de um veículo e calcule percentual de lucro do distribuidor e o percentual de impostos
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float precoFabrica, lucroDistribuidor, imposto, valorFinal;
cout<<"Qual o valor de fábrica : " <<endl;
//Lendo o valor do preço de fábrica
cin>>precoFabrica;
cout<<"Qual o percentual do lucro do distribuidor : ";
//Lendo o percentual do lucro do distribuidor
cin>>lucroDistribuidor;
cout<<"Qual o percentual dos impostos : ";
//Lendo o percentual de impostos
cin>>imposto;
cout<<"O valor do lucro do distribuidor é : R$";
//Calculando o lucro do distribuidor, percentual de lucro vezes o valor base
lucroDistribuidor = ((lucroDistribuidor/100)*precoFabrica);
//Escrevendo resultado
cout<<lucroDistribuidor<<endl;

cout<<"O valor dos impostos é : R$";
//Divide por 100 por que é uma taxa PERCENTUAL
//Calculando imposto taxa de juros vezes valor base
imposto = (imposto/100)*precoFabrica;
//Escrevendo resultado
cout<<imposto<<endl;

//Calculando valor final do veículo, preço de fábrica + lucro + imposto
valorFinal = precoFabrica + lucroDistribuidor + imposto;

cout<< "O valor final do veículo somados os impostos e o lucro do distribuidor é : R$" << valorFinal<<endl;

//Função retornou sem erros e funcionando
return 0;
}
