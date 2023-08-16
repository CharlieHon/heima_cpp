#include <iostream>
using namespace std;

// 拷贝构造函数调用时机
// 1.使用一个已经创建完毕的对象来初始化一个新对象
// 2.值传递的方式给函数参数传值
// 3.值方式返回局部对象

class Person{
public:
    Person(){
        cout << "Person默认构造函数" << endl;
    }

    Person(int age){
        Age = age;
        cout << "Person有参构造函数" << endl;
    }

    Person(const Person &p){
        Age = p.Age;
        cout << "Person拷贝构造函数" << endl;
    }

    ~Person(){
        cout << "Person析构函数调用" << endl;
    }

int Age;
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01(){
    Person p1(20);
    Person p2(p1);  // 拷贝
}

// 2.值传递的方式给函数参数传值
void doWork(Person p){}
void test02(){
    Person p;
    doWork(p);  // 值传递
}

// 3.值方式返回局部对象
Person doWork2(){
    Person p1;
    cout << "doWork2()" << endl;
    return p1;  // 返回p1的拷贝
}
void test03(){
    cout << "test03()" << endl;
    Person p = doWork2();
    cout << "test03()结束" << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}