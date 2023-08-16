#include <iostream>
#include <string>
using namespace std;

// 学生类
class Student{
public:
    void showStu(){
        cout << "姓名: " << Name
        << " 学号: " << Id << endl;
    }
    void set(const string &name, const int &id){    // 通过行为给属性赋值
        Name = name;
        Id = id;
    }

private:
    string Name;
    int Id;
};

int main()
{
    // 创建一个具体学生
    Student s1;
    s1.set("张三", 1);    // 设置信息
    s1.showStu();   // 显示信息

    return 0;
}