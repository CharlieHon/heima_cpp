#include <iostream>
#include <string>

using namespace std;

// 案例1：立方体
// 1.创建立方体类
// 2.设计属性
// 3.设计行为 获取立方体面积和体积
// 4.分别用全局函数和成员函数 判断两个立方体是否相等

class Cube{
public:
    // 设置长宽高
    void setCube(const int &l, const int &w, const int &h){
        L = l;
        W = w;
        H = h;
    }
    int getL() const {return L;}
    int getW() const {return W;}
    int getH() const {return H;}
    // 获取立方体面积
    int getS(){
        return 2*L*W + 2*L*H + 2*W*H;
    }
    // 获取立方体体积
    int getV(){
        return L*W*H;
    }

    // 通过成员函数判断两个立方体是否相等
    bool IsEqual(const Cube &c2){
        if(L==c2.getL() && W==c2.getW() && H==c2.getH()){
            return true;
        }
        return false;
    }

private:
    int L;  // 长
    int W;  // 宽
    int H;  // 高
};

// 利用全局函数判断 两个立方体是否相等
bool isEqual(const Cube &c1, const Cube &c2){
    if(c1.getL()==c2.getL() && c1.getH()==c2.getH() && c1.getW()==c2.getW()){
        return true;
    }
    return false;
}

int main()
{
    Cube c1;
    c1.setCube(10, 10, 10);
    cout << "面积: " << c1.getS() << endl;  // 600
    cout << "体积: " << c1.getV() << endl;  // 1000

    Cube c2;
    c2.setCube(10, 10, 10);

    if(isEqual(c1, c2)){    // 全局函数
        cout << "全局函数: c1和c2相等" << endl;
    }else{
        cout << "全局函数: c1和c2不相等" << endl;
    }

    if(c1.IsEqual(c2)){     // 成员函数
        cout << "成员函数: c1和c2相等" << endl;
    }else{
        cout << "成员函数: c1和c2不相等" << endl;
    }

    return 0;
}