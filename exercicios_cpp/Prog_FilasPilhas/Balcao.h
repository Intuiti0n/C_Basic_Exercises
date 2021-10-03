#ifndef BALCAO_H_
#define BALCAO_H_

#include <iostream>
#include <queue>

using namespace std;

// Dados aos alunos
class Cliente {
      int numPresentes;
public:
       Cliente();
       int getNumPresentes();
};


// Dados aos alunos
class Balcao {
      queue<Cliente> clientes;
      const int tempo_embrulho;
      int prox_chegada, prox_saida;
      int tempo_actual;
      int clientes_atendidos;
public:
       Balcao(int te=2);
       void proximoEvento();
       int getTempoActual();
       int getProxChegada();
       void chegada();
       void saida();
       friend ostream & operator << (ostream & out, const Balcao & b1);
       int getTempoEmbrulho() const;
       int getProxSaida();
       int getClientesAtendidos();
       Cliente & getProxCliente();
};

#endif
