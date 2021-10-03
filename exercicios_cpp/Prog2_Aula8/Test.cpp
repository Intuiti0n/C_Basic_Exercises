#include "Crianca.h"
#include "Jogo.h"

void test_0_Crianca() {
/*
	Crianca a;
	Crianca b("Joao", 10);
	Crianca c("Pedro", 12);
	Crianca d = c;
	*/
}

void test_a_insereCrianca() {
/*
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
	c = cc.back();
*/
}

void test_b_imprimeJogo(){
/*
	Jogo jogo1;
	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Vasco",5);
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	cout << jogo1.escreve();
*/
}

void test_c_nPalavras(){
/*
	Jogo jogo1;
	string frase = "pim pam pum cada bola mata um";
*/
}

void test_d_perdeJogo(){
/*
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
*/
}

void test_e_inverteJogo(){
/*
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

	list<Crianca> invertida = jogo1.inverte();
*/
}

void test_f_divideJogo(){
/*
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

	list<Crianca> dividida = jogo1.divide(5);
	Jogo jogo2(dividida);
*/
}

void test_g_igualdadeJogo(){
/*
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

	list<Crianca> criancas2;
	criancas2.push_back( Crianca("Rui",6) );
	criancas2.push_back( Crianca("Ana",4) );
	criancas2.push_back( Crianca("Rita",3) );
	criancas2.push_back( Crianca("Maria",5) );
	criancas2.push_back( Crianca("Marta",7) );
	criancas2.push_back( Crianca("Vasco",5) );
	criancas2.push_back( Crianca("Ines",5) );

	jogo2.setCriancasJogo(criancas2);
*/
}

void test_h_baralhaCriancas(){
/*
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

	list<Crianca> criancas2 = jogo1.baralha(criancas);
	Jogo jogo2(criancas2);
*/
}


int main(){
    /*
    test_0_Crianca();
    test_a_insereCrianca();
    ...
    test_g_igualdadeJogo();
    test_h_baralhaCriancas();
    */
    system("PAUSE");
    return 0;
}



