#include <iostream>
using namespace std;

// 多态案例二-制作饮品
class Abstract{
public:
    virtual void Boil() = 0;    // 煮水
    virtual void Brew() = 0;    // 冲泡
    virtual void PourInCup() = 0;       // 倒入杯中
    virtual void PutSomething() = 0;    // 加入辅料
    void makeDrink(){   // 制作饮品
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee : public Abstract{
public:
    virtual void Boil(){
        cout << "Boil: 农夫山泉" << endl;
    }
    virtual void Brew(){
        cout << "Brew: 冲泡咖啡" << endl;
    }
    virtual void PourInCup(){
        cout << "PourInCup: 倒入杯中" << endl;
    }
    virtual void PutSomething(){
        cout << "PutSomething: 加点卡布奇诺" << endl;
    }
};

class Tea : public Abstract{
public:
    virtual void Boil(){
        cout << "Boil: 矿泉水" << endl;
    }
    virtual void Brew(){
        cout << "Brew: 冲泡茶叶" << endl;
    }
    virtual void PourInCup(){
        cout << "PourInCup: 倒入杯中" << endl;
    }
    virtual void PutSomething(){
        cout << "PutSomething: 加点枸杞" << endl;
    }
};

// 制作函数
void doWork(Abstract *abs){
    abs->makeDrink();
    delete abs; // 释放内存
}

void test01(){
    // 制作咖啡
    doWork(new Coffee);
    cout << "--------" << endl;
    // 制作茶叶
    doWork(new Tea);
}

int main()
{
    test01();
/*
Boil: 农夫山泉
Brew: 冲泡咖啡
PourInCup: 倒入杯中
PutSomething: 加点卡布奇诺
Boil: 矿泉水
Brew: 冲泡茶叶
PourInCup: 倒入杯中
PutSomething: 加点枸杞
*/
    return 0;
}