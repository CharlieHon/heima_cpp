#include<iostream>
using namespace std;

int main()
{
    //const修饰指针
    //1.常量指针
    int a = 10;
    int b = 20;
    const int *p1 = &a;
    //指针指向的值不可以修改，指针的指向可以改
    // *p = 20;    //报错：表达式必须是可以修改的左值
    cout << *p1 << endl;    //10
    p1 = &b;
    cout << *p1 << endl;    //20

    //2.指针常量
    int * const p2 = &a;
    //指针的指向不可以修改，指针指向的值可以修改
    cout << *p2 << endl;    //10
    *p2 = b;
    cout << *p2 << endl;    //20
    // p2 = &a;    //报错：表达式必须是可以修改的左值

    //3.const修饰指针和常量
    const int * const p3 = &a;
    // *p3 = b; //报错：表达式必须是可以修改的左值
    // p3 = &b; //报错：表达式必须是可以修改的左值

    return 0;
}