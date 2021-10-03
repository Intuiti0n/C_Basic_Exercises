#include <iostream>
#include <cstdlib>
using namespace std;

int main( int argc, char* argv[] )
  {
  cout << "Programa: " << argv[ 0 ]<<endl;
       
  int j=atoi(argv[1]);
  
  for (int n = 1; n <= j; n++)
    cout << "Hello World!"<< '\n';
  return 0;
  }

