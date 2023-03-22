#include<iostream>
using namespace std;

int main()
{
    //1.单精度 float
    //2.双精度 double
    //默认情况下，输出一个小数，会显示出6位有效数字
    float f1 = 3.1415926f;   //编辑器会将小数默认为double型，在末尾加上f则表示其为float型
    cout << "f1 = " << f1 << endl;

    double d1 = 3.1415926;
    cout << "d1 = " << d1 << endl;

    //统计float和都变了占用内存空间
    cout << "float占用内存空间: " << sizeof(float) << endl;
    cout << "double占用内存空间: " << sizeof(double) << endl;

    //科学计数法
    float f2 = 3e2;
    cout << "f2 = " << f2 << endl;  //300

    float f3 = 3e-2;
    cout << "f3 = " << f3 << endl;  //0.03

    return 0;
}