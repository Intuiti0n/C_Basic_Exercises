/*#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"*/
#include "StackExt.h"
#include "Balcao.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include "performance.h"


using namespace std;


void test_1_StackExt_FindMin() {

	StackExt<int> s1;
	// Teste ao empty()
	cout<<"Empty="<<s1.empty()<<endl;
//	ASSERT_EQUAL(true, s1.empty());
	// Teste ao push() e top()
 	s1.push(6);
	s1.push(4);
	s1.push(7);
	s1.push(2);
	s1.push(5);
	cout<<5<<"="<< s1.top()<<endl;
//	ASSERT_EQUAL(5, s1.top());
	// Teste ao pop() e top()
	s1.pop();
	s1.pop();
	cout<<7<<"="<< s1.top()<<endl;
//	ASSERT_EQUAL(7, s1.top());
	// Testar findMin()
	s1.push(3);
	s1.push(2);
	cout<<2<<"="<< s1.findMin()<<endl;;
//	ASSERT_EQUAL(2, s1.findMin());

	// Agora testar findMin() para saber se executa em tempo constante
	// preparar Stack removendo todos os elementos
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	cout<<"Empty="<<s1.empty()<<endl;
//	ASSERT_EQUAL(true, s1.empty());

	// preparar dados para teste TEMPO EXECUCAO
	int size = 9;
	unsigned int elapsedTime[size];
	long int x_el[] = {500,600,700,800,900,1000,1100,1200,1300};
	int random_int;
	ticks tstart;
	ticks tend;

	for (int i = 0; i < size; i++) {
		// encher stack com numero de elementos indicados pelo x_el
		for (long int z = 1; z <= x_el[i]; z++) {
			random_int = rand() % 1000 + 1;
			s1.push(random_int);
		}
		// agora contar tempo invocando o método
		tstart = getticks(); // inicio contagem ticks
		s1.findMin(); // este é constante
		tend = getticks(); // fim da contagem ticks
		// colocar valor no array de elapsedTime
		elapsedTime[i] = getElapsed(tend,tstart);
		// retirar da stack os numeros lá colocados
		for (long int z = 1; z <= x_el[i]; z++) {
			s1.pop();
		}
	}
	// Verifica se executa em TEMPO CONSTANTE
	// NOTA: o parâmetro com valor 10 significa que são considerados constantes valores no intervalo [-10, 10]
	//       nos testes que fiz este intervalo pareceu suficiente
	cout<<"Constante?="<< isConstant(elapsedTime, size, 10)<<endl;
//	ASSERT_EQUAL(true, isConstant(elapsedTime, size, 10));

}

void test_2a_ConstructorCliente(){

    srand(time(NULL));
    Cliente c;
    cout<<endl<<"Teste construtor Cliente"<<endl;
    cout<<((c.getNumPresentes()>0 && c.getNumPresentes()<=5))<<endl;
//    ASSERT((c.getNumPresentes()>0 && c.getNumPresentes()<=5));

}

void test_2b_ConstructorBalcao(){

    srand(time(NULL));
    Balcao b;
    cout<<endl<<"Teste construtor Balcao"<<endl;
	cout<<0<<"=?"<< b.getClientesAtendidos()<<endl;
//    ASSERT_EQUAL(0, b.getClientesAtendidos());
	cout<<2<<"=?"<< b.getTempoEmbrulho()<<endl;
//    ASSERT_EQUAL(2, b.getTempoEmbrulho());
	cout<<0<<"=?"<< b.getTempoActual()<<endl;
//    ASSERT_EQUAL(0, b.getTempoActual());
    cout<<"ProxChegada valida? "<<((b.getProxChegada()>0 && b.getProxChegada() <= 20))<<endl;
//    ASSERT((b.getProxChegada()>0 && b.getProxChegada() <= 20));
	cout<<0<<"=?"<< b.getProxSaida()<<endl;
//    ASSERT_EQUAL(0, b.getProxSaida());
//	ASSERT_THROWS(b.getProxCliente(), FilaVazia);
	try {
		b.getProxCliente();
	}
	catch (FilaVazia &e) {
		cout << "Apanhou excepcao. FilaVazia: " << e.getMsg() << endl;
		//ASSERT_EQUAL("Fila Vazia", e.getMsg());
	}

}

