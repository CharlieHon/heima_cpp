#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 二进制文件 读写文件
class Person{
public:
    char Name[64];  // 姓名
    int Age;    // 年龄
};

void test01(){  // 写文件
    // 1.包含头文件
    // 2.创建流对象
    ofstream ofs("person.txt", ios::out | ios::binary); // 初始化
    // 3.打开文件
    // ofs.open("person.txt", ios::out | ios::binary);
    // 4.写数据
    Person p = {"张三", 23};
    ofs.write((const char *)&p, sizeof(Person));
    // 5.关闭文件
    ofs.close();
}

void test02(){  // 读文件
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs("person.txt", ios::in | ios::binary);
    // 3.打开文件
    // ifs.open();
    if(!ifs.is_open()){ // 判断文件是否打开成功
        cout << "文件打开失败" << endl;
    }
    // 4.读取文件
    Person p;
    ifs.read((char*)&p, sizeof(Person));
    cout << "姓名：" << p.Name << " 年龄：" << p.Age << endl;
    // 5.关闭文件
    ifs.close();
}

int main()
{
    // test01();
    test02();   // 姓名：张三 年龄：23
    return 0;
}