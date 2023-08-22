#include <iostream>
using namespace std;

// 普通函数与函数模板的区别
// 1.普通函数调用时可以发生隐式类型转换
// 2.函数模板 用自动类型推导，不可以发生隐式类型转换
// 3.           显示指定类型，可以

// 普通函数
int myAdd1(int a, int b){
    return a + b;
}

// 函数模板
template<class T>
T myAdd2(T a, T b){
    return a + b;
}

void test01(){
    int a = 10, b = 20;
    char c = 'c';   // a - 97 c - 99
    cout << "10 + 20 = " << myAdd1(a, b) << endl;   // 30
    cout << "10 + c = " << myAdd1(a, c) << endl;    // 109
}

void test02(){
    int a = 10, b = 20;
    char c = 'c';   // a - 97 c - 99
    cout << "10 + 20 = " << myAdd2(a, b) << endl;   // 30
    // cout << "10 + c = " << myAdd2(a, c) << endl;    // 报错：自动类型推导下，不能进行隐式类型转换
}

void test03(){
    int a = 10, b = 20;
    char c = 'c';   // a - 97 c - 99
    cout << "10 + 20 = " << myAdd2<int>(a, b) << endl;   // 30
    cout << "10 + c = " << myAdd2<int>(a, c) << endl;    // 正确：显示指定类型，可以进行类型转换
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}