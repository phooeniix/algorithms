// receba a base e a altura de um triangulo e calcule sua area
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float base, altura, area;
    cout<<"Escreva o valor da base do triângulo :"<<endl;
    //Lendo a base
    cin>>base;
    cout<<"Escreva o valor da altura do triângulo :"<<endl;
    //Lendo a base
    cin>>altura;
    //calculando o valor da área do triangulo
    area = (base*altura)/2;
    //escreva resultado
    cout<<"A área do triângulo é " <<area<<" unidades";
    //função retornou sem erros (0)
    return 0;
}
