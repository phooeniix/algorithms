// receba a medida em pés e converta para polegadas jardas e milhas
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Declarando variáveis
    int pe,jarda,milha,polegada ;
    while((pe<=0)){//enquanto o número não for positivo e diferente de zero não vai para frente
    cout<<"Escreva o a medida em pés :"<<endl;
    //Lendo número uma medida positiva e maior que zero
    cin>>pe;
    }
    //Escrevendo resultado da conversao para polegadas
    cout<<pe<<" Pés é equivalente a "<<(pe*12)<< "  Polegadas"<<endl;
    //Escrevendo resultado da conversao para jardas
    cout<<pe<<" Pés é equivalente a "<<(pe/3)<<" Jardas"<<endl;
    //Escrevendo resultado da conversao para milhas
    cout<<pe<<" Pés é equivalente a "<<(pe*5280) << " Milhas"<<endl;

    //função retornou sem erros (0)
    return 0;
}
