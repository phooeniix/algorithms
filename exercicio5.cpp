// receba o salário de um funcionario e o percentual de aumento calcule e exiba para o usuário
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float salario, aumento, percentual;
    cout<<"Escreva o valor do seu salário"<<endl;
    //Lendo o salário
    cin>>salario;
    cout<<"Escreva o percentual de aumento"<<endl;
    //Lendo o percentual de aumento
    cin>>percentual;
    //percentual de aumento dividido por 100
    percentual = percentual/100;
    //Calculando o aumento ganho pelo funcionario
    aumento=(salario*percentual);
    //escreva resultado
    cout<<"Você recebeu um aumento de R$" <<aumento;
    cout<<" agora seu salario é  R$"<< (salario+aumento);
    //função retornou sem erros (0)
    return 0;
}
