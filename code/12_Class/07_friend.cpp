#include <iostream>
#include <string>
using namespace std;

// 成员函数做友元
class Building;
class Person{
public:
    Person();
    void visit();   // 让visit函数可以访问Building中私有成员
    Building *building;
};

class Building{
    friend void Person::visit();    // Person的成员函数visit作为友元
public:
    Building();
    string SittingRoom;
private:
    string BedRoom;
};

Building::Building(){
    SittingRoom = "客厅";
    BedRoom = "卧室";
}

Person::Person(){
    building = new Building;
}

void Person::visit(){
    cout << "Person::visit()正在访问: " << building->SittingRoom << endl;
    cout << "Person::visit()正在访问: " << building->BedRoom << endl;
}

void test01(){
    // Building b;
    Person p;
    p.visit();
    cout << "Person对象正在访问: " << p.building->SittingRoom << endl;
    // cout << "Person对象正在访问: " << p.building->BedRoom << endl;   // 错误：Person对象无法访问Building的私有成员
}

int main()
{
    test01();
    return 0;
}