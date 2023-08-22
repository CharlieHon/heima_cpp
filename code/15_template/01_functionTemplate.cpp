#include <iostream>
using namespace std;

// 函数模板
// 模板注意事项
// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
// 2.模板必须要确定出T的数据类型，才可以使用

// 交换两个整数函数
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型函数
void swapDouble(double &a, double &b){
    double tmp = a;
    a = b;
    b = tmp;
}

// typename可以替换成class
template<typename T>    // 声明一个模板，告诉编译器后面T是一个通用数据类型
void mySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01(){
    int a = 10, b = 20;
    char c = 'j';
    mySwap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    // mySwap(a, c);   // 错误！
}

// 2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func(){
    cout << "func()" << endl;
}

int main()
{
    int a = 10, b = 20;
    double c = 3.1, d = 4.5;
    // swapInt(a, b);
    // swapDouble(c, d);
    
    // 使用函数模板，有两种方式使用函数模板
    // 1.自动类型推导
    mySwap(a, b);
    // 2.显示指定类型
    mySwap<double>(c, d);

    // func(); // 错误：没有与参数列表匹配的函数模板 "func" 实例
    func<int>();    // 正确！

    return 0;
}