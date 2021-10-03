#include<iostream>
#include "CDate.h"

using namespace std;

int main()
{
	CDate d1(25, 12, 2005), d2(25,12), d3(25), d4;
	CDate d5(16,10,2012), d6(16,10,2012);
	CDate d7(25, 12, 2006);
	CDate d9;
	d1.print(); // imprime: 25/12/2005
	d2.print(); // imprime: 25/12/1900
	d3.print(); // imprime: 25/1/1900
	d4.print(); // imprime: 1/1/1900
	
	cout << endl;	
	cout << "Comparar datas:" <<endl;	
    cout << "Data 1: ";d5.print(); 
	cout << "Data 2: ";d6.print(); 
	cout << "Data 1 = Data 2: "; 
	if (d5==d6) cout << "Sim" << endl; else cout << "Nao" << endl;
	
	cout << endl;	
	cout << "Diferenca datas:" <<endl;	
	cout << "Data 3: ";d1.print(); 
	cout << "Data 4: ";d7.print(); 
	cout << "Data 4 - Data 3 = "; d7.difDate(d1); cout << " dias"  << endl;	
	cout << endl;
	
	cout << endl;	
	cout << "Apresentar datas com cout:" <<endl;		
    cout << d1;
    cout << d2;
    cout << d3;
    cout << d4;
    
    cout << endl;
    cout << "Somar datas:" <<endl;	
	cout << "Somar 365 dias a Data 4: "; d1+365;; 
    cout << "Soma 1 dia a Data 4: "; ++d7;
     
	return 0;
}



