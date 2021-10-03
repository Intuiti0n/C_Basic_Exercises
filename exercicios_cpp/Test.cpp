#include "Crianca.h"
#include "Jogo.h"

void test_0_Crianca() {

	Crianca a;
	cout<<a<<endl;
	Crianca b("Joao", 10);
	cout<<b<<endl;
	Crianca c("Pedro", 12);
	cout<<c<<endl;
	Crianca d = c;
	cout<<d<<endl;	
}

void test_a_insereCrianca() {

	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",6);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Vasco",5);

	Jogo jogo1;
	list<Crianca> cc = jogo1.getCriancasJogo();

	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	cc = jogo1.getCriancasJogo();

	Crianca c = cc.front();
	cout<<c<<endl;
	c = cc.back();
	cout<<c<<endl;

}

void test_b_imprimeJogo(){

	Jogo jogo1;
	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Vasco",5);
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	cout << jogo1.escreve()<<endl;

}

void test_c_nPalavras(){

	Jogo jogo1;
	string frase = "pim pam pum cada bola mata um";
    cout<<"A frase: "<<frase<<endl<<"tem "<<jogo1.nPalavras(frase)<<" palavras"<<endl;
}

void test_d_perdeJogo(){

	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",6);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Vasco",5);

	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
    Crianca c=jogo1.perdeJogo(s);
    cout<<"Perdeu a "<<c.getNome()<<endl;
}

void test_e_inverteJogo(){

	Crianca c1("Rui",6);
	Crianca c2("Vasco",5);
	Crianca c3("Ana",4);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Rita",6);

	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);
    cout<<jogo1.escreve()<<endl;
	list<Crianca> invertida = jogo1.inverte();
    cout<<jogo1.escreve()<<endl;
}

void test_f_divideJogo(){

	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",3);
	Crianca c4("Joao",5);
	Crianca c5("Marta",7);
	Crianca c6("Vasco",5);
	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);
    cout<<jogo1.escreve()<<endl;
	list<Crianca> dividida = jogo1.divide(5);
	Jogo jogo2(dividida);
    cout<<jogo2.escreve()<<endl;

}

void test_g_igualdadeJogo(){

	list<Crianca> criancas1;
	criancas1.push_back( Crianca("Rui",6) );
	criancas1.push_back( Crianca("Ana",4) );
	criancas1.push_back( Crianca("Rita",3) );
	criancas1.push_back( Crianca("Joao",5) );
	criancas1.push_back( Crianca("Marta",7) );
	criancas1.push_back( Crianca("Vasco",5) );
	criancas1.push_back( Crianca("Ines",5) );

	Jogo jogo1(criancas1);
	Jogo jogo2(criancas1);
	cout<<endl<<"testar igualdade"<<endl;
	cout<<(jogo1==jogo2)<<endl;

	list<Crianca> criancas2;
	criancas2.push_back( Crianca("Rui",6) );
	criancas2.push_back( Crianca("Ana",4) );
	criancas2.push_back( Crianca("Rita",3) );
	criancas2.push_back( Crianca("Maria",5) );
	criancas2.push_back( Crianca("Marta",7) );
	criancas2.push_back( Crianca("Vasco",5) );
	criancas2.push_back( Crianca("Ines",5) );

	jogo2.setCriancasJogo(criancas2);
	cout<<(jogo1==jogo2)<<endl;

}

void test_h_baralhaCriancas(){

	list<Crianca> criancas;
	criancas.push_back( Crianca("Rui",6) );
	criancas.push_back( Crianca("Ana",4) );
	criancas.push_back( Crianca("Rita",3) );
	criancas.push_back( Crianca("Joao",5) );
	criancas.push_back( Crianca("Marta",7) );
	criancas.push_back( Crianca("Vasco",5) );
	criancas.push_back( Crianca("Ines",5) );

	Jogo jogo1;
	jogo1.setCriancasJogo(criancas);
	cout<<endl<<"testar baralhar"<<endl;
	cout<<jogo1.escreve()<<endl;

	list<Crianca> criancas2 = jogo1.baralha(criancas);
	Jogo jogo2(criancas2);
	cout<<jogo2.escreve()<<endl;

}


int main(){
    srand(time(NULL));
    test_0_Crianca();
    test_a_insereCrianca();
    test_b_imprimeJogo();
    test_c_nPalavras();
    test_d_perdeJogo();
    test_e_inverteJogo();
    test_f_divideJogo();
    test_g_igualdadeJogo();
    test_h_baralhaCriancas();
    system("PAUSE");
    return 0;
}



