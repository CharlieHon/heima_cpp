#include<iostream>
using namespace std;

int main()
{
    //三目运算符
    //创建3个变量a b c，将a和b作比较，将变量大的值赋值给变量c
    int a = 10, b = 20, c;
    c = a > b ? a : b;
    cout << "c = " << c << endl;    //c = 20

    //在C++中三目运算符返回的是变量，可以继续赋值
    ((a > b) ? a : b) = 100;
    cout << "a = " << a << endl; // 10
    cout << "b = " << b << endl; // 100

    return 0;
}