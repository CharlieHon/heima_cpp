#include <iostream>

using namespace std;

// 占位参数
void func(int a, int){
    cout << "this if a function." << endl;
}

void func2(int a, int = 20){    // 占位参数也可以有默认参数
    cout << "hello world" << endl;
}

int main()
{
    // func(10);    // 错误
    func(10, 20);
    func2(10);

    return 0;
}