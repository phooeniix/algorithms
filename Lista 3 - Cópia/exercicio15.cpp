
#include <iostream>
using namespace std;
int MDC(int a, int b){
  int resto;

  while(b != 0){
    resto = a % b;
    a = b;
    b = resto;
  }

  return a;
}

int main(int argc, char *argv[]){
   int x, y;

   cout << "Este programa permite calcular o MDC\n";
   cout << "Informe o primeiro valor: ";
   cin >> x;
   cout << "Informe o segundo valor: ";
   cin >> y;

   cout << "\nO Máximo Divisor Comum de "
     << x << " e " << y << " é " << MDC(x, y) << endl;
   return 0;
}
