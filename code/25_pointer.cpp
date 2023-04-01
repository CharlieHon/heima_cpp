#include<iostream>
using namespace std;

int main()
{
    //1.定义指针
    int a = 10;
    int *p;
    p = &a;
    cout << "a的地址为: " << &a << endl;    //a的地址为: 0x61fe14
    cout << "指针p为: " << p << endl;       //指针p为: 0x61fe14

    //2.使用指针
    //可以使用解引用的方式来找到指针指向的内存
    //指针前加 * 代表解引用，找到指针指向的内存中的数据
    *p = 1000;
    cout << "a = " << a << endl;    //a = 1000
    cout << "*p = " << *p << endl;  //*p = 1000

    //3.指针所在内存空间
    cout << "sizeof(int *) = " << sizeof(p) << endl;    //8
    cout << "sizeof(float *) = " << sizeof(float *) << endl;    //8
    cout << "sizeof(double *) = " << sizeof(double *) << endl;    //8
    cout << "sizeof(char *) = " << sizeof(char *) << endl;    //8

    //4.空指针
    //空指针用于给指针变量初始化
    //空指针是不可以进行访问的,0~255之间的内存编号是系统占用的，因此不可以访问
    int *p1 = NULL;
    // cout << *p1 << endl; //不允许访问，报错

    //5.野指针
    //在程序中，尽量避免出现野指针
    int *p2 = (int *)0x1100;
    // cout << *p2 << endl;

    return 0;
}