#include <iostream>

//using namespace std;

/*
Given a string str, reverse it omitting all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".


*/
std::string reverse_letter(const std::string &str)
{
    //reverse string
    std::string aux;
    int len = str.size();

    for(int i=str.size()-1;i>= 0;i--){
        if(str[i]>='0' && str[i]<='9')
            continue;
        else aux.append(1,str[i]);
    }

    //    aux.append(1,'\0');

    return aux; //coding and coding..
}

int main()
{
    //cout << "Hello World!" << endl;

    cout << reverse_letter("Hello123")<<endl;
    return 0;
}
