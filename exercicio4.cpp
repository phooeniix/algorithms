// receba o salario de um funcionario calcule o aumento de 25% e exiba
#include <iostream>
using namespace std;
int main(){
    //Declarando variáveis
    float salario, aumento;
    cout<<"Escreva o valor do seu salário"<<endl;
    //Lendo as salário
    cin>>salario;
    //Calculando o aumento ganho pelo funcionario
    aumento=(salario*0,25);
    //escreva resultado
    cout<<"Você recebeu um aumento de R$" <<aumento;
    cout<<" agora seu salario é  R$"<< (salario+aumento);
    //função retornou sem erros (0)
    return 0;
}
