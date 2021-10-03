#include "Jogo.h"
#include <sstream>

Jogo::Jogo(int niv, vector<int> &pontos, vector<bool> &estados )
{
     int p=0;
     jogo=criar_jogo(p,niv,pontos,estados);
}

BinaryTree<Circulo> Jogo::criar_jogo(int p,int niv, vector<int> &pontos, vector<bool> &estados)
{
      if (niv==0)
      {
          Circulo c(pontos[p],estados[p]);
          BinaryTree<Circulo> bt(c);
          return bt;
      }
      else
      {   BinaryTree<Circulo> esq,dir;
          esq=criar_jogo(2*p+1,niv-1,pontos,estados);
          dir=criar_jogo(2*p+2,niv-1,pontos,estados);
          Circulo c(pontos[p],estados[p]);
          BinaryTree<Circulo> bt(c,esq,dir);
          return bt;
      }
}
ostream &operator << (ostream &os, Circulo &c1)
{
        os<<c1.pontuacao<<"-"<<c1.estado<<"-"<<c1.nVisitas;
        }

string Jogo::escreveJogo()
{
       stringstream s;
       BTItrLevel<Circulo> it(jogo);
       while (!it.isAtEnd())
       {
             Circulo c=it.retrieve();
             s<<c.getPontuacao()<<"-"<<c.getEstado()<<"-"<<c.getNVisitas()<<"\n";
             it.advance();
             }
       return s.str();   
}

int Jogo::jogada()
{
       BTItrLevel<Circulo> it(jogo);
       int p=0,prox=0,n=0;
       while (!it.isAtEnd())
       {
             if (p==prox) {
             Circulo c=it.retrieve();
             if (c.getEstado()) prox=2*p+2;
             else prox=2*p+1;
             it.retrieve().incNVisitas();
             it.retrieve().mudaEstado();
             n=c.getPontuacao();
             }
             p++;
             it.advance();
             }
       return n;
}

int Jogo::maisVisitado()
{
       BTItrLevel<Circulo> it(jogo);
       int max=0,p=0;
       while (!it.isAtEnd())
       {
             if (p) {
             Circulo c=it.retrieve();
             int n=c.getNVisitas();
             if(n>max) max=n;
             }
             p++;
             it.advance();
             }
       return max;    
}
