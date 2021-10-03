#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;	

int main( int argc, char* argv[] )
  {
  	cout << "Programa: " << argv[ 0 ]<<endl;
       
  	float cat1=atof(argv[1]);
  
  	float cat2=atof(argv[2]);

	if((cat1>0) && (cat2>0))
	{
		float hip=sqrt(pow(cat1,2)+pow(cat2,2));
		cout<<"A hipotenusa e: "<<hip<<endl; 
		cout <<endl;
	}
	else cout<<"Foi inserido um valor menor ou igual a zero"<<endl;
	
  	return 0;
}	
