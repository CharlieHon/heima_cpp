#include <iostream>
using namespace std;

// 加号运算符重载

class Person{
public:
    Person() = default;
    Person(const int &a, const int &b) : A(a), B(b) {}

    // // 1.成员函数 重载+号
    // Person operator+(const Person &p){
    //     Person tmp;
    //     tmp.A = this->A + p.A;
    //     tmp.B = this->B + p.B;
    //     return tmp;
    // }

    int A;
    int B;
};

// 2.全局函数 重载+号
Person operator+(const Person &p1, const Person &p2){
    Person tmp;
    tmp.A = p1.A + p2.A;
    tmp.B = p1.B + p2.B;
    return tmp;
}

Person operator+(const Person &p, const int &num){  // 根据运算对象进行重载
    Person tmp;
    tmp.A = p.A + num;
    tmp.B = p.B + num;
    return tmp;
}

void test01(){
    Person p1(10,10), p2(10,20);
    // 通过成员函数调用
    Person p3 = p1 + p2;    // 等价于 Person p3 = p1.operator+(p2);
    cout << "p3.A = " << p3.A << " p3.B = " << p3.B << endl;
}

void test02(){
    Person p1(10,10), p2(10,20);
    // 通过全局函数调用
    Person p3 = p1 + p2;    // 等价于 Person p3 = operator+(p1, p2);
    cout << "p3.A = " << p3.A << " p3.B = " << p3.B << endl;
    Person p4 = p1 + 5;     // 等价于 Person p4 = operator+(p1, 5);
    cout << "p4.A = " << p4.A << " p4.B = " << p4.B << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}