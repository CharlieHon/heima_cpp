#pragma
#include <iostream>
#include <string>

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);
    void showInfo();
    T1 Name;
    T2 Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->Name = name;
    this->Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showInfo(){
    std::cout << "姓名: " << this->Name
    << "，年龄: " << this->Age << std::endl;
}