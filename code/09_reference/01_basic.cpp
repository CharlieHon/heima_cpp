#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    // int &b; // 错误
    int &b = a; // 引用必须要初始化

    cout << "a = " << a << endl;    // a = 10
    cout << "b = " << b << endl;    // b = 10

    b = 100;

    cout << "a = " << a << endl;    // a = 100
    cout << "b = " << b << endl;    // b = 100

    // 引用在初始化后，不可以改变
    int c = 20;
    b = c;  // 赋值操作，而不是更改引用

    cout << "a = " << a << endl;    // a = 20
    cout << "b = " << b << endl;    // b = 20
    cout << "c = " << c << endl;    // c = 20

    return 0;
}