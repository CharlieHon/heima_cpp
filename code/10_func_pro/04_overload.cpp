#include <iostream>

using namespace std;

// 函数重载的注意事项
// 1.引用作为重载的条件
void func(int &a){
    cout << "func(int &a)" << endl;
}

void func(const int &a){
    cout << "func(const int &a)" << endl;
}

// 2.函数重载与默认参数
void func2(int a, int b = 10){
    cout << "func2(int a, int b = 10)" << endl;
}

void func2(int a){
    cout << "func2(int a)" << endl;
}

int main()
{
    int a = 10;
    func(a);    // func(int &a)

    const int b = 12;
    func(b);    // func(const int &a)
    func(20);   // func(const int &a)

    // func2(10);  // 当函数重载碰到默认参数，出现二义性，报错，应尽量避免
    func2(10, 20);  // 正确：唯一

    return 0;
}