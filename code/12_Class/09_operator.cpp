#include <iostream>
using namespace std;

// 左移运算符重载

class Person{
    friend ostream& operator<<(ostream &, const Person &);
public:
    Person() = default;
    Person(const int &a, const int &b) : A(a), B(b) {}

    // 通常不会利用成员函数重载左移运算符，因为无法实现 cout 在左侧
    // void operator<<(cout){   // p.operator<<(cout)   p << cout
    // }

private:
    int A;
    int B;
};

// 只能利用全局函数重载左移运算符 <<
ostream& operator<<(ostream &os, const Person &p){ // 本质 operator<<(cout, p) 简化 cout << p
    os << "A = " << p.A << " B = " << p.B;
    return os;  // 返回流引用，可以进行链式编程
}

void test01(){
    Person p(10, 10);
    // cout << p.A << endl;
    cout << p << endl;  // A = 10 B = 10
}

int main()
{
    test01();
    return 0;
}