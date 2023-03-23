#include<iostream>
using namespace std;

int main()
{
    //加减乘除
    int a1 = 10;
    int b1 = 3;

    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl;    //两个整数相除，结果仍是整数，将小数部分去除

    int a2 = 10;
    int b2 = 20;
    int c2 = 0;

    cout << a2 / b2 << endl;    //0
    // cout << a2 / c2 << endl;    //错误！两个数相除，除数不可以为0

    //两个小数相除
    double d1 = 0.5;
    double d2 = 0.22;
    cout << d1 / d2 << endl;    //2.27273

    //取模就是求余数
    int a3 = 10;
    int b3 = 3;
    int c3 = 20;
    int d3 = 0;

    cout << a3 % b3 << endl;    //1
    cout << a3 % c3 << endl;    //10
    // cout << a3 % d3 << endl;    //保存，两个数相除，除数不能为0，也不能取模

    //两个小数是不可以做取模运算的


    //1、前置递增
    int a = 10;
    ++a;
    cout << "a = " << a << endl;    //11

    //2、后置递增
    int b = 10;
    b++;
    cout << "b = " << b << endl;    //11

    //前置递增：先让变量+1，然后进行表达式运算
    int x1 = 10;
    int y1 = ++x1 * 10;
    cout << "x1 = " << x1 << endl;  //11
    cout << "y1 = " << y1 << endl;  //110
    //后置递增：先进行表达式运算，后让变量+1
    int x2 = 10;
    int y2 = x2++ * 10;
    cout << "x2 = " << x2 << endl;  //11
    cout << "y2 = " << y2 << endl;  //100

    //3、前置递减
    //4、后置递减，同理

    return 0;
}