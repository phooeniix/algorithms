/*
 * Código adaptado por Alexandre Carvalho
 * Código Original desenvolvido por Joukin
 * Considerações:
 *     1 - O entendimento da questão foi bem difícil, então fiz da maneira que entendi
 *     2 - Todos os comentários do código original foram removidos, e todos os comentarios, são meus para demonstrar minha lógica
 *	   3 - Fiz todos os requisitos pedidos na questão, fiz a remoção
 *     4 - O limite de entradas eu setei como sendo a capacidade do cash
 *     5 - Criei um contador, para ver o número de nós inseridos pois não é uma tabela hash fechada
 *     6 - E cada vez que ela é acessada é incrementado 1, e na hora de inserir em uma hash lotada, verifico o noh que tem o menor 
           removo, e insiro.

 *     7 - Acertei a senha da prova, antes do professor revelar a senha, mereço alguns créditos pelo pensamento sincronizado.
 */


#include <iostream>
#include <string>
//#include <time.h>
using namespace std;

const int UMPRIMO = 39;
int cont = 0;
int limite;

int funcaoHash(string s, int M) {
	long h = 0;
	for (unsigned i = 0; i < s.length(); i++) {
		h = (UMPRIMO * h + s[i]) % M;
	}
	return h;
}

class noh {
	friend class tabelaHash;
private:
	string chave;
	string valor;
	noh* proximo;
	int timer;
	//time_r timer;
	/*
	 * Cada nó tem um timer, quando for criado um nó dispara o timer, e cada vez que alguem acessar o o determinado nó, ele será setado como zero.
	 * assim para remoção depois, quando o limite for atingido, aquele que estiver com o maior valor no timer
	 * o mesmo será excluido
	*/

