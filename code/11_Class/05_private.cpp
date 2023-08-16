#include <iostream>
#include <string>
using namespace std;

// 将成员属性设置为私有
class Person{
public:
    Person() = default;
    Person(const string name, const int &age, const string &gender) : Name(name), Age(age), Gender(gender) {}
    void setName(const string &name){   // 设置姓名
        Name = name;
    }
    void setAge(const int &age){    // 设置年龄
        if(age<0 || age>150){
            cout << "Invalid!" << endl;
            Age = 0;
            return;
        }
        Age = age;
    }
    void get(){ // 获取姓名和年龄
        cout << "姓名: " << Name
        << " 年龄: " << Age << endl;
    }
    void getGender(){   // 获取性别
        cout << "性别: " << Gender << endl;
    }

private:
    string Name;    // 可读可写
    int Age;        // 可读可写
    string Gender;  // 只读
};

int main()
{
    Person p1("李四", 25, "男");
    p1.setAge(30);
    p1.get();
    p1.getGender();

    return 0;
}