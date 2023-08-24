#include <iostream>
#include <string>

using namespace std;

// 通过全局函数，打印Person信息

// 提前让编译器知道Person类的存在
template<class T1, class T2>
class Person;

template<class T1, class T2>
void printInfo(Person<T1, T2> p){
    cout << "类外实现 -- 姓名: " << p.Name
    << "，年龄: " << p.Age << endl;
}

template<class T1, class T2>
class Person{
    // 全局函数，类内实现
    // friend void printInfo(Person<T1, T2> p)
    // {
    //     cout << "类内实现 -- 姓名: " << p.Name
    //     << "，年龄: " << p.Age << endl;
    // }
    
    // 全局函数，类外实现
    // 加空模板参数列表
    // 如果全局函数是类外实现的话，需要让编辑器提前知道这个函数的存在
    friend void printInfo<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age){
        this->Name = name;
        this->Age = age;
    }
    T1 Name;
    T2 Age;
};



void test01(){
    Person<string, int> p("Tom", 20);
    printInfo(p);
}

int main()
{
    test01();
    return 0;
}