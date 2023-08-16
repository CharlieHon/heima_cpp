#include <iostream>
using namespace std;

// 对象的初始化和清理
// 1、构造函数 进行初始化操作

class Person{
public:
    // 1.构造函数
    // 没有返回值 不用写void
    // 函数名 与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象时，构造函数会自动调用，而且只调用一次
    // Person () = default;    // 合成默认构造函数
    Person() {
        cout << "Person()" << endl;
    }

    // 2.析构函数 进行清理操作
    // 没有返回值，不写void
    // 函数名和类名相同 在名称前加 ~
    // 析构函数没有参数，不可以重载
    // 对象在销毁前 会自动调用析构函数，而且只会调用一次
    ~Person(){
        cout << "~Person()" << endl;
    }
};

// 构造和析构都是必须实现的，如果不提供，编译器会提供
void test01(){
    Person p;   // 在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{
    test01();

    return 0;
}