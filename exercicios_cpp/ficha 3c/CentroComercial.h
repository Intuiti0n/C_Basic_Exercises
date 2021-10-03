#ifndef _CENTROCOMERCIAL_H
#define _CENTROCOMERCIAL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class LOJA {  //Classe simples podia ser uma struct
  public:
    string nome;
    string tipo;
    int renda;
};

class CCentroComercial {
private:
  vector<LOJA> lojas;

public:
  void ler_lojas(const char *nome);
  void imprimir_lojas(ostream &output, string tipo);
  void imprimir_lojas(ostream &output);
  void alterarRenda(int, int);
  void show_lista();
  void gravarLojas(const char *filename, CCentroComercial lj);
  void ordenarLojas();
  friend ostream& operator<< (ostream& os, const LOJA & loja);
};
#endif
