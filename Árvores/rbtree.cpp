// Árvore Rubro-Negra
// Estruturas de Dados - 2016/1
// Código by Joukim

# include <iostream>

using namespace std;

// constantes
const unsigned PRETO = 0;
const unsigned VERMELHO = 1;

// usando bit fields, para economizar memória
class noh {
friend class arvoreRN;
private:
    unsigned chave: 31; 
    char cor: 1; 
    noh* esq;
    noh* dir;
    noh* pai;
};


// uma vez flamengo, sempre flamengo...
class arvoreRN { 
private:
    noh* raiz;
    bool arruma(noh* umNoh);
    void girarDireita(noh* umNoh);     
    void girarEsquerda(noh* umNoh); 
    void percorreEmOrdemAux(noh* umNoh);    
public:
    arvoreRN( ) { 
        raiz = nullptr;
    }
    bool insere(unsigned umaChave);
    void percorreEmOrdem( );
}; 

bool arvoreRN::insere(unsigned umaChave) {
    // primeiro criamos um nó para inserção
    noh* umNoh = new noh;
    umNoh->chave = umaChave;
    umNoh->esq = nullptr;
    umNoh->dir = nullptr;
    
    // checa primeiro se não é o primeiro nó
    // se for, insere ele, como preto
    if (raiz == nullptr) {
        umNoh->cor = PRETO;
        umNoh->pai = nullptr;
        raiz = umNoh;
        return true;
    }
    
    // não é o primeiro nó, busca posição na árvore
    noh* atual = raiz;
    noh* anterior;
    
    while (atual != nullptr) {
        anterior = atual;
        if (umaChave > atual->chave) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    // achou posição, insere o nó, como vermelho
    umNoh->pai = anterior;
    umNoh->cor = VERMELHO;
    
    if (umNoh->chave > anterior->chave) {
        anterior->dir = umNoh;
    } else {
        anterior->esq = umNoh;
    }    
    
    return arruma(umNoh);
}

bool arvoreRN::arruma(noh* umNoh) {
    noh* tio;
    unsigned corAux;

    // percorre a árvore do nó para cima, enquanto ele não é a raiz
    // e o pai ainda é vermelho
    while ((umNoh != raiz) and (umNoh->pai->cor == VERMELHO)) {
        //encontrando o tio
        if (umNoh->pai == umNoh->pai->pai->esq) {
            tio = umNoh->pai->pai->dir;
        } else {
            tio = umNoh->pai->pai->esq;            
        }
        
        // se tio é vermelho, faça o seguinte:
        // i) altere cor do pai e tio como preto
        // ii) altere cor do avô como vermelho
        // iii) mova umNoh para o avô, para continuar verificação
        if ((tio != nullptr) and (tio->cor == VERMELHO)) {
            tio->cor = PRETO;
            umNoh->pai->cor = PRETO;
            umNoh->pai->pai->cor = VERMELHO;
            umNoh = umNoh->pai->pai;
        } else { // tio é preto (nullptr também é preto) 
            // tio é preto e pai é vermelho, precisa
            // fazer rotação, tem 4 situações:
            // EE, ED, DE e DD
            
            // Caso EE (esquerda-esquerda):
            // i) troque cores de pai e avô
            // ii) rotacione à direita o avô
            if ((umNoh->pai == umNoh->pai->pai->esq) and 
                (umNoh == umNoh->pai->esq)) {
                corAux = umNoh->pai->cor;
                umNoh->pai->cor = umNoh->pai->pai->cor;
                umNoh->pai->pai->cor = corAux;
                girarDireita(umNoh->pai->pai);
                continue; // volta ao while para continuar checagem
            }     
            // Caso ED (esquerda-direita):
            // i) troque cores do nó atual e avô
            // ii) rotacione à esquerda o pai
            // iii) rotacione à direita o avô
            if ((umNoh->pai == umNoh->pai->pai->esq) and 
                (umNoh == umNoh->pai->dir)) {
                corAux = umNoh->cor;
                umNoh->cor = umNoh->pai->pai->cor;
                umNoh->pai->pai->cor = corAux;
                girarEsquerda(umNoh->pai);
                girarDireita(umNoh->pai->pai);
                continue; // volta ao while para continuar checagem
            }   
            
             // Caso DD (direita-direita):
            // i) troque cores de pai e avô
            // ii) rotacione à esquerda o avô
            if ((umNoh->pai == umNoh->pai->pai->dir) and 
                (umNoh == umNoh->pai->dir)) {
                corAux = umNoh->pai->cor;
                umNoh->pai->cor = umNoh->pai->pai->cor;
                umNoh->pai->pai->cor = corAux;
                girarEsquerda(umNoh->pai->pai);
                continue; // volta ao while para continuar checagem
            }     
            // Caso DE (direita-esquerda):
            // i) troque cores do nó atual e avô
            // ii) rotacione à esquerda o pai
            // iii) rotacione à direita o avô
            if ((umNoh->pai == umNoh->pai->pai->dir) and 
                (umNoh == umNoh->pai->esq)) {
                corAux = umNoh->cor;
                umNoh->cor = umNoh->pai->pai->cor;
                umNoh->pai->pai->cor = corAux;
                girarDireita(umNoh->pai);
                girarEsquerda(umNoh->pai->pai);
                continue; // volta ao while para continuar checagem
            }   
        } // fim do else
        
    }

    // caso tenhamos alterado a cor da raiz em algum momento
    // arrumamos aqui
    raiz->cor = PRETO;
    
    return true;
}

void arvoreRN::girarDireita(noh* umNoh) {
    // implementar
}

void arvoreRN::girarEsquerda(noh* umNoh) {
    // implementar
}


void arvoreRN::percorreEmOrdem( ) {
    percorreEmOrdemAux(raiz);
    cout << endl;
}

void arvoreRN::percorreEmOrdemAux(noh* umNoh) {
     if (umNoh != NULL) {
        percorreEmOrdemAux(umNoh->esq);
        cout << umNoh->chave << "/";
        if (umNoh->cor == VERMELHO) {
            cout << "V ";
        } else {
            cout << "P ";
        }
        percorreEmOrdemAux(umNoh->dir);
    } 
}

int main() {
    arvoreRN arvRN;
    arvRN.insere(10);
    arvRN.insere(50);
    arvRN.insere(8);
    
    arvRN.percorreEmOrdem();
    return 0;
}



