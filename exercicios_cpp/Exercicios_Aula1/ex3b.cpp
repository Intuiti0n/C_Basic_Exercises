#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
	
int primo(int n);	//Declaracao da funcao
	
int main( int argc, char* argv[] )
{
  
  int n;
  n=atoi(argv[1]);
  	cout<<endl;
  	for (int i=1; i<=n;i++)
  		if (primo(i)==1) cout<<i<<endl;
  
	
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
