#include <iostream>
#include <string>
using namespace std;

//学生结构体定义
struct Student{
    string name;
    int age;
    double score;
}s;

//教师结构体
struct Teacher{
    int id;
    string name;
    int age;
    struct Student stu;
}t;

int main()
{
    Student s = {"Bruce", 22, 97};
    //通过指针指向结构体变量
    Student *p = &s;
    //通过结构体指针访问结构体变量中的数据
    //可以使用 `->`
    cout << "name: " << p->name << endl;
    cout << "age: " << (*p).age << endl;
    cout << "score: " << p->score << endl;

    return 0;
}