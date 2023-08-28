#include <iostream>
#include <queue>
#include <string>

using namespace std;

// queue

class Person{
public:
    Person(const string &name, const int &a) : Name(name), Age(a) {}
    string Name;
    int Age;
};

void test01(){
    // 创建队列
    queue<Person> q;
    // 准备数据
    Person p1("Tom", 25), p2("Bruce", 22), p3("Charlie", 27);
    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    // 只要队列不为空，查看队头/尾，出队
    while(!q.empty()){
        // 查看队头
        cout << "队头元素 --- 姓名：" << q.front().Name << " 年龄：" << q.front().Age << endl;
        cout << "队尾元素 --- 姓名：" << q.back().Name << " 年龄：" << q.back().Age << endl;
        q.pop();
    }
    cout << "队列大小：" << q.size() << endl;   // 0
}

int main()
{
    test01();
    return 0;
}