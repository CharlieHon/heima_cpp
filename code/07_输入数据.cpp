#include<iostream>
#include<string>
using namespace std;

int main()
{
    //1、整型
    int a;
    cout << "请给整型变量a赋值:" << endl;
    cin >> a;
    cout << "a = " << a << endl;

    //2、浮点型
    float f = 3.14f;
    cout << "请给浮点型变量f赋值:" << endl;
    cin >> f;
    cout << "f = " << f << endl;

    //3、字符型
    char ch = 'a';
    cout << "请给字符型变量ch赋值:" << endl;
    cin >> ch;
    cout << "ch = " << ch << endl;

    //4、字符串型
    string str = "hello";
    cout << "请给字符串str赋值:" << endl;
    cin >> str;
    cout << "str = " << str << endl;


    //5、bool型
    bool flag = true;
    cout << "请给布尔变量flag赋值:" << endl;
    cin >> flag;
    cout << "flag = " << flag << endl;

    system("pause");
    return 0;
}