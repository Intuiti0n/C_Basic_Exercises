#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CConta {
   int cod_conta;
   string nome;
   double saldo;
public:
   CConta(int, string); 
   double getSaldo() const;
   int getCodConta() const; // método adicionado
   string getNomeCliente() const {return nome;}
   CConta operator- (int quantia);// adicionado
   bool operator> (const CConta &conta2); //adicionado
   void setSaldo(double); // método adicionado
};

class CAgencia {
   string nomeAgencia;
   string morada;
   vector <CConta> contas;
public:
   CAgencia(string, string);
   string getNomeAgencia() const {return nomeAgencia;} // método adicionado
   int adicionarConta(int, string);
   void listarContas(ostream &os); 
   void listarContasnegativas(); //método adicionado
   void ordenaContas();//adicionado
   void alteraSaldo(int n, double s); //método adicionado
};

class CBanco {
   string nome;
   vector <CAgencia> agencias;
   public: // adicionado
           CBanco(string); //método adicionado
           void adicionarAgencia(CAgencia ag); //método adicionado
          void imprimeContasNegativas(); //método adicionado
};

//2.1) Implemente os construtores das classes CConta e CAgencia.

CConta::CConta(int num, string nom)
{ cod_conta=num; nome=nom; saldo=0;}

CAgencia::CAgencia(string nome, string mor)
{ nomeAgencia=nome; morada=mor;}

//2.2) Implemente o método getSaldo da classe CConta.

double CConta::getSaldo() const {return saldo;}

//2.3) Implemente na classe CAgencia o método adicionarConta.
//Este método deve retornar o número de contas existentes na agência, após a adição da nova conta.

int CAgencia::adicionarConta(int num, string nom)
{
    CConta conta(num,nom);
    contas.push_back(conta);
    return contas.size();
}

//2.4) Implemente o método listarContas da classe CAgencia.
//Este método deve apresentar em cada linha, o código da conta, nome do titular e respectivo saldo.

int CConta::getCodConta() const {return cod_conta;}

void CAgencia::listarContas(ostream &os)
{
     os << endl<<"Contas da Agencia: "<<nomeAgencia<<endl<<endl;
     for (int i=0;i<contas.size();i++)
     os<<"Codigo da conta: "<<contas[i].getCodConta()<<"   "
     <<"Nome do titular: "<<contas[i].getNomeCliente()<<"  "
     <<"Saldo: "<<contas[i].getSaldo()<<endl;
 }
//2.5) Implemente na classe CBanco um novo método: void imprimeContasNegativas(). 
//Este método imprime no standard output (monitor) informação sobre as contas negativas existentes em cada agência. Para cada agência deve indicar o seu nome e a informação 
//sobre os titulares das contas (cod_conta e nome) das contas com saldo inferior a zero.

void CAgencia::listarContasnegativas()
{
     for (int i=0;i<contas.size();i++)
     if (contas[i].getSaldo()<0)
     cout<<"Codigo da conta: "<<contas[i].getCodConta()<<"   "
     <<"Nome do titular: "<<contas[i].getNomeCliente()<<endl;
 }


void CBanco::imprimeContasNegativas()
{
     cout<<endl<<"Listagem de contas negativas do Banco "<<nome<<endl<<endl;
     for (int i=0;i<agencias.size();i++)
     {
         cout<<"Agencia - "<<agencias[i].getNomeAgencia()<<endl<<endl;
         agencias[i].listarContasnegativas();
         
     }
 }
 
 //2.6) Implemente na classe CConta o operador - CConta operator- (int quantia). 
 //A operação - (que retira uma dada quantia da conta) 
 //só pode ser realizada se o saldo da conta não ficar negativo!


CConta CConta::operator- (int quantia)
{
       
       saldo=(saldo-quantia>=0)?saldo-quantia:saldo;
       return *this;
}

// 2.7) Implemente na classe CConta o operador >, ou seja: bool operator > (const CConta &conta2). 
//Este operador permite comparar duas contas, tendo em conta o valor do seu saldo.

bool CConta::operator> (const CConta &conta2)
{
     return saldo>conta2.saldo;
 }

//2.8) Implemente na classe CAgencia o método: void ordenaContas().
//Este método ordena o vector contas, da agência, crescentemente, pelo nome dos titulares das contas.

void CAgencia::ordenaContas()
{
     for (int i=0;i<contas.size()-1;i++)
          for (int j=i+1;j<contas.size();j++)
              if (contas[i].getNomeCliente()>contas[j].getNomeCliente())
                 { 
                    CConta aux=contas[i];
                    contas[i]=contas[j];
                    contas[j]=aux;
                 }
 }

