#include <iostream>
using namespace std;

// 继承中构造和析构顺序

class Base{
public:
    Base()  {   cout << "Base类构造函数" << endl;   }
    ~Base() {   cout << "Base类析构函数" << endl;   }
    int A;
protected:
    int B;
private:
    int C;  // 私有成员只是被隐藏了，但是还是会被继承下去
};

// 公共继承
class Son1 : public Base{
public:
    Son1() {    cout << "Son1类构造函数" << endl;   }
    ~Son1() {   cout << "Son1类析构函数" << endl;     }
    int D;
};

void test01(){
    // Base b;
    Son1 s;     // 先调用父类构造函数，再调用子类构造函数
    // 析构函数调用顺序相反：先调用Son1析构函数，再调用Base析构函数
    // Son1 s2;
}

int main()
{
    test01();
    return 0;
}