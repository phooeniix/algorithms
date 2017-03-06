#include <iostream>
#include "ClasseNoList.h"
using namespace std;
//bool List::Empty() {return (primeiro==NULL)};
void List::Insert(int dado){
	//Criando um novo nó
	No* novo = new No;
	novo->dado = dado;
	novo->prox = NULL;
	//Agora inserindo o nó na lista
	//Se a lista estiver vazia, inserimos no primeiro nó
	if (Empty()){
		//Could use (primeiro == NULL) ou EMPTY()
		qprimeiro = novo;
		ultimo = novo;
	}else{
	//Já tem gente na lista, insere no final
		ultimo->prox = novo;
		ultimo = novo;
	}
	tamanho++;
}
void List::InsertInicio(int dado){
	//Criando um novo nó
	No* novo = new No;
	novo->dado = dado;
	novo->prox = NULL;
	//Agora inserindo o nó na lista
	//Se a lista estiver vazia, inserimos no primeiro nó
	if (Empty()){
	//poderia utilizar (primeiro == NULL) ou EMPTY()
		primeiro = novo;
		ultimo = novo;
	}else{
	//Já tem gente na lista, insere no final
		novo->prox = primeiro;
		primeiro = novo;
	}
	tamanho++;
}
		/*int InsertPosicao(int dado, unsigned posicao){
			//Criando um novo nó
			No* novo = new No;
			novo->dado = dado;
			novo->prox = NULL;

			if(posicao > tamanho){
				if (Empty()){
				//poderia utilizar (primeiro == NULL) ou EMPTY()
					primeiro = novo;
					ultimo = novo;
				}else if (posicao==tamanho){//insere no fim
					ultimo->prox = novo;
					ultimo = novo;
				}
				tamanho++;
				return true;
			}else{//insere no meio da lista
				return false;
			}
		}
		*/
void List::Print(){
	No*aux = primeiro;
	while(aux!=NULL){
		cout<<aux->dado<<" ";
		aux=aux->prox;
	}
	cout<<endl;
}
void List::RemoveItem(int item){
	if(Empty()){
			cout << endl << " LISTA VAZIA" << endl;
		//se tem um item ou já é o primeiro, desvie o quanto antes para removeInicio
	} else if(tamanho == 1 || primeiro->dado == item) {
		//removeInicio();
		return;
	}else {
		No *ant = primeiro; //inicializa o nó anterior com o primeiro item
		No *atu = ant->prox; //e o nó atual com o próximo nó
    		while(atu != NULL){
				if(atu->dado == item) {
       			break; //se achou não precisa continuar procurando
   			} else { //já que vai analisar outro item, então atualiza os nós
       			ant = atu; //agora o anterior é o item atual
   				atu = atu->prox; //o atual passa ser o próximo item da lista
				}
		}
    	if(atu != NULL) { //se chegou no fim sem achar nada, nada deve ser feito
   			if (ultimo == atu) { //se é o último que está removendo
   				ultimo = ant;
				}
   			ant->prox = atu->prox; //atualiza a lista pegando o próximo do atual
				delete atu; //mata o atual
			tamanho--;
			}
	}
}
void List::PrintReverse(No* head){
	if(head==NULL)return;
	PrintReverse(head->prox);
	cout<<head->dado<<" ";
}
