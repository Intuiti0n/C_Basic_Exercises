#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CLeitor {
	string nome;
	int codigo;
	public:
	  CLeitor(string, int);
	  virtual double getMensalidade() = 0;
};

class CLivro {
	string titulo, autor;
	string ISBN;
	int numExemplares;
   public:
   	CLivro operator+ (CLivro livro1);
   	CLivro(string ti, string au, string is, int ne): titulo(ti), autor(au), ISBN(is), numExemplares(ne){}
	string getTitulo() {return titulo;}
	string getISBN() {return ISBN;}
	int getNumExemp() {return numExemplares;}
};

class CBiblioteca {
	vector <CLeitor*> leitores;
	vector <CLivro> livros;
   public:
	CBiblioteca();
	void adicionaLeitor(CLeitor &l1);
	void adicionaLivro(CLivro &l1);
	CLivro &getLivro(string &tituloL);
	double getMensalidade();
};

/* 2.1) Construa a classe Leitor, que contém os atributos privados nome (string) e codigo (inteiro). 
Os leitores devem ter um código único e sequencial. */

class CLeitor {
	string nome; int codigo;
	public:
	  CLeitor(string, int);
	  virtual double getMensalidade() = 0;
};

/* 2.2) Implemente o respectivo método construtor e o método abstracto double getMensalidade. */

CLeitor::CLeitor(string n, int c): nome(n), codigo(c){}	  	  
double CLeitor::getMensalidade(){}

/* 2.3) Na classe CBiblioteca, implemente o método CLivro& getLivro(string &tituloL), que retorna o livro 
cujo título é tituloL.  */

CLivro& CBiblioteca::getLivro(string &tituloL)
{
	for(int i=0; i<livros.size(); i++){
		if(tituloL==livros[i].getTitulo()) return livros[i];
	}	
}

/* 2.4) Na classe CLivro, implemente o operador +. A soma de dois livros só pode ser realizada se os livros forem 
iguais (tiverem o mesmo ISBN). Nesse caso, a soma é um outro livro com o titulo, autor e ISBN do primeiro, e 
número de exemplares igual à soma do número de exemplares dos dois livros. */

CLivro CLivro::operator+ (CLivro livro1)
{
	if (livro1.getISBN() != getISBN()) { cerr << "Impossivel Somar! "; return *this; }
	CLivro novo(titulo, autor, ISBN, this->getNumExemp()+livro1.getNumExemp());
	return novo;
}

/* 2.5) Suponha que os leitores podem ser de dois tipos: sócios e não sócios. Construa a subclasse LeitorSocio. 
Os leitores sócios pagam uma determinada mensalidade à biblioteca, e podem requisitar um número ilimitado de livros. 
O valor da mensalidade é um argumento do construtor. Implemente o método construtor e o método getMensalidade(). */ 

class CLeitorSocio: public CLeitor
{
	double mensalidade;
   public:
	CLeitorSocio(string n, int c, double me): mensalidade(me), CLeitor(n,c) { }	
	double getMensalidade() { return mensalidade;}
};

/* 2.6) Construa a subclasse LeitorNaoSocio. Os leitores não sócios possuem um número limite de livros que podem 
requisitar (argumento do construtor). Esta classe possui também o atributo livrosReq que indica o número de livros 
que requisitou nesse mês, e o atributo taxa (taxa de empréstimo que é um argumento do construtor). 
A mensalidade a pagar é igual a  livrosReq*taxa. Implemente o método construtor e o método getMensalidade(). */
class CLeitorNaoSocio: public CLeitor
{
	const int numLimite;
	int livrosReq;
	double taxa;
   public:
	CLeitorNaoSocio(string n, int c, int nl, double t): numLimite(nl), taxa(t), CLeitor(n,c) { }
	double getMensalidade() { return taxa*livrosReq;}
};

/* 2.7) Na classe CBiblioteca, implemente o método getMensalidade(), que retorna o valor da mensalidade paga por 
todos os leitores da biblioteca. */ 
double CBiblioteca::getMensalidade()
{
	double total=0.0;
	for(int i=0; i<leitores.size(); i++)
		total += leitores[i]->getMensalidade();
	return total;
}

/* 2.8) Considere que pretendia realizar a operação de requisição de um livro por parte de um leitor.
 Especifique quais as estruturas de dados que usaria, alterando/adicionando os atributos das 
 classes que entender.  Explique como realizaria a operação de requisição de um livro. 
 Não precisa apresentar código. */

/*
 bool requisita(string tituloL, int codigo)
 função requisita
 procura livro, verifica se existe e se há exemplares >0
 procura socio verifica e chama função requisita livro do leitor
 se é socio não faz nada
 se não é socio verifica se livrosreq < num limite e incrementa livros req
 decrementa num exemplares
*/

/* 2.9) Suponha que deseja copiar a informação completa relativa a todos os livros da biblioteca para uma fila de modo a serem 
posteriormente processados. Apresente a declaração de tal fila e o código que lhe permite efectuar a referida cópia. */

int main()
{
	return 0;
}
