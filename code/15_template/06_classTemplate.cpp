#include <iostream>
#include <string>
using namespace std;

// 类模板
template<class NameType, class AgeType = int>   // 类模板的模板参数列表中可以有默认参数
class Person{
public:
    Person(NameType name, AgeType age) : Name(name), Age(age) {}
    void showInfo() const{
        cout << "name: " << Name
            << ", age: " << Age << endl;
    }
    NameType Name;
    AgeType Age;
};

void test01(){
    Person<string, int> p1("Tom", 21);
    p1.showInfo();  // name: Tom, age: 21
}

// 类模板与函数模板区别
// 1.类模板没有自动类型推导使用方式
void test02(){
    // Person s("Charlie", 18);    // 错误：无法用自动类型推导
    Person<string, int> s("Charlie", 18);   // 正确
    s.showInfo();

}
// 2.类模板在模板菜蔬列表中可以有默认参数
void test03(){
    Person<string> p("Tom", 16);
    p.showInfo();
}

int main()
{
    // test01();
    test02();
    test03();
    return 0;
}