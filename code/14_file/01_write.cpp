#include <iostream>
#include <fstream>
using namespace std;

// 文本文件 写文件

void test01(){
    // 1.包含头文件
    // 2.创建流对象
    ofstream ofs;
    // 3.绑定文件，指定打开方式
    ofs.open("test.txt", ios::out); // 如果不指定路径，默认为程序所在当前路径
    // 4.写内容
    ofs << "姓名：张三" << endl;
    ofs << "性别：张三" << endl;
    ofs << "年龄：28" << endl;
}

int main()
{
    test01();
    return 0;
}