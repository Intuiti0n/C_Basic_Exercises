#include "cdate.h"
#include <iostream>
using namespace std;

CDate::CDate(int a, int b, int c){
    day = a;
    month = b;
    year = c;
}

CDate::~CDate(){
    return;
}

void CDate::print(void) const{
    cout << day << "/"<< month <<"/" <<year <<endl;
    return;
}

int CDate::checkDay(void){

}
