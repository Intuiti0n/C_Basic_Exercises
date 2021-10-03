// 4) Suponha o seguinte código representando a interface de um Jardim que se 
// encontra contido num ficheiro Jardim.h e se destina a gerir a informação 
// sobre todas as plantas de um Jardim/Horto. O nome das funções e das 
// variáveis indica a sua funcionalidade no programa. Na rotina 'main()' 
// do programa de gestão de informação do Jardim, entre outras coisas, consta 
// a declaração (e definição) 'CJardim  jard;'. Suponha que foram incluídos 
// todos os #include necessários.
 
// #includes e declarações gerais Jardim.h
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CPlanta {
   protected:
      string nome;
      string especie;
      int valor, custo;   // em euros
   public:
      CPlanta(string n, string e, int v, int c) {
          nome=n; especie=e; valor=v; custo=c; 
      }
      string getEspecie() const {return especie;}
      string getNome() const {return nome;}
      void setNome(string nom) {nome=nom;}
      int getValor() const; 
      int getCusto() const {return custo;}
      bool operator == (CPlanta outra);
};
 
class CJardim{    
      vector <CPlanta> plantas;
   public:
      void gravarJardim(char nomefich[]);
      void adicionarPlanta(string, string, int, int);
      void imprimirJardim(ostream &);
      void ordenarJardim();
      void substJardim(string nomeParte, string nomeSubst);
};

// Implementação das Funções Membro - Jardim.cpp

/*
4.1) Escreva o código da função int getValor() const; que retorna o 
     valor de uma dada planta.
*/

int CPlanta::getValor() const
{   
    return valor;
}

/*
4.2) Escreva o código da função 'void adicionarPlanta(string nom, 
     string esp, int val, int cus)', que acrescenta à estrutura de dados 
     a informação sobre uma nova planta adquirida.
*/

void CJardim::adicionarPlanta(string nom, string esp, int val, int cus)
{
     CPlanta pl(nom, esp, val, cus);
     plantas.push_back(pl);
}

/*
4.3) Escreva o código de 'imprimirJardim(ostream &os)', função que, se 
     invocada em 'main()' como 'jardim.imprimirJardim(cout);', vai 
     permitir mostrar no ecrã do computador a lista de plantas de 'jardim', 
     mostrando para cada uma a sua espécie, nome, valor e custo.
*/

void CJardim::imprimirJardim(ostream &os)
{
  os << endl << "Jardim:" << endl;
  for(int i=0; i<plantas.size();i++) {
          os << plantas[i].getNome()<< " " <<plantas[i].getEspecie()<< " " <<
                plantas[i].getValor()<<" " << plantas[i].getCusto()<<endl;
  }
}

/*
4.4) Escreva o código da função 'void ordenarJardim()', que altera a 
     estrutura de dados com a informação das plantas, ordenando-a 
     internamente segundo o valor das plantas, da menos para a mais 
     valiosa.
*/

void CJardim::ordenarJardim()
{
   for(int i=0; i<plantas.size()-1;i++) 
      for(int j=i+1; j<plantas.size(); j++)
          if (plantas[i].getValor() > plantas[j].getValor()) {
              CPlanta aux= plantas[i]; plantas[i]=plantas[j]; plantas[j]= aux;
          }
}

/*
4.5) Implemente um novo operador == que compara duas plantas retornando 
     verdadeiro caso tenham o mesmo nome, espécie, valor e custo.
*/

bool CPlanta::operator ==(CPlanta outra)
{
     return nome == outra.nome && valor == outra.valor && 
            especie == outra.especie && custo == outra.custo;
}

/*
4.6) Escreva o código de uma nova função membro da classe CJardim, 
     gravarJardim que receba o nome de um ficheiro (por exemplo 
     "jardimEstrela.txt") e grave o conteúdo do jardim ordenado segundo 
     o valor das plantas e não incluindo plantas repetidas. Sugestão: 
     use as funções e operadores das alíneas 2.4 e 2.5 (mesmo que não os 
     tenha implementado)
*/

void CJardim::gravarJardim(char nomefich[])
{
     ordenarJardim();
     ofstream fich(nomefich);
     for(int i=0; i<plantas.size();i++){
             if(i==0 || i!=0 && !(plantas[i]==plantas[i-1])) 
                fich << plantas[i].getNome()<< " " <<plantas[i].getEspecie()<< " " <<
                     plantas[i].getValor()<<" " << plantas[i].getCusto()<<endl;
     }
}

/*
4.7) Construa uma função membro da classe CJardim designada: 
     void substJardim(string nomeParte, string nomeSubst); 
     que substitua no nome de todas as plantas do jardim que incluam 
     nomeParte, essa parte do nome por nomeSubst. 
     Exemplo substJardim("Brasil", "América") transforma "Cana do Brasil" 
     em "Cana da América", "Planta Brasil Nova" em "Planta América Nova" 
     e assim por diante.
*/

void CJardim::substJardim(string nomeParte, string nomeSubst)
{
     for(int i=0; i < plantas.size(); i++) {
             string pl(plantas[i].getNome());
             int pos = pl.find(nomeParte);
             if(pos != string::npos){
                  pl.replace(pos, nomeParte.size(), nomeSubst);
                  plantas[i].setNome(pl);}
             }
}

//4-8 main_jardim.cpp 
//Main - Teste das Funcoes
int main()
{
    CPlanta pl("Couve Flor", "Couve", 2, 1);
    cout << pl.getNome() << endl;
    cout << pl.getValor() << endl;
    CPlanta pl2("Couve Flor", "Couve", 2, 1);
    //CPlanta pl2("Couve Flor", "Couve", 10, 3);
    if (pl==pl2) cout << "pl igual a pl2" << endl;
       else cout << "pl diferente de pl2" << endl;
    
    CJardim  jard;	
    jard.adicionarPlanta("Ananas1","Ananas",3,2);
    jard.adicionarPlanta("Ananas1","Ananas",3,2);
    jard.adicionarPlanta("Cravo1","Cravo",10,6);
    jard.adicionarPlanta("Ananas3","Ananas",5,2);
    jard.adicionarPlanta("Ananas4","Ananas",2,1);   
    jard.adicionarPlanta("Ananas4","Ananas",2,1); 
    jard.adicionarPlanta("Ananas4","Ananas",2,1); 
    jard.imprimirJardim(cout);
    
    jard.gravarJardim("ExemploJard.txt");      
  
    jard.ordenarJardim();
    jard.imprimirJardim(cout);
    
    jard.substJardim("Ananas", "Penca");
    jard.imprimirJardim(cout);
    
    system("PAUSE");
	return 0;
}

