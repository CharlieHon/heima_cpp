#include<iostream>
using namespace std;

int main()
{
    //break使用场景
    //1、switch语句中
    cout << "请选择游戏模式：" << endl;
    cout << "1、简单" << endl;
    cout << "2、普通" << endl;
    cout << "3、困难" << endl;
    int select = 0;
    cin >> select;
    switch(select){
        case 1:
            //简单模式
            cout << "游戏模式：简单" << endl;
            break;
        case 2:
            //普通模式
            cout << "游戏模式：普通" << endl;
            break;
        case 3:
            //困难模式
            cout << "游戏模式：困难" << endl;
            break;
        default:
            break;
    }
    //2、出现在循环语句中
    for(int i=0; i<10; ++i){
        if(i == 5)
            break;  //退出循环
        cout << i << endl;
    }

    //3、在嵌套循环语句中
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            if(j ==5)
                break;  //退出内层循环
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}