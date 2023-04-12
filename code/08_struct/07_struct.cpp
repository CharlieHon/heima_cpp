#include <iostream>
#include <string>
using namespace std;

//1.设计英雄结构体
struct Hero{
    string name;
    int age;
    string gender;
};

//打印结构体数组
void print_Hero(const Hero *h){
    for(int i=0; i<5; ++i){
        cout << "name: " << (h+i)->name
            << " gender: " << (h+i)->gender
            << " age: " << (h+i)->age
            << endl;
    }
}

//冒泡排序
void bubbleSort(Hero *h, const int n){
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-1-i; ++j){
            Hero tmp = h[j+1];
            if(h[j].age > h[j+1].age){
                h[j+1] = h[j];
                h[j] = tmp;
            }
        }
    }
}
int main()
{
    //2.创建数组存放5个英雄
    Hero heroArray[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 21, "男"},
        {"赵云", 22, "男"},
        {"貂蝉", 18, "女"},
    };

    cout << "排序前：" << endl;
    print_Hero(heroArray);
    bubbleSort(heroArray, 5);
    cout << "排序后：" << endl;
    print_Hero(heroArray);

    return 0;
}