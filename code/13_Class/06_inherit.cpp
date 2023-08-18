#include <iostream>
using namespace std;

// 继承中同名静态成员处理方式

class Base{
public:
    static int A;   // 静态成员类内声明，类外初始化
    static void func(){
        cout << "Base: static void func()" << endl;
    }
};

int Base::A = 10;

class Son1 : public Base{
public:
    static int A;
    static void func(){
        cout << "Son1: static void func()" << endl;
    }
};

int Son1::A = 20;

// 同名静态成员属性
void test01(){

    // 1.通过对象访问
    Son1 s1;
    //                  Son1::A
    cout << "s1.A = " << s1.A << endl;   // 20
    //                      Base::A
    cout << "s1.Base::A = " << s1.Base::A << endl; // 10

    // 2.通过类名访问
    cout << "Son1::A = " << Son1::A << endl;    // 20
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下的
    cout << "Son1::Base::A = " << Son1::Base::A << endl;  // 10   同 Base::A
}

// 同名静态成员函数
void test02(){
    // 通过对象访问
    Son1 s;
    s.func();
    s.Base::func();
    // 通过类名访问
    Son1::func();
    Son1::Base::func();
}

int main()
{
    test01();
    test02();
    return 0;
}