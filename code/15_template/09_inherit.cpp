#include <iostream>
using namespace std;

// 类模板与继承
template<class T>
class Base{
    T m;
};

class Son : public Base<int>{  // 必须要知道父类中的T的类型，才能继承给子类

};

// 如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1, class T2>
class Son2 : public Base<T2>{
public:
    Son2(){
        cout << "T1的数据类型为: " << typeid(T1).name() << endl;
        cout << "T2的数据类型为: " << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02(){
    Son2<int, char> s2;
}

void test01(){
    Son s1;
}

int main()
{
    test01();
    test02();
    return 0;
}