#include <iostream>
#include <string>
// #include "person.cpp"   // 第一种解决方式：直接包含源文件
#include "person.hpp"   // 第二种解决方式：将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件

using namespace std;

// 类模板分文件编写问题以及解决

// template<class T1, class T2>
// class Person{
// public:
//     Person(T1 name, T2 age);
//     void showInfo();
//     T1 Name;
//     T2 Age;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age){
//     this->Name = name;
//     this->Age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::showInfo(){
//     cout << "姓名: " << this->Name
//     << "，年龄: " << this->Age << endl;
// }

void test01(){
    Person<string, int> p1("Tom", 20);
    p1.showInfo();
}

int main()
{
    test01();   // 姓名: Tom，年龄: 20
    return 0;
}