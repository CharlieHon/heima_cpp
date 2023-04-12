#include <iostream>
#include <string>
using namespace std;

//结构体定义
struct Student{
    string name;
    int age;
    double score;
};

int main()
{
    //创建结构体数组
    Student s[3] = {
        {"Jack", 19, 95},
        {"Tom", 21, 99},
        {"John", 20, 98}
    };

    //遍历结构体数组
    for(int i=0; i<3; ++i){
        cout << "name: " << s[i].name
                << " age: " << s[i].age
                << " score: " << s[i].score << endl;
    }

    return 0;
}