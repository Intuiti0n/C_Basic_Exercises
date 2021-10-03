
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

main ()
{
  int num;
  string frase;

	cout<<"Numero de repeticoes: ";
	cin>>num;
	cin.ignore();
	cout << "Insira a frase: ";
  	getline (cin,frase);
  	
  	for (int i=1;i<=num;i++) cout << frase << endl;

  return 0;
}

