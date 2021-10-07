#include "calunoprog.h"

//CONSTRUCTORS AND DESTRUCTORS--------------------------------------------------------------------------------------
CAlunoProg::CAlunoProg()
{
    this->numAluno = 0;
    this->nomeAluno = "";
    this->exame = 0;
    this->trabFin = 0;
    this->trabInt = 0;
    this->notasMiniTestes.push_back(0);
    this->notasMiniTestes.push_back(0);
    this->notaFinal = 0.15 * trabInt + 0.25 * trabFin + 0.2 * (notasMiniTestes[0]+notasMiniTestes[1])+0.4*exame;
}

CAlunoProg::CAlunoProg(int numero, string nome){
    this->nomeAluno = nome;
    this->numAluno = numero;

}

CAlunoProg::~CAlunoProg(){
    return;
}
//SET FUNCTION IMPLEMENTATION---------------------------------------------------------------------------------------
void CAlunoProg::setNomeAluno(string nome){
    this->nomeAluno = nome;
}
void CAlunoProg::setNumAluno(int num){
    this->numAluno = num;
}
void CAlunoProg::setTrabFin(double nota){
    this->trabFin = nota;
}
void CAlunoProg::setTrabInt(double nota){
    this->trabInt = nota;
}
void CAlunoProg::setNotasMiniTestes(vector<double>vec){
    this->notasMiniTestes = vec;
}
void CAlunoProg::setNotaExame(double exame){
    this->exame = exame;
}


//GET FUNCTION IMPLEMENTATION---------------------------------------------------------------------------------------
string CAlunoProg::getNomeAluno(void){
    return nomeAluno;
}
int CAlunoProg::getNumAluno(void){
    return numAluno;
}
double CAlunoProg::getTrabFin(void){
    return trabFin;
}
double CAlunoProg::getTrabInt(void){
    return trabInt;
}
double CAlunoProg::getNotasMiniTestes(int numMiniTeste){
    return notasMiniTestes[numMiniTeste];
}
double CAlunoProg::getNotaExame(void){
    return exame;
}
double CAlunoProg::calculaNotaFinal(void){
    notaFinal = 0.15 * trabInt + 0.25 * trabFin + 0.2 * (notasMiniTestes[0]+notasMiniTestes[1])+0.4*exame;
    return this->notaFinal;
}

void CAlunoProg::printFichaAluno(void){
    cout << "Ficha do aluno nº "<<numAluno<<endl;
    cout << "Nome: "<<nomeAluno<<endl;
    cout << "Nota Final: "<<notaFinal<<endl;
    if(notaFinal >= 9.5 && notaFinal <=20)
            cout << "Aprovado!"<<endl;
    else cout << "Reprovado!" <<endl;
}
