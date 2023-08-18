#include <iostream>
using namespace std;

// 继承同名成员处理方式

class Base{
public:
    Base() : A(10) {}
    void func(){
        cout << "Base::func()" << endl;
    }
    void func(const int &a){
        cout  << "Base::func(const int&)" << endl;
    }
    int A;
};

class Son1 : public Base{
public:
    Son1() : A(20) {}
    void func(){
        cout << "Son1::func()" << endl;
    }
    int A;
};

// 同名成员属性
void test01(){
    Son1 s1;
    //                  s1.Son1::A
    cout << "s1.A = " << s1.A << endl;  // 20
    //通过子类对象访问父类成员变量需要加上作用域 Base::A
    cout << "s1.Base::A = " << s1.Base::A << endl; // 10
}

// 同名成员函数
void test02(){
    Son1 s;
    s.func();   // 直接调用，调用的是子类的成员函数
    s.Base::func(); // 调用父类成员函数

    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员
    // s.func(100);    // 父类的重载函数也被隐藏，调用需要加上作用域
    s.Base::func(10);
}

int main()
{
    test01();
    test02();
    return 0;
}