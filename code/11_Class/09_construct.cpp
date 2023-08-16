#include <iostream>
using namespace std;

// 构造函数的分类及调用
class Person{
public:
    Person() {  // 默认构造函数(无参构造)
        cout << "Person()" << endl;
    }

    Person(int a) { // 有参构造
        Age = a;
        cout << "Person(int a)" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p){    // 将传入对象的所有属性拷贝
        Age = p.Age;
        cout << "Person(const Person &p)" << endl;
    }

    ~Person(){
        cout << "~Person()" << endl;
    }

    int Age;
};

// 调用
void test01(){
    // 1.括号法
    Person p1;   // 默认构造函数；调用默认构造函数时，不要加括号 `()`
    // Person p1();    // 编译器会认为是一个函数声明
    Person p2(10);  // 有参构造函数
    Person p3(p2);  // 拷贝构造函数
    cout << "p3.Age = " << p3.Age << endl;  // 10
    
    // 2.显式法
    Person p4 = Person(6);  // 有参构造
    Person p5 = Person(p4); // 拷贝构造
    // Person(10); // 匿名对象；特点：当前行执行结束后，系统会立即回收掉匿名对象
    // 不要用拷贝构造函数，初始化匿名对象
    // Person(p5); // 编译器会认为 Person(p5) == Person p5; 对象声明

    // 3.隐式转换法
    Person p6 = 10; // 相当于 Person p6 = Person(10);
    Person p7 = p6; // 相当于 Person p7 = Person(p6);

}

int main()
{
    test01();
    return 0;
}