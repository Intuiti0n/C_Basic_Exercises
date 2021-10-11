#include <iostream>
using namespace std;

class test
{
private:
    /* data */
public:
    test(/* args */);
    ~test();
};

test::test(/* args */)
{
}

test::~test()
{
}

int solve(int n, int e, int o, int t) {
    unsigned int result = 0;
    float curr_value = n;
    //curr_value *= ((float)(100+e)/100);
        while(curr_value < t){
            if (result % 2 == 0){
                curr_value *= ((float)(100+e)/100);
                //curr_value += (float)curr_value * (float)(e/100);
            }
            else if (result % 2 != 0){
                curr_value *= ((float)(100+o)/100);
                //curr_value += (float)curr_value * (float)(o/100);
            }

            if(result == 170){
                cout <<"here"<<endl;
            }
            result++;
            //cout << curr_value<<endl;
        }

    return result;
}


int main(){

    cout << solve(57,6,10,30390291)<<endl;
    class test v;
    v.
    
    return 0;
}