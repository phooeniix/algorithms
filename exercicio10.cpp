// receba area de um circulo dado o raio
#include <iostream>
#include <cmath>
using namespace std;
float pi=3.14159265359;
int main(){
    //Declarando variáveis
    float raio, area;
    cout<<"Escreva o valor do raio do circulo :"<<endl;
    //Lendo a raio
    cin>>raio;
    //calculando o valor da área do circulo pi raio quadrado
    area = pi*(pow(raio, 2));
    //escreva resultado
    cout<<"A área do circulo é " <<area<<" unidades";
    //função retornou sem erros (0)
    return 0;
}
