#include<iostream>
using namespace std;

int main()
{
    //输入一个分数，如果分数大于600，考上一本大学
    //如果没考上，打印未考上一本
    int n;
    cout << "请输入一个考试分数:" << endl;
    cin >> n;
    cout << "您输入的分数是: " << n << endl;
    if(n > 600){
        // cout << "恭喜考上一本大学" << endl;
        if(n > 700){
            cout << "TsingHua" << endl;
        }else if(n > 689){
            cout << "Peiking" << endl;
        }else{
            cout << "TJU" << endl;
        }
    }else if(n > 500){
        cout << "恭喜考上二本大学" << endl;
    }else if(n > 400){
        cout << "恭喜考上三本大学" << endl;
    }else{
        cout << "未考上大学" << endl;
    }

    return 0;
}