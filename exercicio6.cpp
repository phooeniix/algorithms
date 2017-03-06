// receba um salário base de um funcionario e calcule : 5% de aumento e 7% de imposto
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float salario, aumento,imposto;
    cout<<"Escreva o valor do seu salário"<<endl;
    //Lendo as salário
    cin>>salario;
    //calculando o imposto pago pelo funcionario
    imposto = salario*0.07;
    //Calculando o aumento ganho pelo funcionario
    aumento=(salario*0.05);
    //escreva resultado
    cout<<"Você recebeu um aumento de R$" <<aumento;
    cout<<" agora seu salario é  R$"<<(aumento+salario);
    cout<<" mas teve que pagar R$"<<imposto<<"de imposto e ";
    cout<<" agora seu salario é  R$"<< ((salario+aumento)-imposto);
    cout<<"INJUSTO? Vá trabalhar";
    //função retornou sem erros (0)
    return 0;
}
