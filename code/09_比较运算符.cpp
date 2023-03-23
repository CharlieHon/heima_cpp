#include<iostream>
using namespace std;

int main()
{
    //比较运算符
    // ==
    int a = 10;
    int b = 20;
    cout << (a == b) << endl;   // 0
    cout << (a != b) << endl;   // 1

    // < >
    cout << (a < b) << endl;    // 1
    cout << (a > b) << endl;    // 0

    // <= >=
    cout << (a <= b) << endl;   // 1
    cout << (a >= b) << endl;   // 0
    
    return 0;
}