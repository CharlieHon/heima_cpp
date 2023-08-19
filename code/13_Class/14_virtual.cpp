#include <iostream>
#include <string>
using namespace std;

// 虚析构和纯虚析构
class Animal{
public:
    Animal(){
        cout << "Animal()" << endl;
    }
    // 纯虚函数
    virtual void speak() = 0;
    // 可以虚析构可以解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal(){
    //     cout << "~Animal()" << endl;
    // }
    // 纯虚析构：需要声明也要实现
    virtual ~Animal() = 0;  // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
};

Animal::~Animal(){
    cout << "纯虚析构: ~Animal()" << endl;
}

class Cat : public Animal{
public:
    Cat(const string &name){
        cout << "Cat(const string &)" << endl;
        pName = new string(name);   // 堆区数据
    }
    virtual void speak(){
        cout << *pName << " Cat: Meow~" << endl;
    }
    ~Cat(){
        if(pName){
            cout << "~Cat()" << endl;
            delete pName;
            pName = 0;
        }
    }
    string *pName;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时，不会调用子类析构函数，导致子类如果有堆区数据，会出现内存泄漏情况
    delete animal;
}

int main()
{
    test01();
/*
Animal()
Cat(const string &)
Tom Cat: Meow~
~Cat()
纯虚析构: ~Animal()
*/
    return 0;
}