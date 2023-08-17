#include <iostream>
#include <string>
using namespace std;

// 关系运算符重载

class Person{
public:
    Person(const string &name, const int &age) : Name(name), Age(age) {}
    bool operator==(const Person &p){   // 关系运算符 ==
        return Name==p.Name && Age==p.Age;
    }
    bool operator!=(const Person &p){   // 关系运算符 !=
        return Name!=p.Name || Age!=p.Age;
    }
private:
    string Name;
    int Age;
};

void test01(){
    Person p1("Tom", 20), p2("Tom", 20), p3("Jack", 19);
    if(p1 == p2){
        cout << "p1 == p2" << endl;
    }
    if(p1 != p3){
        cout << "p1 != p3" << endl;
    }
}

int main()
{
    test01();
    return 0;
}