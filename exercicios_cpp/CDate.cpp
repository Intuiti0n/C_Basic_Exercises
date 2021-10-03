#include "CDate.h"
#include <ctime>
#include <iostream>

using std::ostream;

CDate::CDate(int d, int m, int a)
{  
	//year = a; month = m; day = d;
	setDate(d, m, a);
}

CDate::~CDate()  
{
}

void CDate::setDate(int d, int m, int a)
{
	year = a;
	if (m>=1 && m<=12) month = m; else month = 1; 
    if (d>=1 && d<=checkDay()) day = d; else day = 1;
} 

void CDate::print() const  
{
	cout << day << "/" << month << "/" << year << endl;
}

int CDate::difDate(CDate d2)
{
	int jDate1;
	int jDate2;
	int newDate;
	// Converte a data em valor númerico
	jDate1 = (1461 * (year + 4800 + (month - 14)/12))/4 +(367 * (month - 2 - 12 * ((month - 14)/12)))/12 - (3 * ((year + 4900 + (month - 14)/12)/100))/4 + day - 32075;
	jDate2 = (1461 * (d2.year + 4800 + (d2.month - 14)/12))/4 +(367 * (d2.month - 2 - 12 * ((d2.month - 14)/12)))/12 - (3 * ((d2.year + 4900 + (d2.month - 14)/12)/100))/4 + d2.day - 32075;
	// Faz a diferença entre dois números
	newDate = jDate1 - jDate2;
	cout << newDate;
}

ostream &operator<< (ostream &os, CDate &d)
{
	 os << "" ; d.print() ;
};

CDate& CDate::operator+ (const int nd)
{
	int y=year, m=month, d=day;
    std::tm t = {};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    // modify
    t.tm_mday += nd;
    std::mktime(&t);
    // show result
    std::cout << std::asctime(&t); 
}

CDate& CDate::operator++()
{
	int y=year, m=month, d=day;
    std::tm t = {};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    // modify
    t.tm_mday += 1;
    std::mktime(&t);
    // show result
    std::cout << std::asctime(&t); 
}

int CDate::checkDay() 
{
	switch(month) {
		case 2: if (year%400 == 0 || year%4 == 0 && year%100!=0)
				return 29; else return 28;
		case 4: case 6: case 9: case 11: return 30;
		default: return 31;
	}
}


