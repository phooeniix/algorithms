// Árvore B
// Estruturas de Dados - 2016/1
// Código by Joukim

# include <iostream>

using namespace std;

/* Para esta implementação, adotou-se a seguinte definição de grau,
 * retirada de Sedgewick:
 *
 * A B tree of order M is a tree that either is empty or comprises
 * k-nodes, with k-1 keys and k links (...) k must be between 2 and
 * M at the root and between M/2 and M at every other node (...).
 *
 * Em minha opinião, essa definição é uma das mais claras e de mais
 * fácil implementação: o grau de uma árvore B é o menor número de
 * filhos (links) que um nó (uma página pode conter).
 *
 * Definições alternativas de grau:
 *
 * I. Wikipedia: Usually, the number of keys is chosen to vary between
 * d and 2d, where d is the minimum number of keys,
 * and d+1 is the minimum degree or branching factor of the tree.
 *
 * II. Cormen: Nodes have lower and upper bounds on the number
 * of keys they can contain. We express these bounds in terms of a
 * ﬁxed integer t called the minimum degree of the B-tree:
 * a. Every node other than the root must have at least t - 1 keys.
 * (...) Every node may contain at most 2t - 1 keys.
 *
 * III. Knuth: According to Knuth's definition, a B-tree of order m
 * is a tree which satisfies the following properties:
 * Every node has at most m children.
 * Every non-leaf node (except root) has at least ⌈m/2⌉ children.
 *
 * IV. Aho & Hopcroft: Formally, a B-tree of order m is an m-ary
 * search tree with the following properties:
 * 1. The root is either a leaf or has at least two children.
 * 2. Each node, except for the root and the leaves, has between [m/2]
 * and m children.
 *
 * V. Horvick: More formally, each non-root node in the B-tree will
 * contain at least T children and a maximum of 2 × T children.
 * (...) Every non-root node will have at least T - 1 values.
 * Every non-root node will have at most 2 × T - 1 values.
*/

// usando bit fields, para economizar memória
struct cabArvB{
  unsigned int grau;
  int folha;
  int nPaginas;
};
class pagina {
friend class arvoreB;
private:
    pagina** filhas; // até 2M filhas
    int* chaves;     // até 2M-1 chaves
    unsigned n: 31;     // número de chaves (n+1 filhos)
    unsigned folha: 1;  // 1 -> folha --- 0 -> não-folha
public:
    pagina(unsigned M, unsigned f) {
        filhas = new pagina*[2*M];
        chaves = new int[2*M-1];
        n = 0;
        folha = f;
    }
};

class arvoreB {
private:
    struct cabArvB cabecalho;
    string nomearquivo;
    pagina* raiz;
    int grau;
    void dividePagFilha(pagina* P, int posFilha);
    void insereEmPagNaoCheia(pagina* P, int chave);
    void percorreEmOrdemAux(pagina* P, int nivel);
public:
    arvoreB(unsigned M=3) {
        raiz = NULL;
        grau = M;

    }
    arvoreB(string nomearquivo, int grauPag);
    void percorreEmOrdem( );
    pagina* busca(int chave);
    void insere(int chave);
};


void arvoreB::insere(int chave) {
    // se árvore estiver vazia, aloca nó para o raiz
    // e insere a chave na posição inicial
    if (raiz == NULL) {
        raiz = new pagina(grau, 1);
        raiz->chaves[0] = chave;
        raiz->n = 1;
    } else { // já tem algo na raiz
        // caso raiz esteja cheia, cresça árvore em altura
        if (raiz->n == 2*grau-1) {
            pagina* novaP = new pagina(grau, 0);

            // torna raiz filho da nova página
            novaP->filhas[0] = raiz;

            // Divide raiz antiga e sobe uma chave para nova raiz
            dividePagFilha(novaP, 0);

            // Nova raiz tem agora duas páginas filhas...
            // Verifica qual das duas irá receber a chave
            int i = 0;
            if (chave > novaP->chaves[0])
                i++;
            insereEmPagNaoCheia(novaP->filhas[i],chave);

            // Change root
            raiz = novaP;
        }
        else  // se raiz não está cheia, chama insiraNaoCheia nela
            insereEmPagNaoCheia(raiz, chave);
    }
}

