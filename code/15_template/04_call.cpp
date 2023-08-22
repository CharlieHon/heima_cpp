#include <iostream>
using namespace std;

// 普通函数与函数模板的调用规则

void myPrint(int a, int b){
    cout << "调用的普通函数" << endl;
}

template<class T>
void myPrint(T a, T b){
    cout << "调用的模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c){
    cout << "重载的模板" << endl;
}

void test01(){
    int a = 10, b = 20;
    myPrint(a, b);  // 调用普通函数，即使普通函数仅有声明(会报错)
    myPrint<>(a, b);    // 通过空模板参数列表，强制调用函数模板
    myPrint(a, b, 10);  // 调用重载的模板

    // 如果函数模板产生更好的匹配，优先调用函数模板
    char c1 = 'a', c2 = 'h';
    myPrint(c1, c2);    // 调用的模板：普通函数 > 模板 > 隐式类型转换

}

int main()
{
    test01();
    return 0;
}