#include <iostream>
#include <string>

using namespace std;

// 类模板对象做函数参数
template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age) : Name(name), Age(age) {}
    void showInfo() const{
        cout << "name: " << Name
            << ", age: " << Age << endl;
    }
    T1 Name;
    T2 Age;
};

// 1.指定传入类型
void printPerson1(Person<string, int> &p){
    p.showInfo();
}
void test01(){
    Person<string, int> p("MonkeySun", 100);
    printPerson1(p);
}

// 2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
    p.showInfo();
    cout << "T1的类型为: " << typeid(T1).name() << endl;
    cout << "T2的类型为: " << typeid(T2).name() << endl;
}
void test02(){
    Person<string, int> p("PigZhu", 100);
    printPerson2(p);
}

// 3.整个类模板化
template<class T>
void printPerson3(T &p){
    p.showInfo();
}
void test03(){
    Person<string, int> p("唐僧", 19);
    printPerson3(p);
    cout << "p的数据类型: " << typeid(p).name() << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}