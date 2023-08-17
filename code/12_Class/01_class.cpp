#include <iostream>
using namespace std;

// 成员变量和成员函数分开存储

class Person{
    int A;  // 非静态成员变量，属于类的对象
    static int B;   // 静态成员变量，不属于类的对象
    void func() {}  // 非静态成员函数，也不属于类对象
    static void func2() {}  // 静态成员函数，不属于类对象
};

int Person::B = 10;

void test01(){
    Person p;
    // 空对象占用内存空间为：1
    // C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象有独一无二的内存地址
    cout << "size of p = " << sizeof(p) << endl;    // 1
}

void test02(){
    Person p;
    // 非空类中，对象所占内存为非静态成员变量的内存
    cout << "size of p = " << sizeof(p) << endl;    // 4
}

int main()
{
    // test01();
    test02();
    return 0;
}