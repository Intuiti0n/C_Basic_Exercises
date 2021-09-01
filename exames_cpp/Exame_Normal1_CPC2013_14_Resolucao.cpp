#include<iostream>
#include<vector>

using namespace std;

//Grupo 2
class Jogador {
   string nomeJogador;
   int codigo;
   int numFichas;
public:
   Jogador (int cod, int nf, string nomeJ) 
      { codigo=cod; numFichas=nf; nomeJogador=nomeJ; }
   int getCodigo() const { return codigo; }
   string getNomeJogador() const {return nomeJogador;}
   int getNumFichas();
   void imprimeJogadorInfo();
   int operator++();
};
class Jogo {
  protected:
   string nomeJogo;
   vector<Jogador> jogadores;  // posicao no vector indica vez de jogada
  public:
   Jogo(string nm) { nomeJogo=nm; }
   string getNomeJogo() const { return nomeJogo; }
   vector<Jogador> getJogadores() const { return jogadores; } 
   bool eliminaJogador(string nomeJ);
   void adicionaJogador(Jogador j) { jogadores.push_back(j); } //aux
   virtual void imprimeJogoInfo(){
		for(int i=0; i<jogadores.size(); i++) jogadores[i].imprimeJogadorInfo();
   }
   Jogo operator+(const Jogo &jogo2);
};
class Casino {
   vector<Jogo *> mesas; 
  public:
   void adicionaMesa(Jogo *jog1) { mesas.push_back(jog1);  }
   void imprimeInfo(); 
   void ordenaMesas();
};
//2.1) Implemente na classe Jogador o método getNumFichas
int Jogador::getNumFichas() {  //int %1  Jogador:: %1
	return numFichas;   //%3
}

//2.2) Implemente as classes BlackJack e Poker como subclasses de Jogo.
// Implemente os respetivos construtores. Considere que a classe 
//BlackJack possui o membro-dado dealer, que é uma string que indica o 
//nome do jogador que tem o papel de dealer (distribui as cartas) 
//nesse jogo. Considere que a classe Poker possui o membro-dado 
//apostaMin, que é um inteiro indicativo do nº mínimo de fichas que 
//qualquer jogador é obrigado a apostar nesse jogo.

class BlackJack:public Jogo {  //nome %1, herança %1
  protected:
    string dealer;  //%1
  public:
    BlackJack(string d, string nm):Jogo(nm) { dealer=d; }  //%1
    void imprimeJogoInfo(){ 
   		cout << "BlackJack com Dealer: " << dealer << endl; 
		Jogo::imprimeJogoInfo();
	}
};

class Poker:public Jogo {  //repetir correto %1
  protected:
   int apostaMin;
  public:
   Poker(int apm, string nm):Jogo(nm) { apostaMin=apm; }
    void imprimeJogoInfo(){ 
   		cout << "Poker com ApostaMin: " << apostaMin << endl; 
		Jogo::imprimeJogoInfo();
	}
};

//2.3) Implemente na classe Jogador o método: void imprimeJogadorInfo().
// Este método imprime no standard output (monitor) informação sobre o 
//jogador incluindo o código, nome e fichas.

void Jogador::imprimeJogadorInfo()
{
   cout << "Codigo: " << codigo <<   //%2
           " / Nome: " << nomeJogador << //%2
		   " / Fichas: " << numFichas << endl;  //%1
}

//2.4) Implemente na classe Casino o método: void imprimeInfo(). 
//Este método imprime no standard output (monitor) informação sobre 
//todos os jogos existentes, nomeadamente: o nome do jogo, informação 
//própria do jogo (qual o dealer se blackjack, ou qual a aposta mínima 
//se poker) e o nome dos jogadores que estão nesse jogo.

void Casino::imprimeInfo()
{
	for(int i=0; i<mesas.size(); i++){
		cout << "Mesa " << i+1 << ": " << mesas[i]->getNomeJogo() << endl;
		mesas[i]->imprimeJogoInfo();
	}
}

//2.5) Implemente na classe Jogo o método bool eliminaJogador(string 
//nomeJ). Este método procura o jogador de nome nomeJ no jogo. 
//Se existir, elimina-o, escreve no ecran uma mensagem "Jogador Nome 
//eliminado" e retorna true. Se não existir, escreve "Jogador Nome 
//inexistente" e retorna false.

bool Jogo::eliminaJogador(string nomeJ)
{
	for(int i=0; i<jogadores.size(); i++)
		if(jogadores[i].getNomeJogador() == nomeJ) {
			jogadores.erase(jogadores.begin()+i);
			cout << "Jogador " << nomeJ << " eliminado" << endl;
			return true;
		}
	cout << "Jogador " << nomeJ << " inexistente" << endl;
	return false;
}

//2.6) Implemente na classe Jogador o operador ++ Jogador operator++(). 
//Suponha que incrementar um jogador significa simplesmente duplicar 
//as suas fichas!

int Jogador::operator++()
{
	numFichas *= 2;
	return numFichas;
}

//2.7) Implemente na classe Jogo o operador + Jogo operator + (const 
//Jogo &jogo2). Dois jogos só podem ser somados se tiverem o mesmo nome. 
//A soma de dois jogos é um outro jogo cujos jogadores são os 
//existentes nos dois jogos (não precisa de eliminar repetidos).

