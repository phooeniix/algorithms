/*
 * Autor:Alexandre Carvalho
 * 
 * Salários acrescidos de 5% do valor total de suas vendas.
 * Valor unitário dos objetos
 * Quantidade vendida de cada peça
 * 
 * Receba preços e a quantidades vendidas armazenando nos respectivos vetores
 * TAMANHO 10
 * 
 * Mostre Relatório com a quantidade vendida
 * MOstre valor unitário e valor total de cada objeto
 * Mostre valor geral das vendas e o valor da comissão que será paga ao vendedor
 * Mostre o valor do objeto mais vendido e sua posição no vetor
 * */
#include <iostream>
#define batata 10
using namespace std;

int main(){
	//Declarando variáveis
	int valorUn[batata],qtd[batata], i, resultado[batata], soma=0;
	int maior=-1, posicao=0;
	cout<<"Escreva os valores por unidade de cada objeto.\n";
	resultado[batata]=0;
	
	for(i=0;i<batata;i++){
		cout<<"Valor["<<i<<"]: ";
		cin>>valorUn[i];
	}
	cout<<"\n---------------------------\n";
	cout<<"Escreva a quantidade de objetos.\n";
	for(i=0;i<batata;i++){
		cout<<"Quantidade["<<i<<"]: ";
		cin>>qtd[i];
	}
	cout<<"\n---------------------------\n";
	//Escrevendo Valor por unidade
	for(i=0;i<batata;i++){
		cout<<"Valor["<<i<<"]: "<<valorUn[i]<<"  "<<endl;
	}
	cout<<"\n---------------------------\n";
	//Escrevendo Quantidade por unidade
	for(i=0;i<batata;i++){
		if((qtd[i])>maior){
			maior=qtd[i];
			posicao=i;
		}
		cout<<"Quantidade["<<i<<"]: "<<qtd[i]<<"  "<<endl;
	}
	cout<<"\n---------------------------\n\n\n";
	//Escrevendo resultado
	for(i=0;i<batata;i++){
		resultado[i]=(valorUn[i])*(qtd[i]);
		cout<<"Resultado ["<<i<<"]: "<<resultado[i]<<"  "<<endl;
		soma+=resultado[i];
	}
	cout<<"\n---------------------------\n";
	float comissao=0.05;
	comissao*=soma;
	//Soma de todo o ultimo vetor
	cout<<"O valor total arrecadado foi de "<<soma<<" reais.\n";
	//Valor da comissão
	cout<<"O valor da comissão do vendedor é de "<<comissao;
	//Salário do funcionário
	cout<<" reais, \n portanto esse vendedor receberá "<<comissao+400;
	cout<<" Reais"<<endl;
	//Item mais vendido
	cout<<"O item mais vendido foi o que está na posição "<<posicao;
	cout<<" com "<<maior<<" unidades.\n ";
	
	//A função retornou sem erros
	return 0;
}
