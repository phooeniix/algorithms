#include <iostream>
using namespace std;
class Queue{
	private:
		int capacity;
		int size;
		int* data;
		int head;
		int last;

	public:
		Queue(int c):capacity(c),size(100),data(),head(0),last(-1){
			data = new int[capacity];
		}
		//~Queue(){delete [] data;}
		bool Insert(int item){
			if(last==head-1)
				return false;
			if(head == -1)
				head++;

			last = (last+1)%capacity;
			data[last] = item;
			size++;
			return true;
			cout<<"Inserido com Sucesso !";
		}
		void Print(){
			cout<<"Me chamou??\n";
			for(int i = head; i<=last; i++)
				cout<<data[i++]<<" ";
			cout<<endl;
		}

};

int main(){
	Queue q(100);
	q.Insert(20);
	q.Insert(30);
	q.Insert(40);
	q.Insert(150);
	q.Insert(530);
	q.Insert(540);
	q.Print();

	return 0;
}