	public:
		noh(){
			proximo = NULL;
			chave = "";
			valor = "";
			timer = 0;
		//y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
		}
	};

	class tabelaHash {
	private:
		noh** elementos;
		int capacidade;

	public:
		tabelaHash(int cap) {
			elementos = new noh*[cap];
			capacidade = cap;
			limite = cap;
			for (int i = 0; i < cap; i++) {
				elementos[i] = NULL;
			}
		}

		~tabelaHash() {
			delete[] elementos;
		}

		void insere(string c, string v) {
			//cout<<"Eu vou inserir monstrão\n";
			int h;
			h = funcaoHash(c, capacidade);
		//Se o número de inserções ultrapassou o limite, ele vai remover aquele nó com o maior timer	
			if (cont < limite) {
				if (elementos[h] == NULL) {
					elementos[h] = new noh;
					elementos[h]->chave = c;
					elementos[h]->valor = v;
				} else {
					cout << "colidiu: " << c << endl;
					noh* atual = elementos[h];

	            // achando local para inserção
					while (atual->proximo != NULL) {
						atual = atual->proximo;
					}

					noh* novo = new noh;
					novo->chave = c;
					novo->valor = v;
					atual->proximo = novo;
				}
				cont++;
			}else{
				cout<<"Entrei no else limite excedido\n";
				int menor = 0;
				int cod_aux_remove;
				for (int i = 0; i < capacidade; i++) {
					noh* atual;
					atual = elementos[i];
					while (atual != NULL) {
						if(atual->timer<menor){
							menor = atual->timer;
							cod_aux_remove = i;	
							//cod_aux_remove = atual->chave;
						}	
						atual = atual->proximo;
					}
					delete atual;
				}
				//Remove o noh com a chave X;
				cout<< elementos[cod_aux_remove]->timer<<endl;
				delete elementos[cod_aux_remove];
				elementos[cod_aux_remove] = NULL;

				//remove(elementos[cod_aux_remove]->chave);
				//Chama a própria função novamente para entrar no primeiro if
				//insere(c, v);
				
			}

		}

		string recupera(string c) {
			int h;
			h = funcaoHash(c, capacidade);

			if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
				//Quando ele acessa um determinado nó, ele incrementa de mais utilizados..
				elementos[h]->timer +=1;
				return elementos[h]->valor;
			} else {
				noh* atual = elementos[h];

				while ((atual != NULL) and (atual->chave != c)) {
					atual = atual->proximo;
				}

				if ((atual != NULL) and (atual->chave == c)) {
					return atual->valor;
				} else {
					return "NÃO ENCONTRADO!";
				}
			}
		}

		void altera(string c, string v) {
			int h;
			h = funcaoHash(c, capacidade);

			if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
				elementos[h]->valor = v;
			} else {
				noh* atual = elementos[h];

				while ((atual != NULL) and (atual->chave != c)) {
					atual = atual->proximo;
				}

				if ((atual != NULL) and (atual->chave == c)) {
					atual->valor = v;
				} else {
					cerr << "ERRO NA ALTERAÇÃO!" << endl;
				}
			}
		}
	/* Para remover usei da seguinte lógica, pega a chave a ser removida, encontra o valor de hash dela
	* se o elemento estiver diferente de null e for mesmo a chave ele deleta o elemento da memória
	* criei dois nós, um anterior e um atual, para andar em todo vetor, sempre ter uma posição na frente e uma atrás
	* percorro toda lista encadeada da tabela hash até encontrar a chave e quando encontrar faço todas as estruturas
	* depois de aquele determinado nó atual, receber os próximos nós
	*/
	void remove(string c) {
		int h;
		h = funcaoHash(c, capacidade);
		if ((elementos[h] != NULL) and (elementos[h]->chave == c)){
			// se ele for o ultimo elemento, faço o elemento[h] ser o elemento[h]->proximo
			if(elementos[h]->proximo==NULL){
				delete elementos[h];
				elementos[h] = NULL;
			}else{
				 //inicializa o nó atual com o primeiro item da posição h
				noh* atual =  elementos[h]; //e o nó ant com o próximo nó
				noh* ant = atual;
				while(atual != NULL){
					// se achar o elemento, faça ele apontar para o proximo dele
					if(atual->chave == c) {
						elementos[h] = elementos[h]->proximo;
						return; //se achou não precisa continuar procurando
					} else { // atualiza os nohs, para que possa continuar a verificação
						ant = atual; //agora o anterior é o item atual
						atual = atual->proximo; //o atual passa ser o próximo item da lista
					}
				}
			}
		}else { // else que remove posição que tem colisão
			noh* atual = elementos[h];
			noh* ant;
			cout << "here"<<endl;
			while ((atual != NULL) and (atual->chave != c)) {
				ant = atual;
				atual = atual->proximo;
			}
			cout << "atual = " << atual->chave<<endl;
			if ((atual != NULL) and (atual->chave == c)) {
				atual = atual->proximo;
				ant->proximo = atual;
			} else {
				cerr << "ERRO NA REMOÇAO!" << endl;
			}
		}
		cont--;

	}

    // percorrendo a tabela hash (para fins de debug)
	void percorre( ) {
		noh* atual;
		for (int i = 0; i < capacidade; i++) {
			cout << i << ":";
			atual = elementos[i];
			while (atual != NULL) {
				cout << "[" << atual->chave << "/" << atual->valor << "]->";
				atual = atual->proximo;
			}
			cout << "NULL  ";
		}

	}
};

int main( ) {
	tabelaHash th(10);

	th.insere("ola", "Olá a todos");//1 registro
	th.insere("olk", "Vai ter Colisão");//2 registro
	th.insere("joukim", "Joaquim Uchôa");//3 registro
	th.insere("tales", "Tales Heimfarth");//4 registro
	th.insere("joaquim", "Selvagem de Bicicleta");//5 registro
	th.insere("francisco", "Francisco de Albuquerque");//6 registro
	th.recupera("francisco");
	th.insere("tomate", "Too Much");//7 registro
	th.insere("23", "São oito dias para o fim do mês");//8 registro
	th.insere("ED", "A matéria do século");//9 registro
	th.insere("ED2", "Não verei essa matéria recursivamente");//10 registro
	//th.remove("ED2");
	th.insere("HAHA", "Não acredito que acabou");//VAI DAR CACA
	//th.remove("olk");
	
	th.recupera("ED");
	cout << endl;
	th.percorre();
	cout << endl;

return 0;
}

