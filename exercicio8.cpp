// receba deposito e a taxa de juros e exiba o rendimento e o valor depois do rendimento
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float deposito,juros,rendimento;
    cout<<"Escreva o valor do seu depósito :"<<endl;
    //Lendo o deposito
    cin>>deposito;
    cout<<"Escreva o valor da taxa de juros :"<<endl;
    //Lendo a taxa de juros
    cin>>juros;
    //calculando a taxa de juros dividindo por 100
    juros/=100;
    //calculando o rendimento total
    rendimento = deposito*juros;
    //escreva resultado
    cout<<"Você recebeu um rendimento de R$" <<rendimento;
    cout<<" agora seu rendimento é  R$"<<(rendimento+deposito)<<endl;
    cout<<"INJUSTO? Vá trabalhar";
    //função retornou sem erros (0)
    return 0;
}
