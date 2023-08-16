#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person{
public:
    static void func(){
        A = 100;    // 静态成员函数可以访问 静态成员变量
        // B = 200;    // 静态成员函数不可以访问非静态成员变量；无法区分到底是哪个对象的成员变量
        cout << "static void func() 调用" << endl;
    }

private:
    static int A;
    int B;
    // 静态成员函数也有访问权限
    static void func2(){
        cout << "static void func2()调用" << endl;
    }
};

int Person::A = 500;

// 有两种访问方式
void test01(){
    // 1.通过对象访问呢
    Person p;
    p.func();
    // 2.通过类名访问
    Person::func();

    // Person::func2();    // 类外访问不到私有静态成员函数
}

int main()
{
    test01();
    return 0;
}