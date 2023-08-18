#include <iostream>
using namespace std;

// 继承中的对象模型

class Base{
public:
    int A;
protected:
    int B;
private:
    int C;  // 私有成员只是被隐藏了，但是还是会被继承下去
};

// 公共继承
class Son1 : public Base{
public:
    int D;
};

void test01(){
    Son1 s1;
    // 父类中所有非静态成员属性都会被子类继承下来
    // 父类中私有成员属性，被编译器给隐藏了，因此访问不到，但是确实是被继承下来了
    cout << "sizeof(Son): " << sizeof(s1) << endl;  // 16
}

int main()
{
    test01();
    return 0;
}