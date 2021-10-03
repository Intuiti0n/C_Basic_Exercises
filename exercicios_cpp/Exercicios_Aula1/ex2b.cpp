#include <iostream>
#include <cmath>
using namespace std;
	
int main()
{
  float cat1, cat2, hip;


	cout << "Insira o primeiro cateto: ";
	cin>>cat1;
	cout<<endl<<"Insira o segundo cateto: ";
	cin>>cat2;
	while(cat1>0 && cat2>0)
	{
		hip=sqrt(pow(cat1,2)+pow(cat2,2));
		cout<<"A hipotenusa e: "<<hip<<endl; 
		cout <<endl;
		cout << "Insira o primeiro cateto: ";
		cin>>cat1;
		cout<<endl<<"Insira o segundo cateto: ";
		cin>>cat2;
	}
  return 0;
}	
