#include <iostream>
using namespace std;

// 菱形继承

// 动物类
class Animal{
public:
    int A;
};

// 利用虚继承 解决菱形继承问题
// 在继承之前，加上关键字 virtual
// Animal类称为 虚基类

class Sheep : virtual public Animal {}; // 羊类
class Tuo : virtual public Animal {};   // 驼类
class SheepTuo : public Sheep, public Tuo {};   // 羊驼类

void test01(){
    SheepTuo st;
    // st.A = 18;  // SheepTuo::A 不明确
    st.Sheep::A = 18;
    st.Tuo::A = 12;
    // 当菱形继承，两个父类拥有相同数据，需要加上作用域进行区分
    cout << "st.Sheep::A = " << st.Sheep::A << endl;    // 12
    cout << "st.Tuo::A = " << st.Tuo::A << endl;        // 12
    // 菱形数据导致数据有两份，资源浪费
    cout << "st.A = " << st.A << endl;                  // 12
}

int main()
{
    test01();
    return 0;
}