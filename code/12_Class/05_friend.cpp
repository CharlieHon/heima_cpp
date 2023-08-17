#include <iostream>
#include <string>
using namespace std;

// 全局函数做友元

class Building{
    friend void func1(const Building &b);   // func1全局函数是Building的友元函数，可以访问Building中私有成员
public:
    Building(){
        SittingRoom = "客厅";
        BedRoom = "卧室";
    }
    string SittingRoom; // 客厅
private:
    string BedRoom; // 卧室
};

// 全局函数
void func1(const Building &b){
    cout << "func1正在访问 " << b.SittingRoom << endl;
    cout << "func1正在访问 " << b.BedRoom << endl;
}

void test01(){
    Building b;
    func1(b);
}

int main()
{
    test01();
    return 0;
}