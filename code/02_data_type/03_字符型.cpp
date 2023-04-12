#include<iostream>
using namespace std;

int main()
{
    //1、字符型变量创建方式
    char ch = 'a';
    cout << ch << endl;

    //2、字符型变量所占内存大小
    cout << "char字符型变量所占内存: " << sizeof(char) << endl;
    
    //3、字符型变量常见错误
    // char ch2 = "b";  //创建字符型变量时，要用单引号
    // char ch3 = 'abcd';  //单引号内只能有一个字符
    
    //4、字符型变量对应ASCII编码
    // a-97 A-65
    cout << (int)ch << endl;    //97为字符a对应的ASCII值

    return 0;
}