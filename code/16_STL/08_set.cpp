#include <iostream>
#include <set>
#include <string>

using namespace std;

class MyCompare2;
class Person{
    friend MyCompare2;  // 友元类
    friend ostream& operator<<(ostream&, const Person&);
    // friend bool compare(const Person&, const Person&);
public:
    Person() = default;
    Person(const string &name, const int &age) : Name(name), Age(age) {}

private:
    string Name;
    int Age;
};

ostream& operator<<(ostream &os, const Person &p){
    os << "姓名：" << p.Name << " 年龄：" << p.Age;
    return os;
}

// bool compare(const Person &p1, const Person &p2){
//     return p1.Age > p2.Age; // 按年龄从大到小排序
// }

template<class T>
void printSet(const set<T> &st){    // set容器打印输出
    for(auto it=st.cbegin(); it!=st.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){  // set容器构造和赋值
    set<int> s1;
    // 插入数据，只有insert方式
    s1.insert(10);
    s1.insert(10);
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    // 遍历容器
    // set容器的特点：所有元素插入时会自动被排序
    // set容器不允许插入重复值
    printSet(s1);   // 10 20 30
    set<int> s2(s1);    // 拷贝构造
    set<int> s3 = s2;   // 赋值操作
}

void test02(){  // set大小和交换
    set<int> s1;
    s1.insert(20);
    s1.insert(30);
    s1.insert(10);
    s1.insert(40);
    if(!s1.empty()){
        cout << "s1.size = " << s1.size() << endl;  // 4
        printSet(s1);   // 10 20 30 40
    }else{
        cout << "s1 is empty!" << endl;
    }

    set<int> s2 = {80, 50, 60};
    printSet(s2);   // 50 60 80

    // 交换
    s1.swap(s2);
    cout << "交换后：" << endl;
    printSet(s1);   // 50 60 80
    printSet(s2);   // 10 20 30 40
}

void test03(){
    set<int> s1 = {1,9,4,9,2,0,2,3};
    printSet(s1);   // 0 1 2 3 4 9

    // 删除
    s1.erase(s1.begin());
    printSet(s1);   // 1 2 3 4 9
    // 删除的重载版本
    s1.erase(2);
    printSet(s1);   // 1 3 4 9
    s1.clear(); // 清空
    // s1.erase(s1.begin(), s1.end()); // 同上
    printSet(s1);   // 
}

void test04(){  // set查找和统计
    set<int> s1{4,7,6,4,1,1};
    // 查找
    auto iter = s1.find(6);
    if(iter!=s1.end()){
        cout << "find: " << *iter << endl;
    }else{
        cout << "Not Found!" << endl;
    }
    // 统计
    int num = s1.count(1);  // 对于set而言，统计的结果要么是0，要么是1
    cout << "num = " << num << endl;    // 1
}

void test05(){  // set容器和multiset区别
    set<int> s1;
    pair<set<int>::iterator, bool> res = s1.insert(10);  // 返回类型 pair<iterator, bool>
    if(res.second){
        cout << "第一次插入成功" << endl;   // 成功
    }else{
        cout << "第一次插入失败" << endl;
    }
    res = s1.insert(10);
    if(res.second){
        cout << "第二次插入成功" << endl;
    }else{
        cout << "第二次插入失败" << endl;   // 失败
    }

    // multiset允许插入重复值
    multiset<int> ms;
    ms.insert(10);  // 返回类型 iterator
    ms.insert(10);
    ms.insert(6);
    ms.insert(7);
    for(auto it=ms.cbegin(); it!=ms.end(); ++it){
        cout << *it << " "; // 6 7 10 10
    }
    cout << endl;
}

void test06(){  // pair对组创建
    // 第一种方式
    pair<string, int> p1("Tom", 20);
    cout << "姓名：" << p1.first << " 年龄：" << p1.second << endl;
    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

class MyCompare1{
public:
    bool operator()(const int &v1, const int &v2){
        return v1 > v2; // 从大到小
    }
};

class MyCompare2{
public:
    bool operator()(const Person &p1, const Person &p2){
        return p1.Age > p2.Age; // 按年龄从大到小
    }
};


void test07(){  // set容器排序
    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(60);
    printSet(s1);   // 10 20 50 60
    
    // 指定排序规则为从大大小
    
    // 示例一：set存放内置数据类型
    set<int, MyCompare1> s2; // 第个参数放一个用于排序的类
    s2.insert(16);
    s2.insert(20);
    s2.insert(30);
    s2.insert(10);
    // printSet(s2);   // 错误：没有与参数列表匹配的函数
    for(auto it=s2.cbegin(); it!=s2.end(); ++it){
        cout << *it << " "; // 30 20 16 10
    }
    cout << endl;

    // 示例二：set存放自定义数据类型
    set<Person, MyCompare2> s3;
    Person p1("刘备", 43), p2("关羽", 40), p3("张飞", 36), p4("黄忠", 45);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    for(auto it=s3.cbegin(); it!=s3.cend(); ++it){
        cout << *it << endl;
    }
/*
姓名：黄忠 年龄：45
姓名：刘备 年龄：43
姓名：关羽 年龄：40
姓名：张飞 年龄：36
*/
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
    return 0;
}