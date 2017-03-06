// receba 4 números e some-os
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    int num1, num2, num3, num4, soma;
    cout<<"Escreva os números para serem somados"<<endl;
    //Recebendo as variaveis
    cin>>num1>>num2>>num3>>num4;
    //Somando
    soma=num1+num2+num3+num4;
    cout<<"A soma entre os número é  "<< soma;
    //função retornou sem erros (0)
    return 0;
}
