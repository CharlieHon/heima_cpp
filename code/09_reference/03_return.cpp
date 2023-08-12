#include <iostream>

using namespace std;

// 引用做函数的返回值
// 1.不要返回局部变量的引用
// int &test01(){
//     int a = 10; // 局部变量存放在四区中的 栈区
//     return a;   // 错误：返回局部变量的引用
// }

// 2.函数的调用可以作为左值
int &test02(){
    static int a = 10;  // 静态变量，存放在全局区，在程序结束后由系统释放
    return a;
}

int main()
{
    // int &ref = test01();
    // cout << ref << endl;

    int &ref2 = test02();
    cout << ref2 << endl;   // 10

    // 函数的返回值是引用，这个函数调用可以作为左值
    test02() = 1000;    // 作为左值
    cout << ref2 << endl;   // 1000

    return 0;
}