#ifndef _AlunoProg_H_
#define _AlunoProg_H_

#include <iostream>
#include <string>


using namespace std;

class CAlunoProg
{
	public:
		CAlunoProg();
		CAlunoProg(int, string);
		void setNumAluno(int);
		void setNomeAluno(string);
		void setTrabInt(double);
		void setTrabFin(double);
		void setExame(double);
		void setNotaMiniTeste(int, float);
		void printFichaAluno();
		float notaFinal;
		~CAlunoProg();
			
		int getNumAluno();
		string getNomeAluno();
		double getTrabInt();
		double getTrabFin();
		double getExame();
		float getNotaMiniTeste(int numMiniTeste);
		float getNotaFinal();
		float calculaNotaFinal();
				
		
	private:
		int numAluno;
		string nomeAluno;
		double trabInt, trabFin, notasMiniTestes[2], exame;
		
		
};
#endif


