//Verificar se o numero é par ou ímpar
#include <iostream>
using namespace std;
int main(){

int aux, resultado, prova;
float numero;
cout<<"Informe um número:";
cin>>numero;
aux = numero/2.0;
prova = aux*2;
resultado = numero - prova;
//cout<<resultado;

if(resultado==0){
    cout<<"Par!";
}else{
    cout<<"Impar";
}

return 0;
}
