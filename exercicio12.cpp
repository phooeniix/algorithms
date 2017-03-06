// receba dois numero positivo maior que zero e mostre um elevado ao outro
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Declarando variáveis
    int numero1, numero2;
    while((numero1<=0)){//enquanto o número não for positivo e diferente de zero não vai para frente
    cout<<"Escreva o primeiro número :"<<endl;
    //Lendo número positivo e maior que zero
    cin>>numero1;
    }
    while((numero2<=0)){//enquanto o número não for positivo e diferente de zero não vai para frente
    cout<<"Escreva o segundo número :"<<endl;
    //Lendo número positivo e maior que zero
    cin>>numero2;
    }
    //Escrevendo resultado numero elevado ao quadrado
    cout<<"O número "<<numero1<<" elevado a "<<numero2 <<" é igual a : "<<(pow(numero1,numero2))<<endl;
    //função retornou sem erros (0)
    return 0;
}
