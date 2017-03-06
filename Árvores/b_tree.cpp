/*
 * Código adaptado por Alexandre Carvalho
 * Código Original desenvolvido por Joukin
 * Considerações:
 *      para esse código a grande dificuldade foi entender a complexidade da árvore b
 *      mas a lógica eu entendi, seria ler os valores do disco, armazenar no cash, que seria minha hash
 *      e quando precisasse de ler qualquer coisa no arquivo, eu iria primeiro na minha cash, acessando direto o valor
 *      não precisando ler de novo o arquivo.
 *      para isso a estrutura cash foi criada. logo depois um vetor ** elementos é criado para armazenar os valor advindos da leitura
 */

#include <iostream>
#include <fstream>

using namespace std;
const int UMPRIMO = 39;
struct cabArqB{
    int grau;
    int posRaiz;
    int nPaginas;
};
class cash{
private:
    string chave;
    string valor;
    cash* proximo;
public:
    cash(){
        proximo = NULL;
        chave = "";
        valor = "";
    }
};
class pagina {
friend class arvoreB;
private:
    pagina** filhas; // *** SÓ PARA COMPILAR! ***
    int* posFilhas; // até 2M filhas (posFilhas -> posição relativa no disco)
    int* chaves;     // até 2M-1 chaves 
    int n;     // número de chaves (n+1 filhos)
    char folha;  // 1 -> folha --- 0 -> não-folha
public:
    pagina(unsigned M, char f = 1) {
        posFilhas = new int[2*M];
        chaves = new int[2*M-1];
        n = 0;
        folha = f;
    }
};

class arvoreB {
private:
    cabArqB cab;
    string nomeArq;
    pagina* raiz;
    void dividePagFilha(pagina* P, int posFilha);
    void insereEmPagNaoCheia(pagina* P, int chave);
    void percorreEmOrdemAux(pagina* P, int nivel);
    void lerPagArquivo(pagina* p, int posDisk);
    void escreverPagArquivo(pagina* p, int posDisk);    
public:
    arvoreB(string nome, int grau=3) {
        nomeArq = nome;
        ifstream arqE(nomeArq.c_str(), ios::binary);

        if ( arqE ) {
            arqE.read((char*) &cab, sizeof(cabArqB));
            if (cab.nPaginas == 0) {
                raiz = NULL;
            } else { 
                raiz = new pagina(cab.grau);
                lerPagArquivo(raiz, cab.posRaiz);
            }
            arqE.close();
        
        } else { // não existe o arquivo de entrada ainda, nova árvore
            ofstream arqS(nomeArq.c_str(),ios::out | ios::binary);
            raiz = NULL;
            cab.grau = grau;
            cab.nPaginas = 0;
            arqS.write((const char*) &cab, sizeof(cabArqB));
            arqS.close();
        } 
    }
    void percorreEmOrdem( );
    pagina* busca(int chave);
    void insere(int chave);
};


void arvoreB::lerPagArquivo(pagina* p, int posDisk){
    ifstream arqE(nomeArq.c_str(), ios::binary);
    
    // num_chaves + eh_folha + 2*M (chaves) + 2*M+1 filhos
    int tamPag = sizeof(int) + sizeof(char)  
                 + (sizeof(int) * ((2 * cab.grau) - 1))
                 + (sizeof(int) * (2 *cab.grau));
    
    // pula o cabeçalho do arquivo e o número de páginas anteriores             
    int posAbs = sizeof(cab) + posDisk*tamPag;
    
    // leitura dos dados
    arqE.seekg(posAbs);
    arqE.read((char*) &(p->n),sizeof(int));
    arqE.read((char*) &(p->folha),sizeof(char));
    // lendo n dados do vetor em sequencia
    arqE.read((char*) p->chaves,sizeof(int)*(p->n));    
    // pulando as chaves não existentes
    posAbs += sizeof(int) + sizeof(char) 
              + sizeof(int)*((2 * cab.grau) - 1);
    arqE.seekg(posAbs);
    // lendo as posições das páginas filhas
    arqE.read((char*) p->posFilhas,sizeof(int)*(p->n + 1));     
    arqE.close();  
}


void arvoreB::escreverPagArquivo(pagina* p, int posDisk){
    // usando fstream para não sobrescrever o arquivo
    fstream arqS(nomeArq.c_str(), ios::in | ios::out | ios::binary);
    
    // num_chaves + eh_folha + 2*M (chaves) + 2*M+1 filhos
    int tamPag = sizeof(int) + sizeof(char)  
                 + (sizeof(int) * ((2 * cab.grau) - 1))
                 + (sizeof(int) * (2 *cab.grau));
    
    // pula o cabeçalho do arquivo e o número de páginas anteriores             
    int posAbs = sizeof(cab) + posDisk*tamPag;
    
    // escrita dos dados
    arqS.seekp(posAbs);
    arqS.write((char*) &(p->n),sizeof(int));
    arqS.write((char*) &(p->folha),sizeof(char));
    // escrevendo n dados do vetor em sequencia
    arqS.write((char*) p->chaves,sizeof(int)*(p->n));    
    // pulando as chaves não existentes
    posAbs += sizeof(int) + sizeof(char) 
              + sizeof(int)*((2 * cab.grau) - 1);
    arqS.seekp(posAbs);
    // escrevendo as posições das páginas filhas
    arqS.write((char*) p->posFilhas,sizeof(int)*(p->n + 1));     
    arqS.close();  
}



void arvoreB::insere(int chave) {
    int grau = cab.grau;
    
    // se árvore estiver vazia, aloca nó para o raiz
    // e insere a chave na posição inicial    
    if (raiz == NULL) {
        raiz = new pagina(grau);
        raiz->chaves[0] = chave; 
        raiz->n = 1; 
        
        // alterando o cabeçalho do arquivo
        // usa fstream para não apagar conteúdo do arquivo
        fstream arq(nomeArq.c_str(), ios::in | ios::out | ios::binary);
        cab.posRaiz = 0;
        cab.nPaginas = 1;
        arq.write((const char*) &cab, sizeof(cabArqB)); 
        arq.close(); 

        // escreve a raiz no disco
        escreverPagArquivo(raiz, 0);
        
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
            
            // Gravando modificações no arquivo
            escreverPagArquivo(raiz, cab.posRaiz);
            
            // A nova página é escrita no final do arquivo
            int posNovaPagina =  cab.nPaginas;
            escreverPagArquivo(novaP, posNovaPagina);
            
            // Modifica o cabeçalho
            cab.posRaiz = posNovaPagina;
            cab.nPaginas++;
        }
        else  // se raiz não está cheia, chama insiraNaoCheia nela
            insereEmPagNaoCheia(raiz, chave);
    } 
}

void arvoreB::dividePagFilha(pagina* P, int posFilha) {
    int grau = cab.grau;
        
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
    int grau = cab.grau;
    
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
    arvoreB A("arq1.dat", 3);
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