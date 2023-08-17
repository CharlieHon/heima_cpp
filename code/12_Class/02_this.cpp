#include <iostream>
using namespace std;

// this指针
// 1.解决名称冲突
// 2.返回对象本身 *this

class Person{
public:
    Person() = default;
    Person(const int &age){
        this->age = age;    // this指针指向调用函数的对象
    }

    Person& PersonAddAge(const Person &p){
        this->age += p.age;
        return *this;   // 返回对象本身
    }

    int age;
};

// 1.解决名称冲突
void test01(){
    Person p1(18);  // this指向p1
    cout << "p1.age = " << p1.age << endl;
}

// 2.返回对象本身用 *this
void test02(){
    Person p1(10);
    Person p2(20);

    p1.PersonAddAge(p2).PersonAddAge(p2);   // 链式编程思想
    cout << "p1.age = " << p1.age << endl;  // 10 + 20 + 20 = 50
}

int main()
{
    // test01();
    test02();
    return 0;
}