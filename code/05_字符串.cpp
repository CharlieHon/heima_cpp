#include<iostream>
#include<string>    //使用C++风格字符串，需要包含这个头文件
using namespace std;

int main()
{
    //1、C风格字符串
    //char 字符串 []
    //等号后面要用双引号包含起来字符串
    char str1[] = "hello world";
    cout << str1 << endl;

    //2、C++风格字符串
    //包含头文件 #include<string>
    string str2 = "hello world";
    cout << str2 << endl;

    return 0;
}