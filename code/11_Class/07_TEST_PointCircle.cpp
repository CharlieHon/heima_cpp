#include <iostream>
#include <string>
using namespace std;
// 点和圆关系案例

class Point{    // 点类
public:
    // 设置X
    void setP(const int &x, const int &y){
        X = x;
        Y = y;
    }
    int getX() const {
        return X;
    }
    int getY() const {
        return Y;
    }

private:
    int X;
    int Y;
};

class Circle{   // 圆类
public:
    // 设置半径
    void setR(const int &r){
        R = r;
    }
    // 获取半径
    int getR() const {
        return R;
    }
    // 设置圆心
    void setO(const Point &center){
        O = center;
    }
    // 获取圆心
    Point getCenter() const {
        return O;
    }

private:
    int R;  // 半径
    // 在类中可以让另一个类，作为本类的成员
    Point O; // 圆心
};

// 判断点和圆关系
void isInCircle(const Circle &c, const Point &p){
    // 计算两点之间的距离 平方
    int d1 = (c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX())
            + (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());
    // 计算半径的平方
    int d2 = c.getR() * c.getR();
    // 判断
    if(d1 == d2){
        cout << "点在圆上" << endl;
    }else if(d1 < d2){
        cout << "点在圆内" << endl;
    }else{
        cout << "点在圆外" << endl;
    }
}

int main()
{
    // 圆心
    Point center;
    center.setP(10, 0);
    // 圆
    Circle c;
    c.setR(10);
    c.setO(center);

    // 点
    Point p1, p2, p3;
    p1.setP(10, 10);
    p2.setP(10, 11);
    p3.setP(10, 0);

    isInCircle(c, p1);  // 点在圆上
    isInCircle(c, p2);  // 点在圆外
    isInCircle(c, p3);  // 点在圆内


    return 0;
}