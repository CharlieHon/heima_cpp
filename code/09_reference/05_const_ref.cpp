#include <iostream>

using namespace std;

// 引用的使用场景，通常用来修饰形参
void showValue(const int &val){
    // val = 1000;  // 不可修改
    cout << "val = " << val << endl;
}

int main()
{
    // 加上const之后，编译器将代码修改为 int temp = 10; const int &ref = temp;
    const int &ref = 10;
    // ref = 20;    // 加入const之后变为只读，不可以修改

    // 函数中利用常量引用防止误操作修改实参
    int a = 100;
    showValue(a);

    return 0;
}