#include<iostream>
using namespace std;

//返回值类型 函数名 参数列表{函数体 return 表达式}
int add(int a, int b){
    int sum = a + b;
    return sum;
}

//定义函数，实现两个数字进行交换
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

//函数常见样式
// 1. 无参数无返回值
void test1(){
    cout << "test1()" << endl;
}
// 2. 有参数无返回值
void test2(int a){
    cout << "test2() " << a << endl;
}
// 3. 无参数有返回值
int test3(){
    cout << "test3()" << endl;
    return 12;
}
// 4. 有参数有返回值
int test4(int a){
    cout << "test4()" << endl;
    return a;
}

//函数的声明
//提前告诉编译器函数的存在。声明可以有多次，但是定义只能有一次
int max(int , int);


int main()
{
    int a, b;
    cout << "请输入两个数：" << endl;
    cin >> a >> b;
    int sum = add(a, b);
    cout << a << " + " << b << " = "
        << sum << endl;

    //值传递
    cout << "交换前：" << endl;
    cout << "a: " << a
        << " b: " << b << endl;
    cout << "交换后：" << endl;
    swap(a, b);
    cout << "a: " << a
        << " b: " << b << endl;

    cout << "max(a, b) = " << max(a, b) << endl;

    return 0;
}

//函数定义
int max(int a, int b){
    return a > b ? a : b;
}