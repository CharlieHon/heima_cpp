#include <iostream>
#include <string>
using namespace std;

// 类对象作为类成员
class Phone{
public:
    Phone(const string &s) : PName(s)   {   cout << "Phone构造函数" << endl;}
    ~Phone() {  cout << "Phone析构函数" << endl;}
    string PName;
};

class Person{
public:
    // Phone P = PName; // 隐式转换法
    Person(const string name, const string PName) : Name(name), P(PName)    {   cout << "Person构造函数" << endl;}
    ~Person() { cout << "Person析构函数" << endl;}

    // 姓名
    string Name;
    // 手机
    Phone P;
};

// 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构顺序与构造顺序相反
// 当对象销毁时，先销毁本对象，再销毁类对象
void test01(){
    Person p1("张三", "iPhone18");  // 先构造Phone对象，然后构造Person对象
    cout << p1.Name << " 拿着：" << p1.P.PName << endl;
}

int main()
{
    test01();

    return 0;
}