// receba um salário base de um funcionario e calcule : 50R$ de aumento e 10% de imposto sobre o salário base
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float salario, aumento,imposto;
    cout<<"Escreva o valor do seu salário"<<endl;
    //Lendo o salário
    cin>>salario;
    //percentual de aumento dividido por 100
    imposto = salario*0.1;
    //Calculando o aumento ganho pelo funcionario
    aumento=50;
    //escreva resultado
    cout<<"Você recebeu um aumento de R$" <<aumento;
    cout<<" agora seu salario é  R$"<<(aumento+salario);
    cout<<" mas teve que pagar R$"<<imposto<<" de imposto e ";
    cout<<" agora seu salario é  R$"<< ((salario+aumento)-imposto)<<endl;
    cout<<"INJUSTO? Vá trabalhar";
    //função retornou sem erros (0)
    return 0;
}
