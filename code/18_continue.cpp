#include<iostream>
using namespace std;

int main()
{
    //continue语句
    for(int i=1; i<=100; ++i){
        if(i % 2)
            continue;   //可以筛选条件，执行到此就不再向下执行，而是执行下一次循环
        cout << i << endl;
    }

    return 0;
}