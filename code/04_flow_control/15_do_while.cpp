#include<iostream>
using namespace std;

int main()
{
    //do...while语句
    //do...while和while循环区别在于do...while会先执行一次循环语句
    //在屏幕上输出0到9，这10个数字
    int num = 0;
    do{
        cout << num++ << endl;
    }while(num < 10);

    //使用do...while循环，输出所有3位数中的水仙花数
    int x = 100, a, b, c;
    do{
        a = x / 100;
        b = x % 100 / 10;
        c = x % 10;
        if((a*a*a + b*b*b + c*c*c) == x){
            cout << "x = " << x << endl;
        }
        ++x;
    }while(x < 1000);

    return 0;
}