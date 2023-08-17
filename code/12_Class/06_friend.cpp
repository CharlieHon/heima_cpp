#include <iostream>
#include <string>
using namespace std;

// 类做友元
class Building;
class Person{
public:
    Person();
    void visit();   // 参观函数，访问Building中的属性
    Building *building;
};

class Building{
    friend class Person;    // 友元类，可以访问本类的成员函数
public:
    Building();
    string SittingRoom; // 客厅
private:
    string BedRoom; // 卧室
};

// 类外写成员函数
Building::Building(){
    SittingRoom = "客厅";
    BedRoom = "卧室";
}

// Person类成员函数
Person::Person(){
    // 创建建筑物对象
    building = new Building;
}
void Person::visit(){
    cout << "Person类正在访问: " << building->SittingRoom << endl;
    cout << "Person类正在访问: " << building->BedRoom << endl;
}

void test01(){
    Person p;
    p.visit();
}

int main()
{
    test01();
    return 0;
}