// receba o ano de nascimento de uma pessoa calcule a idade e a idade que ela terá no ano de 2050
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Declarando variáveis
    int ano, anoAtual ;
    cout<<"Em que ano você nasceu :"<<endl;
    //Lendo ano de nascimento
    cin>>ano;
    cout<<"Em que ano estamos :"<<endl;
    //Lendo ano atual
    cin>>anoAtual;
    //Calcula idade da pessoa
    cout<<"A sua idade eh "<< (anoAtual-ano)<<endl;
    //Calcula a idade da pessoa no ano de 2050
    cout<<"A sua idade no ano de 2050  "<<(2050-ano)<<" anos"<<endl;
    //função retornou sem erros (0)
    return 0;
}
