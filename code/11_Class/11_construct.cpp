#include <iostream>
using namespace std;

// 构造函数的调用规则
// 1.创建一个类，C++编译器会给每个类都添加至少3个函数
// 默认构造函数
// 析构函数
// 拷贝构造函数

// 2.如果提供了有参构造函数，编译器就不在提供默认构造函数，但仍提供拷贝构造函数

class Person{
public:
    Person(){
        cout << "Person默认构造函数" << endl;
    }

    Person(int age){
        Age = age;
        cout << "Person有参构造函数" << endl;
    }

    Person(const Person &p){
        Age = p.Age;
        cout << "Person拷贝构造函数" << endl;
    }

    ~Person(){
        cout << "Person析构函数调用" << endl;
    }

int Age;
};

void test01(){
    Person p;
    p.Age = 18;

    Person p2(p);   // 编译器自动生成拷贝构造函数
    cout << "p2.Age = " << p2.Age << endl;
}

void test02(){
    // Person p;   // 调用默认构造函数
    Person p1(18);
    Person p2(p1);
    cout << "p2.Age = " << p2.Age << endl;
}

int main()
{
    test01();
    test02();

    return 0;
}