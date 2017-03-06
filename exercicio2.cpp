// receba 3 números e calcule a média
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float num1, num2, num3, media;
    cout<<"Escreva os números para calcular a média"<<endl;
    //Lendo as notas
    cin>>num1>>num2>>num3;
    //Calculando a média, 3.0 por ser um valor float
    media=(num1+num2+num3)/3.0;
    //escreva
    cout<<"A media entre os número é  "<< media;
    //função retornou sem erros (0)
    return 0;
}