//2.9) Implemente uma função main() (programa principal) que lhe permita testar as 8 alíneas anteriores.

CBanco::CBanco(string nom) {nome=nom;}

void CBanco::adicionarAgencia(CAgencia ag)
{
    agencias.push_back(ag);
}

void CConta::setSaldo(double s){saldo=s;}

void CAgencia::alteraSaldo(int n, double s)
{
     int i=0;
     while (i<contas.size()&&contas[i].getCodConta()!=n)
     i++;
     if (i<contas.size())
     contas[i].setSaldo(s);
 }

int main()
{
    CBanco banco("Mau");
    CAgencia ag1("Dep1","sem morada 1");
    ag1.adicionarConta(3,"cc");
    ag1.alteraSaldo(3,5);
    ag1.adicionarConta(1,"aa");
    ag1.alteraSaldo(1,10);
    ag1.adicionarConta(4,"dd");
    ag1.alteraSaldo(4,-1);
    ag1.adicionarConta(2,"bb");
    ag1.alteraSaldo(2,-2);
    ag1.listarContas(cout);
    ag1.ordenaContas();
    ag1.listarContas(cout);
    banco.adicionarAgencia(ag1);
    banco.imprimeContasNegativas();
    CConta c1(5,"ab");
    c1.setSaldo(2);
    cout<<"saldo: "<<c1.getSaldo()<<endl;
    CConta c2=c1-5;
    cout<<"Novo saldo: "<<c2.getSaldo()<<endl;
    c2=c1-1;
    cout<<"Novo saldo: "<<c2.getSaldo()<<endl;
    c1.setSaldo(5);
    if(c1>c2) cout<<"Saldo de c1 e' maior"<<endl;
    system("Pause");
    return 0;
}

/*
GRUPO III (4.0 Valores)
 
Pretende-se guardar informação sobre uma colecção de filmes com a seguinte definição:
- Uma colecção é composta por um conjunto de filmes. 
- Cada filme possui um título, ano de estreia, realizador, um conjunto de atores e um conjunto de classificações dadas pelos utilizadores do sistema. 
- Uma classificação de um utilizador a um filme, contém um valor numérico (1 a 5) e um comentário opcional (texto até 255 caracteres). Contém também indicação de qual o utilizador que a realizou.
- Para cada ator interessa unicamente o seu nome, ano de nascimento e nacionalidade.
- O sistema armazena ainda os dados de cada utilizador que incluem a sua identificação (código numérico), nome, password (código alfanumérico com 8 caracteres) e o número de filmes que já classificou.
- Existem ainda um conjunto de categorias de filmes ("comédia", "ficção", "drama", etc) e cada filme tem uma dada categoria.
Defina um conjunto de classes que na sua opinião melhor descreve o cenário acima, especificando os dados, construtores e destrutures (se necessário) de cada classe. Implemente ainda métodos get e set, exemplificativos, para uma única classe à sua escolha Justifique as suas escolhas. Nota: Não é necessário implementar qualquer método, simplesmente definir os ficheiros *.h das classes respetivas. 

*/

//Tópicos de resolução - existem outras possíveis soluções

class CUtilizador {
      int cod_util;
      string nome;
      char password[9];
      int nfilmes;
      public:
             CUtilizador(int cod, string nom){cod_util=cod;nome=nom;}
      };

class CClassif {
      int valor;
      string comentario;
      int cod_util;
      public:
             CClassif(int cod, int v, int coment =""){cod_util=cod;valor=(v>=1&&v<=5)?v:1;comentario=coment;}
             int getValor() const {return valor;}
             string getComentario() const {return comentario;}
             int getCodUtil() const {return cod_util;}
             void setCodUtil(int cod) {cod_util=(cod>0)?cod:1;}
             void setValor(int v){valor=(v>=1&&v<=5)?v:1;}
             void setComentario(string coment){comentario=coment;}
      };      

class CAtor {
      string nome;
      int ano_nasc;
      string nacionalidade;
      public:
             CAtor(string nom, int a, string nac) {nome=nom;ano_nasc=a; nacionalidade=nac;}
      };       

class CFilme {
      string titulo;
      int ano_estreia;
      string realizador;
      string categoria;
      vector <CAtor> atores;
      vector <CClassif> classificacoes;
      public:
      CFilme(string t, int a, string r){titulo=t;ano_estreia=a;realizador=r;}
      };

class Colecao_filmes {
      vector <CFilme> filmes;
      };
