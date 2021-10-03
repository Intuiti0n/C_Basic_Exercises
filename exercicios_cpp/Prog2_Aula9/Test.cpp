
#include "Jogo.h"
#include "Dicionario.h"
#include <fstream>


void test_1a_InicioJogo(){
	/*
	vector<int> pontos;
	vector<bool> estados;
	pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
	pontos.push_back(4); pontos.push_back(5); pontos.push_back(6); pontos.push_back(7);
	estados.push_back(true); estados.push_back(false); estados.push_back(false);
	estados.push_back(false); estados.push_back(false); estados.push_back(true); estados.push_back(false);
    Jogo jogo1(2, pontos,estados);
*/
}

void test_1b_EscreveJogo(){
	/*
	vector<int> pontos;
	vector<bool> estados;
	pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
	pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
	pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
	pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
	pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
	estados.push_back(true); estados.push_back(false); estados.push_back(false);
	estados.push_back(false); estados.push_back(false); estados.push_back(true);
	estados.push_back(false); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Jogo jogo1(3, pontos,estados);
    string jogoStr="1-true-0\n2-false-0\n3-false-0\n4-false-0\n5-false-0\n6-true-0\n7-false-0\n8-true-0\n9-true-0\n10-true-0\n11-true-0\n12-true-0\n13-true-0\n14-true-0\n15-true-0\n";

    */
}

void test_1c_FazJogada(){
	/*
	vector<int> pontos;
	vector<bool> estados;
	pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
	pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
	pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
	pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
	pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
	estados.push_back(true); estados.push_back(false); estados.push_back(false);
	estados.push_back(false); estados.push_back(false); estados.push_back(true);
	estados.push_back(false); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Jogo jogo1(3, pontos,estados);
    */
}

void test_1d_MaisVisitado(){
	/*
	vector<int> pontos;
	vector<bool> estados;
	pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
	pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
	pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
	pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
	pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
	estados.push_back(true); estados.push_back(false); estados.push_back(false);
	estados.push_back(false); estados.push_back(false); estados.push_back(true);
	estados.push_back(false); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
	estados.push_back(true); estados.push_back(true); estados.push_back(true);
	Jogo jogo1(3, pontos,estados);
	jogo1.jogada(); jogo1.jogada(); jogo1.jogada();
	jogo1.jogada(); jogo1.jogada(); jogo1.jogada();jogo1.jogada();
	*/
}

void test_2a_CriaDicionario(){
	/*
	ifstream fich;
    fich.open("C:\\directorio_ficheiro\\dic.txt");
	Dicionario d1;
	d1.lerDicionario(fich);
	fich.close();
	d1.imprime();
	BST<PalavraSignificado> pal = d1.getPalavras();
	BSTItrIn<PalavraSignificado> it(pal);
	it.advance(); it.advance();
	*/
}

void test_2b_ImprimeDicionario(){
	/*
	ifstream fich;
	fich.open("C:\\directorio_ficheiro\\dic.txt");
	Dicionario d1;
	d1.lerDicionario(fich);
	fich.close();
	d1.imprime();
	*/
}

void test_2c_ConsultaDicionario(){
	/*
	ifstream fich;
	fich.open("C:\\directorio_ficheiro\\dic.txt");
	Dicionario d1;
	d1.lerDicionario(fich);
	fich.close();
  */
}

void test_2d_CorrigeDicionario(){
	/*
	ifstream fich;
	fich.open("C:\\directorio_ficheiro\\dic.txt");
	Dicionario d1;
	d1.lerDicionario(fich);
	fich.close();
	d1.imprime();
	BST<PalavraSignificado> pal = d1.getPalavras();
	BSTItrIn<PalavraSignificado> it(pal);
	it.advance(); it.advance();
	*/
}


int main(){
    /*
    test_1a_InicioJogo();
    ...
    test_2d_CorrigeDicionario();
    */
    system("PAUSE");
    return 0;
}



