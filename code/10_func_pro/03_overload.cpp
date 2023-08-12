#include <iostream>

using namespace std;

// 函数充值该
// 可以让函数名相同，提高复用性

void func(){
    cout << "func()" << endl;
}

void func(int a){
    cout << "func(int a)" << endl;
}

void func(double a){
    cout << "func(double a)" << endl;
}

void func(int a, double b){
    cout << "func(int a, double b)" << endl;
}

void func(double a, int b){
    cout << "func(double a, int b)" << endl;
}

// 函数的返回值类型不同不可以作为重载的条件
// int func(){
//     return 1;
// }

int main()
{

    // 参数个数不同
    func();

    // 参数类型不同
    func(10);
    func(3.14);
    
    // 参数顺序不同
    func(1, 3.14);
    func(3.14, 1);

    return 0;
}