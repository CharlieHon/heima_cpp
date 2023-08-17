#include <iostream>
#include <string>
using namespace std;

// 函数调用运算符重载

// 打印输出类
class MyPrint{
public:
    // 重载函数调用运算符
    void operator()(const string &s){
        cout << s << endl;
    }
};

void MyPrint02(const string &s){
    cout << s << endl;
}

void test01(){
    MyPrint p;
    p("Hello, World!"); // 对象调用()符号，类似函数调用，因此称为仿函数
    MyPrint02("TEST!");
}

// 仿函数非常灵活，没有固定的写法
// 加法类
class MyAdd{
public:
    int operator()(const int &a, const int &b){
        return a+b;
    }
};

void test02(){
    MyAdd m;
    int res = m(100, 200);
    cout << res << endl;    // 300
}

void test03(){
    // 匿名函数对象；匿名对象：类名加小括号 MyAdd()
    cout << MyAdd()(10, 20) << endl;    // 30
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}