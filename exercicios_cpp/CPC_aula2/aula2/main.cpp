#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;

    vector <int > vec;

    cout << sizeof (vec)<<endl;

    vec.push_back(1);
    vec.push_back(2);

    cout << sizeof (vec)<<endl;



    return 0;
}