Jogo Jogo::operator+(const Jogo &jogo2)
{
	if (nomeJogo!=jogo2.nomeJogo) return *this;
	Jogo final(nomeJogo);
	for(int i=0; i<getJogadores().size(); i++)
		final.adicionaJogador(getJogadores()[i]);
	for(int i=0; i<jogo2.getJogadores().size(); i++)
		final.adicionaJogador(jogo2.getJogadores()[i]);
	return final;
}

//2.8) Implemente na classe Casino o método: void ordenaMesas(). Este 
//método ordena o vector mesas, crescentemente pelo número de jogadores 
//presentes em cada mesa.
void Casino::ordenaMesas()
{
	for(int i=0; i<mesas.size()-1; i++)
	  for(int j=i+1; j<mesas.size(); j++)
		if (mesas[i]->getJogadores().size()>
			mesas[j]->getJogadores().size()){
				Jogo* aux = mesas[i]; mesas[i]=mesas[j]; mesas[j]=aux;
			}
}

//Main para teste das alineas 2.1 a 2.8
int main()
{
	Jogador jogador1(1,1000,"Paulo");
	cout << jogador1.getNumFichas() << endl;
	jogador1.imprimeJogadorInfo();
	
	Jogo jogo1("JogoInicial");
	jogo1.adicionaJogador(Jogador(1,1000,"Luis"));
	jogo1.adicionaJogador(Jogador(2,1000,"Antonio"));
	jogo1.adicionaJogador(Jogador(3,600,"Mario"));
	jogo1.adicionaJogador(Jogador(4,300,"Joao"));	
	jogo1.eliminaJogador("Mario");
	jogo1.eliminaJogador("Joaquim");
	
	Poker jogo2(100,"NovoJogoPoker");
	jogo2.adicionaJogador(Jogador(1,5000,"Mario"));
	jogo2.adicionaJogador(Jogador(2,3000,"Ana"));
	jogo2.adicionaJogador(Jogador(3,2000,"Joana"));	

	BlackJack jogo3("Silva","JogoDeBlack");
	jogo3.adicionaJogador(Jogador(1,2000,"Bruno"));
	jogo3.adicionaJogador(Jogador(2,1500,"Carlos"));
	jogo3.adicionaJogador(Jogador(3,800,"Eduardo"));		
	jogo3.adicionaJogador(Jogador(4,500,"Joana"));
	
	Jogo jogo4("JogoInicial");
	jogo4.adicionaJogador(Jogador(1,500,"Ana"));
	jogo4.adicionaJogador(Jogador(2,500,"Anabela"));
	
	Casino cas;
	cas.adicionaMesa(&jogo1);
	cas.adicionaMesa(&jogo2);
	cas.adicionaMesa(&jogo3);
	cas.adicionaMesa(&jogo4);
	cas.imprimeInfo();
	cout << endl;
	
	cout << ++jogador1 << endl; 
	jogador1.imprimeJogadorInfo();
	cout << endl;
	
	Jogo novo = jogo1+jogo4;
	novo.imprimeJogoInfo();	
	cout << endl;
	
	cas.ordenaMesas();
	cas.imprimeInfo();
	
	return 0;
}

//Grupo 3 - Tópicos de Resolução (Incompleto)
class CData{
  protected:
	int dia, mes, ano;
  public:
  	CData(int d, int m, int a) { dia=d; mes=m; ano=a; } //falta verificar dados
};

class CInsc{
  protected:
  	string codPess, codCurso;
	int anoLetivo, nota;
  public:
};

class CPessoa {
  protected:
	string codPess, nome, morada, telefone;
	CData dataNasc;	
  public:
//  	CPessoa(...){ 
//	  	codPess=cp, nome=no; morada=mo; telefone=t; dataNasc(d,m,a);}
//  	}
};

class CFuncionario: public CPessoa {
  public:
//  	CFuncionario(...): CPessoa(...) {...;}
};

class CDocente: public CPessoa {
  protected:
  	vector <string> disc;
  public:
};

class CAluno: public CPessoa {
  protected:
  	string codCurso;
	vector <CInsc> inscricoes;
  public:
};

class CDisciplina {
  protected:
  	string codDisc, programa;
	string codDocResp;  //codigo responsavel (podia ser CDocente)
	int ano;
	double ECTS,carga;
	vector <string> alunos;  //codigos alunos 
	vector <string> docentes; //codigos docentes
  public:
};

class CCurso {
  protected:
		string tipo; //ou enum
		string cod, nome;
		CDocente diretor;  //ou codigo (string)
		vector <string> codDep;
		vector <CDisciplina> planoCurr;
  public:
};

class CInstituicao {
  protected:
		string codInst, nome, morada, telefone;
  public:
};

class CDepartamento: public CInstituicao {
  protected:
		CDocente diretor;	
  public:
};

class CEscola: public CInstituicao {
		vector <CDepartamento> depart;	
		CDocente presidente;
  public:
};

class CUniversidade: public CInstituicao {
  protected:
		vector <CEscola> escolas;
		vector <CCurso> cursos;
		CDocente reitor;
  public:
};
 
