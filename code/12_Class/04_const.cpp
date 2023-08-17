#include <iostream>
using namespace std;

// const修饰成员函数

class Person{
public:
    // this指针的本质是 指针常量 指针的指向是不可以修改的
    // 在成员函数后面加 const，修饰的是this指向的对象，让指针指向的值也不可以修改
    void showPerson() const {   // 常函数
        // this = 0;   // 不可以修改this指针的指向(Person *const this)
        // this->Age = 10; // 常函数内不可以修改对象属性(const Person *const this)
        this->B = 16;   
    }

    void func(){
        cout << "void func()" << endl;
    }

    int Age;
    mutable int B;  // 特殊变量，即使在常函数中，也可以修改这个值，加关键字 mutable
};

// 1.常函数
void test01(){
    Person p;
    p.showPerson();
}

// 2.常对象
void test02(){
    const Person p1;    // 在对象前加 const，变为常对象
    // p1.Age = 10;    // 错误：p1是常对象，属性不可以修改
    p1.B = 20;  // 特殊变量在常对象下，也可以修改

    // 常对象只能调用常函数
    p1.showPerson();    // 正确：常对象调用常函数
    // p1.func();  // 错误：func不是常函数
}

int main()
{
    test01();
    // test02();
    return 0;
}