#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// 学生的结构体
struct Student{
    // 姓名
    string name;
    // 分数
    int score;
};

// 老师的结构体定义
struct Teacher{
    // 姓名
    string tname;
    // 学生数组
    Student sArray[5];
};

// 给老师和学生信息赋值
void allocateSpace(Teacher tArray[], int len){
    string nameSeed = "ABCDE";
    // 给老师开始赋值
    for(int i=0; i<len; ++i){
        tArray[i].tname = string("Teacher_") + nameSeed[i];
        // 通过循环给每名老师所带的学生赋值
        for(int j=0; j<5; ++j){
            tArray[i].sArray[j].name = string("Student_") + nameSeed[j];
            tArray[i].sArray[j].score = rand()%61+40;   // [0, 100]
        }
    }
}

// 打印所有信息
void printInfo(struct Teacher tArray[], int len){
    for(int i=0; i<len; ++i){
        cout << tArray[i].tname << endl;
        for(int j=0; j<5; ++j){
            cout << "\t" << tArray[i].sArray[j].name << ": " << tArray[i].sArray[j].score << endl;
        }
    }
}

int main()
{
    srand(time(NULL));  // 随机种子初始化
    // 1.创建3名老师的数组
    struct Teacher tArray[3];
    int len = sizeof(tArray)/sizeof(tArray[0]);
    // 2.通过函数给3名老师信息复制，并给老师带的学生信息赋值
    allocateSpace(tArray, len);
    // 3.打印所有老师及所带的学生信息
    printInfo(tArray, len);

    return 0;
}