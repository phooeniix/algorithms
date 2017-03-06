// receba 3 números e o peso e calcule a média ponderada
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float num1, num2, num3, media;
    int peso1, peso2, peso3;
    cout<<"Escreva os números para calcular a média"<<endl;
    //Lendo as notas
    cin>>num1>>num2>>num3;
    cout<<"Escreva os pesos das notas respectivamente"<<endl;
    //Lendo os pesos
    cin>>peso1>>peso2>>peso3;
    //Calculando a média, notas * peso dividido pela soma de todos os pesos
    media=((num1*peso1)+(num2*peso2)+(num3*peso3))/(peso1+peso2+peso3);
    //escreva resultado
    cout<<"A media entre os número é  "<< media;
    //função retornou sem erros (0)
    return 0;
}
