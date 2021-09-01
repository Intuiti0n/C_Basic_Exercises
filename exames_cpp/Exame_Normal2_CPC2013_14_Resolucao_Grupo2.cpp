#include <iostream>
#include <cstdio>
#include <vector>
#include "Stack.h"
#include <Stack>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

class CTemaLivros {
    string tema;
    stack<string> livros;
  public:
    CTemaLivros(string tm="diversos"): tema(tm) {}
    string getTema();
    stack<string> &getLivros() { return livros; }
    bool operator!= (const CTemaLivros &l1) { return tema!=l1.tema; }
    void imprimeTemas(vector <CTemaLivros> bib);
    void ordenaTemas(vector <CTemaLivros> bib);
    void escreveBib(vector <CTemaLivros> bib);
    void devolucao(vector<CTemaLivros> bib, const string nomeL, const string temaX);
    void eliminaTopo(vector<CTemaLivros> bib);
    int procuraTema(const vector<CTemaLivros> bib, const string temaX);
    
};


using namespace std;

//Grupo 2


//2.1) Implemente na classe CTemaLivros o método getTema
string CTemaLivros::getTema() {  
	return tema;   
}

//2.2) Implemente a função que imprime o título de todos os 
//temas existentes no vetor

void imprimeTemas(vector <CTemaLivros> bib)
{
	
	for(int i=0; i<bib.size(); i++){
		cout << "Tema: " << bib[i].getTema() << endl;
	}
}

//2.3) Implemente a função que ordena os títulos de todos os 
//temas existentes no vetor.

void ordenaTemas(vector <CTemaLivros> bib)
{ 
	
	for(int i=1; i<bib.size(); i++)
	{
		int j;
		CTemaLivros temp = bib[i];
		for(j = i; j > 0 && temp.getTema() < bib[j-1].getTema(); j--)
	  	{
			bib[j]=bib[j-1]; 
		}
		bib[j]=temp;
	}
}

//2.4) Implemente a função que imprime o título de todos os 
//livros existentes na biblioteca, apresentando-os por temas: 
//void escreveBib(vector<CTemaLivros> bib). 
//Esta função escreve no monitor o título de cada tema, 
//seguido dos títulos dos livros desse tema existentes na 
//biblioteca bib sem alterar o conteúdo da biblioteca.
//bool sortByTema(const CTemaLivros &lhs, const CTemaLivros 
//&rhs) { return lhs.tema < rhs.tema; }

void escreveBib(vector <CTemaLivros> bib)
{
    ordenaTemas(bib);
	for(int i=0; i<bib.size(); i++)
	{
		cout << "Tema:" << bib[i].getTema() << endl;
		stack<string> Liv_temp(bib[i].getLivros());
		cout << "Livros:" << endl;
 		while (!Liv_temp.empty())
		{
	 		Liv_temp.pop();
	    	cout << Liv_temp.top() << endl;
		}
	}
}

//2.5) Implemente a função que procura na lista o elemento 
//relativo a um tema especificado. 
//CTemaLivros procuraTema(const vector<CTemaLivros> bib, 
//const string temaX). 
//Esta função pesquisa a lista de temas da biblioteca bib, 
//e retorna o elemento relativo ao tema temaX especificado 
//como argumento.

int CTemaLivros::procuraTema(const vector<CTemaLivros> bib, const string temaX)
{
	for (int i=0 ; i< bib.size() ; i++ )
	    if (bib[i].tema == temaX) 
		{ 
			return i;
		}
}

//2.6) Quando um livro é devolvido (ou um livro novo é 
//comprado), este é colocado no topo da pilha correspondente 
//ao seu tema. Implemente a função que realiza o processo 
//de devolução (ou compra) de um livro: 
//void devolucao(vector<CTemaLivros> bib, const string nomeL, 
//const string temaX). 
//Esta função repõe na biblioteca bib o livro de título 
//nomeL, pertencente ao tema temaX. 

void devolucao(vector<CTemaLivros> bib, const string nomeL, const string temaX)
{
	for (int i=0 ; i< bib.size() ; i++ )
	{
		ordenaTemas(bib);
	    if (bib[i].getTema() == temaX) 
			bib[i].getLivros().push(nomeL);
	} 
}

//2.7) Os livros que estavam no topo das pilhas começam a 
//ficar um pouco estragados, devido ao maior movimento que 
//apresentam. Implemente a função que elimina o elemento do 
//topo de todas as pilhas referentes a todos os temas que 
//existem na biblioteca: 
//void eliminaTopo(vector<CTemaLivros> bib). 

void eliminaTopo(vector<CTemaLivros> bib)
{
	for (int i=0 ; i< bib.size() ; i++)
	   bib[i].getLivros().pop();  
}


