#include <iostream>
using namespace std;

// 多继承

class Base1{
public:
    Base1() : A(10) {}
    int A;
};

class Base2{
public:
    Base2() : A(20) {}
    int A;
};

// 子类 继承Base1和Base2
// 语法：class 子类 : 继承方式 父类, 继承方式 父类
class Son : public Base1, public Base2{
public:
    Son() : C(30), D(40) {}
    int C;
    int D;
};

void test01(){
    Son s;
    cout << "sizeof(s) = " << sizeof(s) << endl;    // 16
    // 当父类中出现同名成员，需要加作用域区分
    cout << "s.Base1::A = " << s.Base1::A << endl;    // 10
    cout << "s.Base2::A = " << s.Base2::A << endl;    // 20
}

int main()
{
    test01();
    return 0;
}