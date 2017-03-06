// Dano o numero de lados de um poligono calcule numero de diagonais
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    int num, diagonais;
    cout<<"Escreva o número de lados de um poligono"<<endl;
    cin>>num;
    //Formula é D = N*(N-3)/2
    diagonais=(num*(num-3)/(2));
    //Escreva o resultado
    cout<<"O numero de Diagonais é "<< diagonais<<endl;
    //função retornou sem erros (0)
    return 0;
}
