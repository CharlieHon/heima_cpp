#include <iostream>
#include <string>

using namespace std;

// 类模板成员函数类外实现

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);
    void showInfo();

    T1 Name;
    T2 Age;
};

// 构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->Name = name;
    this->Age = age;
}

// 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showInfo(){
    cout << "姓名: " << this->Name
    << "，年龄: " << this->Age << endl;
}

int main()
{
    Person<string, int> p("Tom", 20);
    p.showInfo();   // 姓名: Tom，年龄: 20
    return 0;
}