#include <iostream>

#include "cdate.h"

using namespace std;

int main()
{
    CDate d1(31, 12, 2005), d2(25, 12), d3(25), d4;
    CDate d5(1,1,2006);
    d1.print(); // imprime: 25/12/2005
    d2.print(); // imprime: 25/12/1900
    d3.print(); // imprime: 25/1/1900
    d4.print(); // imprime: 1/1/1900
    d1++;
    d1.print();
    if(d1 == d5)
        cout<<"Sao iguais"<<endl;
    cout<<endl<<endl;
    d1.print();
    d1.setDate(10,10,2021);
    d1.print();
    d1.setDate(50,10,2000);
    d1.print();

    cout <<d1<<endl;
    return 0;
}
