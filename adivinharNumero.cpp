//Chute um número para mim
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
bool adivinhar;
int numero=0, aux, i;
srand(time(NULL));

aux = rand();
do{
    cout<<"Qual é o número:"<<endl;
    for(i=0;i<=aux;i++){
        numero++;
    }
}while(numero==aux);
cout<<(numero-1);



return 0;
}
