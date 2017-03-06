#include <iostream>
using namespace std;
class Node{
  private:
    int key;
    Node *left;
    Node *right;
  public:
    Node(int key){
      this->key = key;
      left = NULL;
      right = NULL;
    }
    int getKey(){
      return key;
    }
    Node *getLeft(){
      return left;
    }
    Node *getRight(){
      return right;
    }
    void setLeft(Node *node){
      left = node;
    }
    void setRight(Node *node){
      right = node;
    }
};
class Tree{
  private:
    Node *raiz;
  public:
    Tree(){
      raiz = NULL;
    }
    void insert(int key){
      if(raiz == NULL){
        raiz = new Node(key);
      }else{
        InsertAux(raiz, key);
      }
    }
    void InsertAux(Node *node, int  key){
      //if menor when insert a left
      if(key < node->getKey()){
        //Verify if a left is NULL
        if(node->getLeft()==NULL){
          Node *newNode = new Node(key);
          node->setLeft(newNode);
        }else{
          //else continue searching recursive
          InsertAux(node->getLeft(),key);
        }
      }else if(key > node->getKey()){
        //Verify if a right node is NULL
        if(node->getRight()==NULL){
          Node *newNode = new Node(key);
          node->setRight(newNode); // seting in Right node
        }else{
          //else recursive call
          InsertAux(node->getRight(), key);
        }
      }

    }
    Node *getRaiz(){
      return raiz;
    }
    void InOrdem(Node *node){
      if(node!=NULL){
        InOrdem(node->getLeft());
        cout<<node->getKey()<<" ";
        InOrdem(node->getRight());
      }
    }
};
int main(){
  Tree t;
  cout<<"***---Menu de opções---***\n";
  cout<<"1 - Inserir\n";
  cout<<"2 - Ver Raiz\n";
  cout<<"3 - Imprimir InOrdem\n";
  cout<<"4 - Sair do Programa\n";
  int op;
  while(op!=4){
    cin>>op;
    switch (op) {
      case 1:
      int valor;
      cout<<"Digite um valor: ";
        cin>>valor;
        t.insert(valor);
        cout<<endl;
      break;
      case 2:
        cout<<(t.getRaiz());
      break;
      case 3:
        t.InOrdem(t.getRaiz());
      break;
      case 4:
        cout<<"Good Bye\n";
      break;
    }
  }
  // t.insert(20);
  // t.insert(90);
  // t.insert(60);
  // t.insert(0);
  // t.insert(30);
  // t.insert(40);
  // t.insert(80);
  //
  // cout<<"\nPercorrendo InOrdem\n";
  // t.InOrdem(t.getRaiz());

  return 0;
}
