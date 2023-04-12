#include<iostream>
using namespace std;

int main()
{
    //转义字符
    //换行符    \n
    cout << "hello world\n";

    //反斜杠    "\\"
    cout << "\\" << endl;

    //水平制表符    \t 可以整齐地输出数据
    cout << "aa\thello world" << endl;
    cout << "aaa\thello world" << endl;

    return 0;
}