void arvoreB::dividePagFilha(pagina* P, int posFilha) {
    // Cria nova página para armazenar metade das chaves
    // da página filha
    pagina *filha = P->filhas[posFilha];
    pagina *novaP = new pagina(grau, filha->folha);
    novaP->n = grau - 1;

    // Copia os últimas chaves e filhas da página filha para novaP
    for (int j = 0; j < grau-1; j++) {
        novaP->chaves[j] = filha-> chaves[j+grau];
    }
    if (filha->folha == 0) {
        for (int j = 0; j < grau; j++)
            novaP->filhas[j] = filha->filhas[j+grau];
    }

    // Reduz número de chaves na página filha
    filha->n = grau - 1;

    // Cria espaço no vetor de filhas do nó atual
    // para inserir novaP
    for (int j = P->n; j >= posFilha+1; j--) {
        P->filhas[j+1] = P->filhas[j];
    }

    // Insere apontador para novaP no nó atual
    P->filhas[posFilha+1] = novaP;

    // Cria espaço no vetor de chaves para a chave que
    // subirá da página filha
    for (int j = P->n-1; j >= posFilha; j--) {
        P->chaves[j+1] = P->chaves[j];
    }

    // Copia chave do meio da página filha para nó atual
    P->chaves[posFilha] = filha->chaves[grau-1];
    P->n = P->n + 1;
}


void arvoreB::insereEmPagNaoCheia(pagina* P, int chave) {
    // inicializa índice como elemento mais à direita
    int i = P->n-1;

    // Caso página atual seja folha,
    // encontre o local para inserir nova chave
    // e mova outros valores uma posição à frente
    if (P->folha == 1) {
        while (i >= 0 && P->chaves[i] > chave) {
            P->chaves[i+1] = P->chaves[i];
            i--;
        }

        // Insere nova chave no local encontrado
        P->chaves[i+1] = chave;
        P->n = P->n+1;
    } else { // nó não é folha
        // Encontra página filha que irá receber a nova chave
        while (i >= 0 && P->chaves[i] > chave) {
            i--;
        }

        // Verifica se página encontrada não está cheia
        if (P->filhas[i+1]->n == 2*grau-1) {
            // Se página filha está cheia, divida-a
            dividePagFilha(P, i+1);

            // Após divisão, verifica qual das duas partes
            // irá receber a nova chave
            if (P->chaves[i+1] < chave)
                i++;
        }
        insereEmPagNaoCheia(P->filhas[i+1], chave);
    }
}


void arvoreB::percorreEmOrdem( ){
    percorreEmOrdemAux(raiz,0);
    cout << endl;
}

void arvoreB::percorreEmOrdemAux(pagina* P, int nivel){
    int i;
    for (i = 0; i < P->n; i++) {
        // se a página não é folha, imprima os dados da página filha i
        // antes de imprimir a chave i
        if (P->folha == 0) {
            percorreEmOrdemAux(P->filhas[i], nivel+1);
        }
        cout << P->chaves[i] << '/' << nivel << ' ';
    }

    // Imprima os dados do último filho
    if (P->folha == 0) {
        percorreEmOrdemAux(P->filhas[i], nivel+1);
    }
}

int main() {
    // 1 34 23 1 200 344 222 12 8 2221 12 9 1 3 4 5 6 6 -1
    arvoreB A("entrada.txt",5);
    int n;
    cin >> n;

    while (n != -1) {
        A.insere(n);
        A.percorreEmOrdem();
        cin >> n;
    }

    A.percorreEmOrdem();

    return 0;
}
