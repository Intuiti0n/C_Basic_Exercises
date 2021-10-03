#include "CAlunoProg.h"

#include <iostream>

CAlunoProg::CAlunoProg(){}

CAlunoProg::CAlunoProg(int numero, string nome)
{
	setNumAluno(numero);
	setNomeAluno(nome);
}

//DESTRUTOR

CAlunoProg::~CAlunoProg(){}

//METODOS SET

void CAlunoProg::setNumAluno(int numero)
{
	numAluno=numero;
}

void CAlunoProg::setNomeAluno(string nome)
{
	nomeAluno=nome;
}

void CAlunoProg::setTrabInt(double nota1 )
{
	trabInt=nota1;
}

void CAlunoProg::setTrabFin(double nota2 )
{
	trabFin=nota2;
}

void CAlunoProg::setNotaMiniTeste(int pos, float nota3 )
{
notasMiniTestes[pos] = nota3;
}

void CAlunoProg::setExame(double nota4 )
{
	exame=nota4;
}

// METODOS GET

int CAlunoProg::getNumAluno()
{
	return numAluno;
}

string CAlunoProg::getNomeAluno()
{
	return nomeAluno;
}


//OUTROS METODOS

float CAlunoProg::calculaNotaFinal()
{
	float notaFinal;
	
	notaFinal=((0.15*trabInt)+(0.25*trabFin)+(0.2*((notasMiniTestes[0]+notasMiniTestes[1])/2))
	+(0.4*exame));
	
	return notaFinal;
}

void CAlunoProg::printFichaAluno()
{
		
  float notaFinal2;
  notaFinal2 = calculaNotaFinal();
  string ClassificacaoFinal;
  if (notaFinal2 > 10) ClassificacaoFinal="Aprovado"; else ClassificacaoFinal="Reprovado";
  cout << "\nNumero Aluno: " <<numAluno<< endl;
  cout << "Nome Aluno: "<<nomeAluno << endl;
  cout << "Nota Final: "<<notaFinal2<< endl;
  cout << "Classificacao Final: "<<ClassificacaoFinal<< endl;
}
