#include <iostream>
#include <cmath>
using namespace std;
	
void imprime_todos(int n);	//Declaracao da funcao
	
int main()
{
  
  int n;
  cout<<"Insira um numero: ";
  cin>>n;
  imprime_todos(n);
	
  return 0;
}	

//Definicao da funcao

void imprime_todos(int n)
{
	if (n>0)
	{
 		for (int i=1;i<=n;i++)
 			if (((i%2)&&(i%3))!=0)cout<<i<<"  ";

	}
	else cout<<n<<" não é um inteiro positivo"<<endl; 

}
