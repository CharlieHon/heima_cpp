#include <iostream>
using namespace std;

// 空指针调用成员函数

class Person{
public:
    void showClassName(){
        cout << "this is Person class" << endl;
    }

    void showPersonAge(){
        if(!this)   return; // 保证代码的健壮性
        cout << "age = " << Age << endl;    // 默认为 this->Age
    }

    int Age;
};

void test01(){
    Person *p = 0;  // 空指针
    p->showClassName(); // 正确
    // p->showPersonAge();  // 函数中包含隐式this，传入指针为空，报错
}

void test02(){
    Person *p = 0;
    p->showPersonAge();
}

int main()
{
    // test01();
    test02();
    return 0;
}