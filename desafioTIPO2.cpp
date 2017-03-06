//Verificar se o numero é par ou ímpar
#include <iostream>
using namespace std;
int main(){

int numero;
cout<<"Informe um número:";
cin>>numero;
//Operação bit a bit
cout<<(numero&1)<<endl;

return 0;
}
