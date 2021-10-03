#include "CAlunoProg.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	CAlunoProg aluno;
	int numA;
	string nomeA;
	double trabInt, trabFin, miniTeste1, miniTeste2, exame;
	
	cout<<"PROGRAMA ALUNO PROG"<<endl<<endl;
	cout<<"Numero: "; 
	cin>> numA;
	aluno.setNumAluno(numA);
	cout<<endl<<"Nome: ";
	cin>> nomeA;
	aluno.setNomeAluno(nomeA);
	cout<<endl<<"Nota avaliacao intercalar do trabalho: ";
	cin>> trabInt;
	aluno.setTrabInt(trabInt);
	cout<<endl<<"Nota avaliacao final do trabalho: ";
	cin>> trabFin;
	aluno.setTrabFin(trabFin);
	cout<<endl<<"Nota do primeiro mini-teste: ";
	cin>> miniTeste1;
	aluno.setNotaMiniTeste(1,miniTeste1);	
	cout<<endl<<"Nota do segundo mini-teste: ";
	cin>> miniTeste2;
	aluno.setNotaMiniTeste(2,miniTeste2);	
	cout<<endl<<"Nota do exame: ";
	cin>> exame;
	aluno.setExame(exame);	

	aluno.printFichaAluno();

	return 0;
}


