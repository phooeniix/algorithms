#include <iostream>
#include <cstdlib>
#include "ClasseNoList.h"
using namespace std;
int main(){
	No *(pfun)(int, int) = Percorre;
	srand(time(NULL));
	List minhalista;
	minhalista.Insert(1);
	minhalista.Insert(2);
	minhalista.Insert(300);
	minhalista.Insert(4);
	minhalista.Insert(5);
	//minhalista.RemoveItem(300);
	//minhalista.InsertInicio(50);

	minhalista.PrintReverse(minhalista.primeiro);
	return 0;
}