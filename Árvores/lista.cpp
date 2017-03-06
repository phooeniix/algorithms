	#include <iostream>
#include <cstdlib>
using namespace std;
class No{
	friend class List;//Pode acessar dados privados
	private:
		int dado; //poderia ser outro tipo de variavel
		No* prox;
};
class List{
	private:
		int tamanho;
		No* primeiro;
		No* ultimo;
	public:
		//No* primeiro;
		List():tamanho(0), primeiro(NULL), ultimo(NULL){}
		List(int max):tamanho(max), primeiro(NULL), ultimo(NULL){}
		bool Empty(){
			return (primeiro==NULL);
		}
		void Insert(int dado){
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
				ultimo->prox = novo;
				ultimo = novo;
			}
			tamanho++;
		}
		void InsertInicio(int dado){
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
		void Print(){
			No*aux = primeiro;
			while(aux!=NULL){
				cout<<aux->dado<<" ";
				aux=aux->prox;
			}
			cout<<endl;
		}
		void RemoveItem(int item){
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
		void PrintRe(No* head){
			if(head==NULL)return;
			PrintRe(head->prox);
			cout<<head->dado<<" ";
		}
		void PrintReverse(){
			PrintRe(primeiro);cout<<"\n";
		}
		//void PercorreReverso(void *(Percorre)(No* umNo)){

		//}

		int Per(int posicao, No* head, int i){
			if(i == posicao)return 0;
			if(Empty()){
				cout<<"LISTA VAZIA\n";
			}else if(tamanho<posicao){
				cout<<"Posicao Inválida\n";
			}else{
				return Per(posicao, head->prox, i+1);
			}
		}
		void Percorre(int posicao){
			cout<<Per(posicao, primeiro, 0)<<endl;
		}
		int Search(int item){
    		No* aux = primeiro;
    		/* traverse the list */
    		while (aux != NULL) {
        		/* Target! */
        		if(aux->dado == item){
        			cout<<"Encontrei!\n";
            		return aux->dado;
        		}
        		/* move to the next one */
        		aux = aux->prox;
    		}
    		return 0;
		}
		void AcessaPosicao(int pos){
			int k=1;
			No *aux = primeiro;
			while(aux!=NULL){
				if(k==pos){
					break;
				}else{
					k++;
					aux = aux->prox;
				}
			}
			cout<<aux->dado<<endl;
		}
		~List(){
			No* aux;
			while(primeiro!=NULL){
				aux = primeiro;
				delete aux;
				primeiro = primeiro->prox;
			}
		}
};
int main(){
	//No *(pfun)(int) = Percorre;
	srand(time(NULL));
	List minhalista;
	minhalista.Insert(1);
	minhalista.Insert(2);
	minhalista.Insert(3);
	minhalista.Insert(4);
	minhalista.Insert(5);
	minhalista.Insert(6);
	minhalista.Insert(7);
	minhalista.Insert(8);
	minhalista.AcessaPosicao(5);
	//minhalista.Search(300);
	//minhalista.RemoveItem(300);
	//minhalista.InsertInicio(50);
	minhalista.PrintReverse();
	//minhalista.Percorre(3);

	return 0;
}
