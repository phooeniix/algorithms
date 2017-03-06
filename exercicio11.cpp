// receba um numero positivo maior que zero e mostre ele ao quadrado ao cubo e a raiz
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Declarando variáveis
    float numero;
    while(numero<=0){//enquanto o número não for positivo e diferente de zero não vai para frente
    cout<<"Escreva um número :"<<endl;
    //Lendo número positivo e maior que zero
    cin>>numero;
    }
    //Escrevendo resultado numero elevado ao quadrado
    cout<<"O número elevado ao quadrado é igual a : "<<(pow(numero,2))<<endl;
    //Escrevendo resultado numero elevado ao cubo
    cout<<"O número elevado ao cubo é igual a : "<<(pow(numero,3))<<endl;
    //Escrevendo resultado raiz do numero
    cout<<"A raiz quadrada de "<<numero<<" é igual a : "<<sqrt(numero)<<endl;
    //função retornou sem erros (0)
    return 0;
}
