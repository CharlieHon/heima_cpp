#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    //while循环
    //在屏幕中打印0~9，这10个数字
    int num = 0;
    while(num < 10){
        cout << num++ << endl;
    }

    //添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int)time(NULL));

    //1、系统生成随机数(0~100)
    int x = rand() % 100 + 1;   //生成[0, 99] + 1之间的随机数
    // cout << "x = " << x << endl;
    int val = 0, i = 0;
    while(true){
        //2、玩家输入猜测数值
        cin >> val;
        if(val > x){
            cout << "过大" << endl;
        }else if(val < x){
            cout << "过小" << endl;
        }else{
            //3、猜对退出循环
            cout << "猜对了" << endl;
            break;  //break退出当前循环
        }
        ++i;
        if(i > 6){
            cout << "错误超过6次 游戏结束!" << endl;
            break;
        }
    }

    return 0;
}