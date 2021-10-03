#include<iostream>
#include<fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int primo(int n);	//Declaracao da funcao

int main( int argc, char* argv[] ) 
{
 cout << "Programa: " << argv[ 0 ]<<endl;

 ifstream fich;
 fich.open(argv[1]);
 
 
 int num;
 if (fich.is_open()) 
 {
  
 	while (fich>>num)
	 {
    	if (primo(num)==1) cout<<num<<" e' primo"<<endl;
    	else if (primo(num)==0) cout<<num<<" nao e' primo"<<endl;
    	else cout<<num<<" não e' um inteiro positivo"<<endl;

 	}
}
else cout<<"O ficheiro não existe"<<endl;
fich.close();
return 0;
}

//Definicao da funcao

int primo(int n)
{
  int eprimo=1;
  int x=2;
  if (n>0)
	{  
		while((eprimo==1)&&(x<=sqrt(n)))
		{
			if (n%x == 0) eprimo=0;
			x++;
		}
  		return eprimo;
	}
else 
{
	eprimo=-1;
	return eprimo;
}
}
