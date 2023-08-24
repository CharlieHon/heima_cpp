#pragma once
#include <iostream>
#include <string>

class Person{
    friend std::ostream& operator<<(std::ostream&, const Person&);  // 重载输出运算符 <<
public:
    Person() = default;
    Person(const std::string &name, int age) : Name(name), Age(age) {}
    Person(const Person &p){
        this->Name = p.Name;
        this->Age = p.Age;
    }

    Person& operator=(const Person &p){ // 重载赋值运算符
        this->Name = p.Name;
        this->Age = p.Age;
        return *this;
    }

    std::string name() const{   // 获取姓名
        return this->Name;
    }

    int age() const{    // 获取年龄
        return this->Age;
    }

private:
    std::string Name;
    int Age;
};

std::ostream& operator<<(std::ostream &os, const Person &p){
    os << "姓名：" << p.Name
    << " 年龄：" << p.Age;
    return os;
}