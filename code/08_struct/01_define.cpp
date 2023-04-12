#include <iostream>
#include <string>
using namespace std;
//1.创建学生类型数据结构：学生包括（姓名，年龄，分数）
//自定义数据类型，一些类型集合组成的一个类型
struct Student{
    //成员列表
    string name;
    int age;
    double score;
}s3;

int main()
{
    //2.通过学生类型撞见具体学生
    //2.1 struct Student s1;
    struct Student s1;  // 定义变量时 struct 关键字可以省略
    s1.age = 18;
    s1.name = "Bruce";
    s1.score = 99;
    //2.2 struct Student s2 = {...}
    struct Student s2 = {"Leslie", 20, 98};

    //2.3 在定义结构体时顺便创建结构体变量
    s1.age = 20;
    s1.name = "Jack";
    s1.score = 95;

    return 0;
}