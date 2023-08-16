#include <iostream>
using namespace std;

// 静态成员变量
class Person{
public:
    // 所有类对象共享同一份数据
    // 编译阶段分配内存
    // 类内声明，类外初始化操作
    static int A;

    // 静态成员变量也是有访问权限的
private:
    static int B;
};

int Person::A = 100;    // 类外初始化
int Person::B = 500;


void test01(){
    Person p;
    cout << p.A << endl;    // 100

    Person p1;
    p1.A = 200;
    cout << p.A << endl;    // 200
}

void test02(){
    // 静态成员变量，不属于某个对象，所有对象都共享同一份数据
    // 因此静态成员变量有两种访问方式

    // 1.通过对象访问
    Person p;
    cout << p.A << endl;    // 100
    // 2.通过类名访问
    cout << Person::A << endl;  // 100
    // cout << Person::B << endl;  // 类外访问不到私有权限的静态成员变量
}

int main()
{
    // test01();
    test02();
    return 0;
}