#include <iostream>
#include <cstdlib>

using namespace std;

class noh {
friend class ArvoreAVL;
private:
	int chave, altd, alte;
	noh* esq;
	noh* dir;
};

class ArvoreAVL {
private:
	int maior (int a, int b);
	noh* rotacao_esquerda (noh* aux);
	noh* rotacao_direita (noh* aux);
	noh* balanceamento (noh* aux);
public:
	noh* insere (noh* aux, int chave);
	void mostra(noh* aux);
};

int ArvoreAVL::maior(int a, int b){
	return a > b ? a : b;
}

noh* ArvoreAVL::insere(noh* aux, int chave){
	noh* novo;

	if(aux == NULL){
		novo = new noh;
		novo->chave = chave;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->alte = 0;
        novo->altd = 0;
        aux = novo;
	} else{
		if(chave < aux->chave)
        {
            aux->esq = insere(aux->esq,chave);
            aux->alte = 1 + maior(aux->esq->alte,aux->esq->altd);
        }
        else
        {
            aux->dir = insere(aux->dir,chave);
            aux->altd = 1+maior(aux->dir->alte,aux->dir->altd);
        }
	}
	return balanceamento(aux);
}

void ArvoreAVL::mostra(noh* aux)
{
    if(aux!=NULL)
    {
        mostra(aux->esq);
        cout << aux->chave << " ";
        mostra(aux->dir);
    }
}

noh* ArvoreAVL::rotacao_esquerda(noh* aux){
	noh* aux1;
	noh* aux2;

	aux1 = aux->dir;
	aux2 = aux1->esq;
	aux->dir = aux2;
	aux1->esq = aux;

	if (aux->dir == NULL){
		aux->altd = 0;
	}
    else{
		aux->altd = 1+maior(aux->dir->alte,aux->dir->altd);
	}

    if(aux->esq == NULL){
		aux->alte =0;
	}
    else{
		aux->alte = 1+maior(aux->esq->alte,aux->esq->altd);
	}
    return aux1;
}

noh* ArvoreAVL::rotacao_direita(noh* aux){
	noh* aux1;
	noh* aux2;
    aux1 = aux->esq;
    aux2 = aux1->dir;
    aux->esq = aux2;
    aux1->dir = aux;

    if (aux->esq == NULL)
        aux->alte = 0;
    else
        aux->alte = 1+maior(aux->esq->alte, aux->esq->altd);

    if(aux->dir ==NULL)
        aux->altd = 0;
    else
        aux->altd = 1+maior(aux->dir->alte, aux->dir->altd);

    return aux1;
}

noh* ArvoreAVL::balanceamento (noh* aux)
{
    int d;
    d = aux->altd - aux ->alte;
    if(d == 2)
    {
        int df;
        df = aux->dir->altd - aux->dir->alte;
        if(df >= 0)
        {
            aux = rotacao_esquerda(aux);
        }
        else
        {
            aux->dir = rotacao_direita(aux->dir);
            aux = rotacao_esquerda(aux);
        }
    }
    if(d == -2)
    {
        int df;
        df = aux->esq->altd - aux->esq->alte;
        if(df <= 0)
        {
            aux = rotacao_direita(aux);
        }
        else
        {
            aux->esq = rotacao_esquerda(aux->esq);
            aux = rotacao_direita(aux);
        }
    }
    return aux;
}


int main(int argc, char const *argv[]) {
	ArvoreAVL arvAvl;
	noh* raiz = NULL;
    raiz = arvAvl.insere(raiz,10);
    raiz = arvAvl.insere(raiz,50);
    raiz = arvAvl.insere(raiz,8);
    raiz = arvAvl.insere(raiz,12);
    raiz = arvAvl.insere(raiz,55);
	raiz = arvAvl.insere(raiz,88);
    raiz = arvAvl.insere(raiz,75);
    raiz = arvAvl.insere(raiz,90);
    raiz = arvAvl.insere(raiz,102);


    arvAvl.mostra(raiz);
	cout << endl;
	return 0;
}
