#include <iostream>
#include <cmath>
using namespace std;
	
void imprime_piramide(int n);	//Declaracao da funcao
	
int main()
{
  
  int n;
  cout<<"Insira um numero: ";
  cin>>n;
  imprime_piramide(n);
	
  return 0;
}	

//Definicao da funcao

void imprime_piramide(int n)
{
	if (n>0)
	{
 		for (int i=1;i<=n;i++)
 		{	
		 	for(int j=i; j>=1;j--)
 			cout<<j<<"  ";
 			cout<<endl;
		}
	}
	else cout<<n<<" não é um inteiro positivo"<<endl; 

}
