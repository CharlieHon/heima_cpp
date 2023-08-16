#include <iostream>
#include <string>
using namespace std;

// 访问权限
// 三种
// 公共权限 public      成员在类内和类外都可以访问
// 保护权限 protected   类内可以访问，类外不可；子类可以访问父类保护内容
// 私有权限 private     类内可以访问，类外不可；子类不可以父类私有内容

class Person{
public: // 公共权限
    string Name;    // 姓名
protected:  // 保护权限
    string Car; // 汽车
private:    // 私有权限
    string Password;    // 密码

public:
    void set(){ // 类内都可以访问
        Name = "张三";
        Car = "拖拉机";
        Password = "123456";
    }
};

int main()
{
    Person p1;  // 实例化对象
    p1.Name = "李四";   // 公有属性可以类外访问
    // p1.Car = "大众";    // 错误：类外不可以访问保护权限内容
    // p1.Password = "0000";   // 错误：类外不可以访问私有权限内容
    p1.set();

    return 0;
}