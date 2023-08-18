#include <iostream>
using namespace std;

// 继承方式

// 公共继承
class Base1{
public:
    int A;
protected:
    int B;
private:
    int C;
};

class Son1 : public Base1{
public:
    void func(){
        A = 10; // 父类中的公有权限，在子类中仍然是公有权限
        B = 20; // 父类中的保护权限，在子类中仍然是保护权限
        // C = 30; // 父类中的私有权限成员，子类访问不到
    }
};

class Son2 : protected Base1{
public:
    void func(){    // 父类中的公有权限，在子类中变为保护权限，保护权限不变
        A = 10;
        B = 20;
        // C = 30; // 父类中的私有权限成员，子类访问不到
    }
};

class Son3 : private Base1{
public:
    void func(){    // 父类中的公有权限成员和保护权限成员在子类中均为私有成员
        A = 10;
        B = 20;
        // C = 30; // 父类中的私有权限成员，子类访问不到
    }
};

class GrandSon3 : public Son3{
public:
    void func(){
        // A = 1;  // 错误：A在Son3类中为私有属性，子类无法访问；下同
        // B = 2;
        // C = 3;
    }
};

void test01(){
    Son1 s1;
    Son2 s2;
    Son3 s3;

    // 公有继承
    s1.A = 1;
    // s1.B = 2;   // 错误：保护权限，类外无法访问
    // 保护权限
    // s2.A = 3;   // 错误：保护权限，类外访问不到，下同
    // s2.B = 4;
    // s2.C = 0;   // 成员 Base1::C 无法访问
    // 私有权限
    // s3.A = 5;   // 错误：私有权限，类外无法访问，下同
    // s3.B = 6;
}

int main()
{
    test01();
    return 0;
}