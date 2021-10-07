#ifndef CALUNOPROG_H
#define CALUNOPROG_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CAlunoProg
{
private:
    string nomeAluno;
    int numAluno;
    double trabFin,trabInt;
    vector<double>notasMiniTestes;
    double exame;
    double notaFinal;
public:
    CAlunoProg();
    CAlunoProg(int numero, string nome);
    ~CAlunoProg();
    void setNomeAluno(string nome);
    void setNumAluno(int num);
    void setTrabFin(double nota);
    void setTrabInt(double nota);
    void setNotasMiniTestes(vector<double>vec);
    void setNotaExame(double exame);
    //void NotaFinal(void);

    string getNomeAluno(void);
    int getNumAluno(void);
    double getTrabFin(void);
    double getTrabInt(void);
    double getNotasMiniTestes(int numMiniTeste);
    double getNotaExame(void);
    double calculaNotaFinal(void);
    void printFichaAluno(void);
};

#endif // CALUNOPROG_H
