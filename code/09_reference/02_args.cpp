#include <iostream>

using namespace std;

// 1.值传递
void swap1(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

// 2.传地址
void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.传引用
void swap3(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;

    cout << "a = " << a << ", b = " << b << endl;
    // swap1(a, b);
    // swap2(&a, &b);
    swap3(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}