void test_2c_ChegadaBalcao(){

	Balcao b;
	cout<<endl<<"Teste de chegada de cliente"<<endl;
//    ASSERTM("Este teste não falha. Verifique se na consola apareceu (x varia entre 1 e 5): tempo= 0\nchegou novo cliente com x presentes", true);
    b.chegada();
    //
    // Agora que se invocou o método chegada, verifica-se se fez correctamente alguns dos requisitos
    //
	cout<<0<<"=?"<< b.getTempoActual()<<endl;
//    ASSERT_EQUAL(0, b.getTempoActual());
    cout<<"NumPresentes valido? "<<((b.getProxCliente().getNumPresentes()>0 && b.getProxCliente().getNumPresentes()<=5))<<endl;
//    ASSERT((b.getProxCliente().getNumPresentes()>0 && b.getProxCliente().getNumPresentes()<=5));
    cout<<"ProxChegada valida? "<<((b.getProxChegada()>0 && b.getProxChegada() <= 20))<<endl;
//    ASSERT((b.getProxChegada()>0 && b.getProxChegada() <= 20));
    cout<<"ProxSaida valida? "<<((b.getProxSaida()>=2 && b.getProxSaida() <= 10))<<endl;
//    ASSERT((b.getProxSaida()>=2 && b.getProxSaida() <= 10)); // entre [0+1*2, 0+5*2]

}

void test_2d_SaidaBalcao(){

    Balcao b;
    cout<<endl<<"Saida de cliente"<<endl;
    // Simula a chegada de um cliente
    b.chegada();
    // Guarda dados do cliente para teste posterior
    int numP = b.getProxCliente().getNumPresentes();
    //
//    ASSERTM("Este teste não falha. Verifique se na consola apareceu (x varia entre 1 e 5): tempo= 0\ncliente atendido: x presentes", true);
    b.saida();
    //
    // Agora que se invocou o método saida, verifica-se se fez correctamente alguns dos requisitos
    //
	cout<<0<<"=?"<< b.getTempoActual()<<endl;
//    ASSERT_EQUAL(0, b.getTempoActual());
    cout<<"NumPresentes valido? "<<((numP>0 && numP<=5))<<endl;
    
    //Verificar se testa quando a fila fica vazia
    b.saida();

//    ASSERT((numP>0 && numP<=5));
/*	try {
		b.getProxCliente();
	}
	catch (FilaVazia &e) {
		cout << "Apanhou excepção. FilaVazia: " << e.getMsg() << endl;
		ASSERT_EQUAL("Fila Vazia", e.getMsg());
	}
*/
}

void test_2e_ProximoEvento(){

    cout<<endl<<"Testar Proximo Evento"<<endl;
//	ASSERTM("Este teste não falha. Verifique na consola os valores", true);
	Balcao b;
    b.proximoEvento();
    cout << "01: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoActual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "02: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoActual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "03: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoActual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "04: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoActual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;

}

void test_2f_Operador() {

    cout<<endl<<"Testar Operador"<<endl;
//	ASSERTM("Este teste não falha. Verifique na consola os valores", true);
	Balcao b;
    b.proximoEvento();
    b.proximoEvento();
    b.proximoEvento();
    b.proximoEvento();
    cout << b << endl;
}



void runSuite(){
     test_1_StackExt_FindMin();
     test_2a_ConstructorCliente();
     test_2b_ConstructorBalcao();
     test_2c_ChegadaBalcao();
     test_2d_SaidaBalcao();
     test_2e_ProximoEvento();
     test_2f_Operador();
/*	cute::suite s;
	s.push_back(CUTE(test_1_StackExt_FindMin));
	s.push_back(CUTE(test_2a_ConstructorCliente));
	s.push_back(CUTE(test_2b_ConstructorBalcao));
	s.push_back(CUTE(test_2c_ChegadaBalcao));
	s.push_back(CUTE(test_2d_SaidaBalcao));
	s.push_back(CUTE(test_2e_ProximoEvento));
	s.push_back(CUTE(test_2f_Operador));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2010/2011 - Aula Pratica 7");
*/
}

int main(){
    runSuite();
    system("Pause");
    return 0;
}



