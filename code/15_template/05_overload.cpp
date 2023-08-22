#include <iostream>
#include <string>
using namespace std;

// 模板的局限性
// 模板不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

class Person{
public:
    Person(const string &n, const int &a) : Name(n), Age(a) {}

    string Name;
    int Age;
};

// 对比两个数据是否相等函数
template<class T>
bool myCompare(T &a, T &b){
    return a == b;
}

// 利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person &p1, Person &p2){
    return p1.Name==p2.Name && p1.Age==p2.Age;
}

void test01(){
    int a = 10, b = 20;
    bool res = myCompare(a, b);
    if(res){
        cout << "a == b" << endl;
    }else{
        cout << "a != b" << endl;
    }
}

void test02(){
    Person p1("Tom", 12), p2("Tom", 10);
    bool res = myCompare(p1, p2);
    if(res){
        cout << "p1 == p2" << endl;
    }else{
        cout << "p1 != p2" << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}