#include <iostream>
using namespace std;

// 设计一个⚪类，求周长
// 周长公式：2*PI*半径
const double PI = 3.14;
class Circle{
public: // 访问权限
    double r;   // 属性
    double perimeter(){ // 行为
        return 2 * PI * r;
    }
};

int main()
{
    // 创建对象
    Circle c1;  // 实例化：通过一个类 创建一个对象的过程
    c1.r = 1;
    cout << "周长: " << c1.perimeter() << endl;

    return 0;
}