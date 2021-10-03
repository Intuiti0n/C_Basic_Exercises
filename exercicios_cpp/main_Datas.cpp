#include <iostream>
#include "CDate.h"
using namespace std;

int main()
{
    CDate d1(25, 12, 2005), d2(25, 2), d3(25), d4;
    d1.print();
    d2.print();
    d3.print();
    d4.print();
    d1.setDate(31,12,1904);
    d1.print();
    cout<<d1.convData()<<endl;
    d1.setDate(1,1,2004);
    d2.setDate(1,1,2004);
    if (d1==d2) cout<<"Datas iguais:"<<d1<<endl;
    else cout<<"Datas diferentes:"<<d2.difDate(d1)<<" dias de diferença"<<endl;
    d1.setDate(30,1,2003);
    ++d1;
    d1.print();
    d1++;
    cout<<d1<<endl;
    cout<<d1+3<<endl;
    system("Pause");
    return 0;
}
