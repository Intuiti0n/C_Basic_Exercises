#include <cstdlib>
#include <iostream>
#include "CentroComercial.h"

using namespace std;

int main()
{
	CCentroComercial loja;
	loja.ler_lojas ("lojas.txt");
	//loja.show_lista();
	cout << endl << "###  LOJAS DE ROUPA ###" << endl;
	loja.imprimir_lojas(cout, "Roupa");

	cout << endl << "###  TODAS AS LOJAS ###" << endl;
	loja.imprimir_lojas(cout);

	cout << endl << "###  LOJAS ORDENADAS POR RENDA ###" << endl;
	loja.ordenarLojas();
	loja.imprimir_lojas(cout);

	cout << "Indique a loja que pretende alterar a renda:";
	int a,b;
	cin >> a;
	cout << endl;
	cout << "Indique o novo valor da renda:";
	cin >> b;
	cout << endl;
	loja.alterarRenda(a,b);
	loja.ordenarLojas();
	//loja.imprimir_lojas(cout);
	loja.gravarLojas("lojas.txt", loja);
	return 0;
}
