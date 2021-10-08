#include <iostream>

#include "cdate.h"

using namespace std;

int main()
{
    CDate d1(25, 12, 2005), d2(25, 12), d3(25), d4;
    d1.print(); // imprime: 25/12/2005
    d2.print(); // imprime: 25/12/1900
    d3.print(); // imprime: 25/1/1900
    d4.print(); // imprime: 1/1/1900
    return 0;
}
