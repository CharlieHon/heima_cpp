#include <iostream>

using namespace std;

// 函数默认参数
int func(int a, int b = 20, int c = 60){    // 如果传入参数，就用自己的数据；否则，用莫二五年至
    return a + b + c;
}

// 注意事项
// 1.如果某个位置已经有了默认参数，那么这个位置往后，从左到右都必须有默认值
// int func2(int a, int b = 2, int c); // 错误：c也得有默认参数

// 2.如果函数声明有默认参数，函数实现就不能有默认参数
int func3(int a = 10, int b = 20);

int main()
{
    cout << func(10, 20, 30) << endl;
    cout << func(10) << endl;
    cout << func3() << endl;

    return 0;
}

int func3(int a, int b){    // 声明和实现只能有一个有默认参数
    return a + b;
}