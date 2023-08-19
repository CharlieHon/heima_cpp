#include <iostream>
using namespace std;

// 纯虚函数和抽象类
class Base{
public:
    // virtual 函数返回类型 函数名(参数列表) = 0;
    // 只要有一个纯虚函数，这个类就称为抽象类
    // 1.无法实例化对象
    // 2.抽象类的子类必须要重写父类中的纯虚函数，否则也是抽象类
    virtual void func() = 0;    // 纯虚函数
};

class Son : public Base{
public:
    virtual void func() {
        cout << "func()" << endl;
    }
};

void test01(){
    // Base b; // 抽象类是无法实例化对象
    // new Base;   // 抽象类无法实例化对象
    Base *base = new Son;
    base->func();
}

int main()
{
    test01();
    return 0;
}