#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
	
void imprime_piramide_fich(int n);	//Declaracao da funcao
	
int main()
{
  
  int n;
  cout<<"Insira um numero: ";
  cin>>n;
  imprime_piramide_fich(n);
	
  return 0;
}	

//Definicao da funcao

void imprime_piramide_fich(int n)
{
	ofstream fich;
	fich.open("piramide.txt",ios::out);
	
	if (n>0)
	{
		if (fich.is_open())
 		{
		 	for (int i=1;i<=n;i++)
 			{	
		 		for(int j=i; j>=1;j--)
 				fich<<j<<"  ";
 				fich<<endl;
			}
		}
		else cout<<"O ficheiro não está aberto"<<endl;	
	}
	else fich<<n<<" não é um inteiro positivo"<<endl; 

}
