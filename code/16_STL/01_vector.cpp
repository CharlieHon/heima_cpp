#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector容器

class Person{
public:
    Person() = default;
    Person(const string &name, const int &age) : Name(name), Age(age) {}

    string Name;
    int Age;
};

void test01(){
    vector<Person> v;
    Person p1("A", 20), p2("B", 26), p3("C", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 遍历容器中的数据
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); ++it){
        cout << "姓名：" << it->Name << " 年龄：" << it->Age << endl;
    }
}

void test02(){  // 嵌套容器
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1, v2, v3, v4, v5;
    for(int i=0; i<5; ++i){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
        v5.push_back(i+5);
    }
    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    // 通过大容器，把所有容器遍历一遍
    for(vector<vector<int>>::iterator it=v.begin(); it!=v.end(); ++it){
        auto it1 = it->begin(); // vector<int>::iterator
        while(it1 != it->end()){
            cout << *it1 << " ";
            ++it1;
        }
        cout << endl;
    }
}

void printVec(int val){
    cout << val << endl;
}

int main()
{
    // 创建一个vector容器，数组
    vector<int> v1;

    // 向容器中插入数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    // 通过迭代器访问容器中的数据
    // vector<int>::iterator it = v1.begin();  // 起始迭代器，指向容器中第一个元素

    // 第一种遍历方式
    // while(it != v1.end()){  // v1.end()返回尾后迭代器，指向最后一个元素的下一个位置
    //     cout << *it << endl;
    //     ++it;
    // }

    // 第二种遍历
    // for(vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it){
    //     cout << *it << endl;
    // }

    // 第三种遍历方式，利用STL提供的遍历算法
    for_each(v1.begin(), v1.end(), printVec);

    // vector存放自定义数据类型
    test01();

    // 容器嵌套容器
    test02();
/*
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
*/

    return 0;
}