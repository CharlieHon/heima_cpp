#include <iostream>
#include <string>
using namespace std;

// struct和class区别
class C1{
    int A;  // 默认为私有权限(private)
};

struct C2{
    int A;  // 默认为公有权限(public)
};

int main()
{
    C1 a;
    // a.A = 6;    // 错误：私有权限，类外不可访问

    C2 b;
    b.A = 5;    // struct默认公有权限，类外可以访问

    return 0;
}