#include <iostream>
using namespace std;
class Node{
  friend class List;
  int data;
  Node *next;
};
class List{
private:
    int size;
    Node *head;
    Node *last;
public:
  List():size(0), head(NULL), last(NULL){}
  bool Empty(){
    return (head==NULL);
  }
  void Insert(int item){
    //Create a new node
    Node *aux = new Node;
    aux->data = item;
    aux->next = NULL;
    //NOw INSERT A NODE IN LIST
    //if list is empty, insert in first node
    if(Empty()){
      //could use (head==primeiro)
      head = aux;
      last = aux;
    }else{
      //insert in the end, because list have elements
      last->next = aux;
      last = aux;
    }
    size++;
  }
bool InsertPosition(int item, int pos){
    int p = pos;
    Node *aux = new Node;
    aux->data = item;
    aux->next = NULL;
    //if position is > at size the list -> ERROR
    if(p>size){
      cout<<"Posição errada\n";
      return false;
    }else if(p<=size){//if pos < at size insert, pos never was negative number
        if (Empty()){
            head = aux;
            last = aux;
        }else if(p==size){//insert in the end
          last->next;
          last = aux;
        }else{
          int k = 0;
          Node * aux = head;
          while(aux!=NULL){
            if(p==k){
              head->next;
              head = aux;
            }else{
              k++;
              aux = aux->next;
            }

          }
        }
        size++;
        return true;
    }

}
    void Print(){
      Node* aux = head;
      while (aux!=NULL) {
        cout<<aux->data<<" ";
        aux = aux->next;
      }
      cout<<endl;
    }

};

int main(){
  List list;
  char op;
  int valor, position;
  while(op!='x'){
    cin>>op;
    switch (op) {
      case 'i':
        cin>>valor;
        list.Insert(valor);
      break;
      case 'p':
        list.Print();
      break;
      case 'k':
        cin>>valor>>position;
        //list.InsertPosition(valor, position);
      break;
      case 'x':
        cout<<"Tenha um bom dia \n";
      break;
      default:
        cout<<"Não existe essa bagaça, escolhe a porra certa.\n";
      break;
    }
  }
  return 0;
}
