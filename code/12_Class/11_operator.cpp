#include <iostream>
using namespace std;

// 赋值运算符重载

class Person{
public:
    Person(const int &age){
        Age = new int(age);
    }
    ~Person(){
        if(Age){
            delete Age;
            Age = 0;
        }
    }

    // 重载赋值运算符
    Person& operator=(const Person &p){
        // 编译器提供的是浅拷贝
        // Age = p.Age;

        // 应该先判断是否有属性在堆区；如果有，先释放干净
        if(Age){
            delete Age;
            Age = 0;
        }
        // 深拷贝
        Age = new int(*p.Age);

        return *this;   // 返回自身，允许链式操作 p1 = p2 = p3
    }

    int *Age;
};

void test01(){
    Person p1(18), p2(20), p3(30);
    cout << "p1.age = " << *p1.Age << endl;
    cout << "p2.age = " << *p2.Age << endl;
    p2 = p1;    // 如果不重载赋值运算符，默认浅拷贝下会导致堆区内存重复释放
    cout << "p1.age = " << *p1.Age << endl;
    cout << "p2.age = " << *p2.Age << endl;

    p1 = p2 = p3;
    cout << "p1.age = " << *p1.Age << ", p2.age = " << *p2.Age << ", p3.age = " << *p3.Age << endl;
}

int main()
{
    test01();

    int a = 10, b = 20, c = 30;
    c = b = a;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;    // a = 10, b = 10, c = 10

    return 0;
}