#include<iostream>
#include<string>
using namespace std;
class Data{
	int dia;
	int mes;
	int ano;
	Data():dia(0), mes(0), ano(0){}
	Data(int a, int b, int c):dia(a), mes(b), ano(c){}
	void setDia(int d){
		dia = d;
	}
	void setMes(int m){
		mes = m;
	}
	void setAno(int a){
		ano = a;
	}
	void Insert(int di,int me,int an){
		setDia(di);
		setMes(me);
		setAno(an);
	}
};
class Funcionario{
	protected:
		int id;
		string nome;
		float salario;
		//Data *contratacao;
	
	public:
		Funcionario():id(0), nome(""), salario(0.0){}
		Funcionario(int i, string s, float sa):id(0), nome(""), salario(0.0){}
		int getID(){
			return id;
		}
		string getNome(){
			return nome;
		}
		int getSalario(){
			return salario;
		}
		//~ int getData(){
			//~ return *contratacao;
		//~ }
		void setId(int i){
			id = i;
		}
		void setNome(string aux){
			nome = aux;
		}
		void setSalario(float x){
			salario = x;
		}
		//~ void setData(Data *x){
			//~ contratacao.dia = x;
			//~ contratacao.mes = x;
			//~ contratacao.ano	= x;
		//~ }
		void Insert(int i, string n, float s){
			setId(i);
			setNome(n);
			setSalario(s);
		}
		void Print(){
			cout<< getID() <<endl;
			cout<< getNome() <<endl;
			cout<< getSalario() <<endl;
		}
		
};
class Tecnico:public Funcionario{
	private:
		int nAnos;
		
		int getnAnos(){
			return nAnos;
		}
		void setnAnos(int x){
			nAnos = x;
		}
};
class Medico:public Funcionario{
	private:
		int crm;
		string especialidade;
	public:
		int getCRM(){
			return crm;
		}
		string getEspecialidade(){
			return especialidade;
		}
		void setCRM(int x){
			crm = x;
		}
		void setEspecialidade(string aux){
			especialidade = aux;
		}
		void Insert(int cr, string es){
			setCRM(cr);
			setEspecialidade(es);
		}
		void Print(){
			cout<< getCRM()<<endl;
			cout<< getEspecialidade()<<endl;
		}
};

int main(){
	Funcionario f;
	f.Insert(1, "Alexandre", 50500);
	f.Print();
	//~ Medico rodrigo;
	//~ rodrigo.Insert(19090909, "Otorrinonaringologista");
	//~ rodrigo.Print();
	return 0;
}
