#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student{
    string name;
    int score;
};

struct Teacher{
    string name;
    struct Student stuArray[5]; //每名老师带5和学生
};

//给老师和学生赋值的函数
void allocateSpace(Teacher *t, const int n){
    string names = "ABCDEFG";
    for(int i=0; i<n; ++i){
        (t+i)->name = string("Teacher_") + names[i];
        //给老师带的学生赋值
        for(int j=0; j<5; ++j){
            (t+i)->stuArray[j].name = string("Stu_") + names[j];
            int random = rand() % 61 + 40;  // 0~60 + 40
            (t+i)->stuArray[j].score = random;
        }
    }
}

//打印所有信息
void printInfo(const Teacher *t, const int n){
    for(int i=0; i<n; ++i){
        cout << "Teacher_name: " << (t+i)->name << endl;
        for(int j=0; j<5; ++j){
            cout << "Student_name: " << (t+i)->stuArray[j].name
                << " Student_score: " << (t+i)->stuArray[j].score
                << endl;
        }
    }
}

int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));

    //1.创建3名老师的数组
    Teacher t[3];
    const int n = sizeof(t)/sizeof(t[0]);
    //2.通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
    allocateSpace(t, n);
    //3.打印所有老师及其学生信息
    printInfo(t, n);

    return 0;
}