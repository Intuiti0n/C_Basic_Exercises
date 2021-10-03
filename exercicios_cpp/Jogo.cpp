#include "Jogo.h"

void Jogo::insereCrianca(Crianca & c1)
{
     criancas.push_back(c1);
 }

const list<Crianca>& Jogo::getCriancasJogo() const
{
     return criancas; 
}

string Jogo::escreve()
{
    string s="";
    for(list<Crianca>::iterator it =criancas.begin();it!=criancas.end();++it)
           s+=it->getNome()+", ";
    return s;  
}

int Jogo::nPalavras(string frase)
{
    int npal=0;
    int i=0;
    while (i<frase.length())
    {
    while (i<frase.length()&&frase[i]==' ') i++;
    if (i<frase.length()) npal++;
    while (i<frase.length()&&frase[i]!=' ') i++;    
    }
    return npal;
}

Crianca& Jogo::perdeJogo(string frase)
{
         int npal=nPalavras(frase);
         cout<<escreve()<<endl;
//         cout<<npal<<endl;
         list<Crianca> lc=criancas;
         list<Crianca>::iterator it=lc.begin();
         while (lc.size()>1)
         {
         for(int i=1;i<npal;i++)
         {
                 if (it==lc.end())
                    {it=lc.begin();it++;}
                 else it++;
         }
         if (it==lc.end()) it=lc.begin();
         cout<<"livrou-se "<<(*it)<<endl;
//         system("Pause");
         it=lc.erase(it);
         if (it==lc.end()) it=lc.begin();
         }
         return *it;
}

list<Crianca>& Jogo::inverte()
{
        criancas.reverse();
        return criancas;
}

list<Crianca> Jogo::divide(int id)
{
        list<Crianca>::iterator it=criancas.begin();
        while (it!=criancas.end())
        {
              if((it->getIdade())>id)
                  it=criancas.erase(it);
              else it++;
        }
        return criancas;
}

void Jogo::setCriancasJogo(list<Crianca>& l2)
{
     criancas=l2;
 }

bool Jogo::operator==(Jogo& j2)
{
     return (this->criancas==j2.criancas);
 }
 
list<Crianca> Jogo::baralha(const list<Crianca> & lista)
{
     list<Crianca> ln,ll=lista;
     while (!ll.empty())
     {
           int n=rand()%(ll.size());
           list<Crianca>::iterator it=ll.begin();
           for(int i=0;i<n;i++) it++;
           ln.push_back(*it);
           it=ll.erase(it);
     }
     return ln;
}
