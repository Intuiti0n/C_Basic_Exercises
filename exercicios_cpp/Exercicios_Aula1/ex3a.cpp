#include <iostream>
#include <cmath>
using namespace std;
	
int primo(int n);	//Declaracao da funcao
	
int main()
{
  
  int n;
  cout<<"Insira um numero: ";
  cin>>n;
  if (primo(n)==1) cout<<n<<" e' primo."<<endl;
  else if (primo(n)==0) cout<<n<<" nao e' primo."<<endl;
  else cout<<"Numero nao inteiro positivo"<<endl;
	
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
