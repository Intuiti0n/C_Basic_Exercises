#include <queue>
#include <cstdlib>
#include "Balcao.h"

using namespace std;

Cliente::Cliente()
{
      numPresentes=rand()%5+1;
}

int Cliente::getNumPresentes()
{ return numPresentes;}

Balcao::Balcao(int te):tempo_embrulho(te)
{
      tempo_actual=0;
      prox_chegada=rand()%20+1;
      prox_saida=0;
      clientes_atendidos=0;             
}

int Balcao::getTempoActual()
{return tempo_actual;}

int Balcao::getProxChegada()
{return prox_chegada;}
      
int Balcao::getTempoEmbrulho() const
{return tempo_embrulho;}

int Balcao::getProxSaida()
{return prox_saida;}

int Balcao::getClientesAtendidos()
{return clientes_atendidos;}

Cliente & Balcao::getProxCliente()
{
        if (clientes.empty()) throw FilaVazia();
        return clientes.front();
}

void Balcao::chegada()
{
     Cliente c;
     clientes.push(c);
     prox_chegada=tempo_actual+rand()%20+1;
     prox_saida=tempo_actual+c.getNumPresentes()*tempo_embrulho;
     cout<<"Tempo atual="<<tempo_actual<<endl
     <<"Chegou Cliente com "<<c.getNumPresentes()<<" presentes"<<endl;
 }
 
 void Balcao::saida()
 {
      try {
      Cliente c=getProxCliente();
      clientes.pop();
      clientes_atendidos++;
      if (clientes.empty()) prox_saida=0;
      else prox_saida=tempo_actual+clientes.front().getNumPresentes()*tempo_embrulho;
     cout<<"Tempo atual="<<tempo_actual<<endl
     <<"Saiu Cliente com "<<c.getNumPresentes()<<" presentes"<<endl;
      }
      catch (FilaVazia ex)
      {
            cout<<"Erro na saida: "<<ex.getMsg()<<endl;
      }
  }
  
  void Balcao::proximoEvento()
  {
       if (prox_saida==0)
       {
          tempo_actual=prox_chegada;
          this->chegada();
       }
       else
           if (prox_saida<prox_chegada)
             { 
              tempo_actual=prox_saida;
              this->saida();}
           else
           {
               tempo_actual=prox_chegada;
               this->chegada();}
   }

ostream & operator << (ostream & out, Balcao & b1)
{
        out<<"Clientes atendidos: " << b1.getClientesAtendidos()
        <<" Numero de Clientes em espera: "<<b1.clientes.size()<<endl;
}

