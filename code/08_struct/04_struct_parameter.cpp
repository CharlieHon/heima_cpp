#include <iostream>
#include <string>
using namespace std;

//学生结构体定义
struct Student{
    string name;
    int age;
    double score;
};

//值传递
void printStu(Student s){
    cout << "name: " << s.name
            << " age: " << s.age
            << " score: " << s.score << endl;
}

//地址传递
void printStu_(Student *p){
    cout << "name: " << p->name
            << " age: " << p->age
            << " score: " << p->score << endl;
}

int main()
{
    Student s = {"Bruce", 20, 100};
    //传值
    printStu(s);
    //传地址
    printStu_(&s);

    return 0;
}