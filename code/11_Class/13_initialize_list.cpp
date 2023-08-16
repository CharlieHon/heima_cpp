#include <iostream>
using namespace std;

// 初始化列表
class Person{
public:
    // 传统初始化操作
    // Person(const int &a, const int &b, const int &c){
    //     A = a;
    //     B = b;
    //     C = c;
    // }

    // 初始化列表 初始属性
    Person() : A(10), B(20), C(30)  {}  // 默认构造函数
    Person(const int &a, const int &b, const int &c) : A(a), B(b), C(c) {}

    int A;
    int B;
    int C;
};

void test01(){
    Person p(1, 2, 3);
    cout << "A: " << p.A << " B: " << p.B << " C: " << p.C << endl;
}

int main()
{
    test01();
    return 0;
}