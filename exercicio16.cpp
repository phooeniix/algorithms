/*receba horas trabalhadas e o salário minimo e calcule o salario de acordo com as regras
1-A hora trabalhada vale metade do salário minimo
2-O salário bruto equivale a horas trabalhadas multiplicada pelo valor da hora trabalhada
3-Imposto equivale a 3% do salário bruto
4-O salário a receber equivale ao  salario bruto menos imposto
*/
#include <iostream>
using namespace std;
int main(){
//declarando variáveis
float hTrabalhadas,valorH, imposto,salarioMinimo, salarioBruto, salarioFinal;
cout<<"Quantas horas trabalhadas? ";
//Lendo quantidade de horas trabalhadas
cin>>hTrabalhadas;
cout<<"Valor Salário mínimo: ";
//Lendo Salario Minimo
cin>>salarioMinimo;
//Valor da hora trabalhada é igual a metade do salário minimo
valorH = (salarioMinimo/2.0);
//Função retornou sem erros e funcionando
salarioBruto = (hTrabalhadas * valorH);
//imposto é equivalente 3% do salario bruto
imposto = 0.03 * salarioBruto;
//Calculo do salário final, salário bruto menos imposto
salarioFinal = (salarioBruto - imposto);
//Escreva o resultado
cout<<"O valor final do salário aplicando as regras é de R$"<<salarioFinal;
return 0;
}
