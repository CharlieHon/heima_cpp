#include <iostream>
using namespace std;

// 多态的基本概念

class Animal{
public:
    // 虚函数
    // 在函数前面加上 virtual 关键字，编程虚函数，那么编译器在编译时就不能确定函数调用了
    virtual void bark() const { // 
        cout << "动物叫" << endl;
    }
};

class Cat : public Animal{  // 猫
public:
    // 重写父类函数 函数返回类型 函数名 参数列表 完全相同
    virtual void bark() const {
        cout << "Cat: 喵~" << endl;
    }
};

class Dog : public Animal{  // 狗
public:
    void bark() const { // virtual关键字 可不写
        cout << "Dog: 汪~" << endl;
    }
};

// 执行函数
// 地址早绑定 在编译阶段就确定了函数地址
// 如果像执行让猫叫，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

// 动态多态满足条件
// 1.有继承关系
// 2.子类要重写父类的虚函数

// 动态多态使用
// 父类的指针或者引用，执行子类对象

void doBark(const Animal &a){
    a.bark();
}

void test01(){
    Cat c;
    doBark(c);  // Cat: 喵~
    Dog d;
    doBark(d);  // Dog: 汪~
}

void test02(){
    cout << "sizeof Animal = " << sizeof(Animal) << endl;   // 8
    cout << "sizeof Cat = " << sizeof(Cat) << endl;   // 8
    cout << "sizeof Dog = " << sizeof(Dog) << endl;   // 8
}

int main()
{
    test01();
    test02();
    return 0;
}