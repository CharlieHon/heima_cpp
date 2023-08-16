#include <iostream>
using namespace std;

// 深拷贝与浅拷贝
// 1. 编译器自动生成的拷贝构造函数执行 浅拷贝 操作
//      函数体在栈区，先进后出，p2先销毁，导致p1执行析构操作时出错
// 2.用户自定义拷贝

class Person{
public:
    Person(){
        cout << "Person默认构造函数" << endl;
    }

    Person(int age, int height){
        Age = age;
        Height = new int(height);   // 在堆区开辟内存
        cout << "Person有参构造函数" << endl;
    }

    // 通过自定义拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p){
        cout << "Person 拷贝构造函数" << endl;
        Age = p.Age;
        // Height = p.Height;   // 浅拷贝：编译器默认实现的就是这行代码
        
        // 深拷贝操作
        Height = new int(*p.Height);    // 重新在堆区创建内存
    }

    ~Person(){
        // 析构代码，将堆区开辟数据做释放操作
        if(Height){
            delete Height;
            Height = 0;
        }
        cout << "Person析构函数调用" << endl;
    }

    int Age;
    int *Height;
};

void test01(){
    Person p1(18, 160);
    cout << "p1.Age = " << p1.Age << " 身高 " << *p1.Height << endl;
    Person p2(p1);
    cout << "p2.Age = " << p2.Age << " 身高 " << *p2.Height << endl;
}

int main()
{
    test01();
    return 0;
}