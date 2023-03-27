#include<iostream>
using namespace std;

int main()
{
    //for循环，打印数字0~9
    for(int i=0; i<10; ++i){
        cout << i << endl;
    }

    //敲桌子案例
    for(int i=1; i<=100; ++i){
        if((i%7==0) || (i%10==7) || (i/10==7)){
            cout << "敲桌子" << endl;
        }else{
            cout << i << endl;
        }
    }

    //外层循环；外层执行一次，内层执行一周
    for(int i=0; i<10; ++i){
        //内层循环
        for(int j=0; j<10; ++j){
            cout << "* ";
        }
        cout << endl;
    }

    //九九乘法表
    for(int i=1; i<=9; ++i){    //行数
        for(int j=1; j<=i; ++j){    //列数
            cout << j << "*" << i << "=" << j*i << "\t";
            if(j == i)
                cout << endl;
        }
    }

    return 0;
}