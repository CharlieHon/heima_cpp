#include <iostream>
#include <string>
using namespace std;

//学生结构体定义
struct Student{
    string name;
    int age;
    double score;
};

//传引用，节省内存
void printStu(const Student &s){
    cout << "name: " << s.name
            << " age: " << s.age
            << " score: " << s.score << endl;
}

int main()
{
    const Student s = {"Bruce", 23, 98};
    printStu(s);

    return 0;
}