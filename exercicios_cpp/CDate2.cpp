#include "CDate.h"
#include <iostream>
using namespace std;

CDate::CDate(int d, int m, int a)
{
    setDate(d,m,a);
 
}
CDate::~CDate()
{}

void CDate::print() const
{
     cout<<day<<"/"<<month<<"/"<<year<<endl;
 }

int CDate::checkDay()
{
    int dm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2)
       if ((year%4==0 && year%100!=0)||(year%400==0))
          dm[1]=29;
    return dm[month-1];
}

void CDate::setDate(int d, int m, int a)
{
     if (m>=1 && m<=12) month=m;
     else { cout<<m<<" - Invalid month"<<endl;month=1;}
     if (a>=1900) year=a;
     else { cout<<a<<" - Invalid year"<<endl;year=1900;}
     if (d>=1&&d<=checkDay())
        day=d;
     else { cout<<d<<" - Invalid day"<<endl;day=1;} 
 }
 
 int CDate::difDate(CDate d2)
 {
     int data1=convData();
     int data2=d2.convData();
     return data1-data2;
 }
 
 int CDate::convData()
 {
     int dify=year-1900;
     int dif=0;
     for (int i=0;i<dify;i++)
         if (yearBis(1900+i)) dif+=366;
         else dif+=365;
     int dm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     for (int i=1;i<month;i++)
     {if (i==2)
         if (yearBis(year))
            dm[1]=29;
         else
            dm[1]=28;
         dif+=dm[i-1];}
     return dif+day;
 }
 
 bool CDate::yearBis(int a)
 {
     return((a%4==0 && a%100!=0)||(a%400==0));
 }
 
 bool CDate::operator== (const CDate& rhs)
 {
      return (year==rhs.year)&&(month==rhs.month)&&(day==rhs.day);
  }
 
 ostream& operator<< (ostream& os, CDate &d)
 {
          os<<d.day<<"/"<<d.month<<"/"<<d.year;
          return os;
 }
 
 CDate& CDate::operator++()
 {
        if (day<checkDay())
           day++;
        else
        {
            day=1;
            if (month<12)
               month++;
            else
                {month=1;year++;}
        }
        return *this;       
 }
 CDate& CDate::operator++(int a)
 {
        if (day<checkDay())
           day++;
        else
        {
            day=1;
            if (month<12)
               month++;
            else
                {month=1;year++;}
        }       
        return *this;       
 }
CDate& CDate::operator+(const int nd)
{
       int i;
       for (i=1;i<=nd;i++)
           ++(*this);       
       return *this;       
}
