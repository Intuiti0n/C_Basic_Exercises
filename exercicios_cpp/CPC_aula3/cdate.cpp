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


/*
meses com 31 dias:
1 31
2 28 ou 29
3 31
4 30
5 31
6 30
7 31
8 31
9 30
10 31
11 30
12 31
*/
int CDate::checkDay(void){
    if(day <= 0 || day > 31 || month<=0 ||month > 12 || year < 1900)//verificação default
        return 0;
    else if(month == 2 && day > 29)//verifica default fevereiro
        return 0;
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)//meses que tem 30 dias
        return 0;
    else if(year % 4 !=0 && month == 2 && day == 29)//ano sem ser bissexto
        return 0;
    else if(year % 100 ==0 && month == 2 && day == 29)//ano sem ser bissexto
        return 0;
    else return 1;

}

int CDate::checkDay(int a,int b,int c){
    if(a <= 0 || a > 31 || b<=0 ||b > 12 || c < 1900)//verificação default
        return 0;
    else if(b == 2 && a > 29)//verifica default fevereiro
        return 0;
    else if((b == 4 || b == 6 || b == 9 || b == 11) && a > 30)//meses que tem 30 dias
        return 0;
    else if(c % 4 !=0 && b == 2 && a == 29)//ano sem ser bissexto
        return 0;
    else if(c % 100 ==0 && b == 2 && a == 29)//ano sem ser bissexto
        return 0;
    else return 1;

}

void CDate::setDate(int a, int b, int c){
    if (checkDay(a,b,c)){

        this->day = a;
        this->month = b;
        this->year = c;
    }
    else {
        day = 1;
        month = 1;
        year = 1900;
    }

}

bool CDate::operator== (const CDate& rhs){
    if(this->day == rhs.day && this->month == rhs.month && this->year == rhs.year)
        return true;
    else return false;
}

ostream& operator<< (ostream& os, CDate &d){
    os << d.day << "/"<<d.month <<"/"<<d.year<<endl;
    return os;
}

CDate& CDate::operator++(){
    day++;
    if(checkDay()==0){
        day = 1;
        month++;
    }
    if(checkDay()==0){
        year++;
        month=1;
    }
    return *this;
}

CDate& CDate::operator++(int){
    CDate temp = *this;
    ++*this;
    return temp;
}

int difDate(CDate d2){
    //calcular valor do dia desde que se passaram 1900
    //fazer diferença em dias

}
