#include <iostream>
#include <map>
#include <string>

using namespace std;

template<class T1, class T2>
void printMap(map<T1, T2> &mp){   // 打印输出map容器
    for(auto it=mp.cbegin(); it!=mp.cend(); ++it){
        cout << "key: " << (*it).first << " value: " << it->second << endl;
    }
    cout << endl;
}

void test01(){  // map容器构造和赋值
    map<int, int> m;    // 创建map容器
    m.insert(pair<int, int>(1, 10));    // 插入数据
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
/*
key: 1 value: 10
key: 2 value: 20
key: 3 value: 30
key: 4 value: 40
*/
    map<int, int> m2(m);    // 拷贝构造
    map<int, int> m3 = m;   // 赋值操作
}

void test02(){  // map容器大小和交换
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));
    if(m1.empty()){
        cout << "m1 is empty!" << endl;
    }else{
        cout << "m1.size = " << m1.size() << endl;  // 3
    }

    // 交换
    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));
    m1.swap(m2);
    cout << "交换后：" << endl;
    printMap(m1);
    printMap(m2);
/*
key: 4 value: 100
key: 5 value: 200
key: 6 value: 300

key: 1 value: 10
key: 2 value: 20
key: 3 value: 30
*/
}

void test03(){  // map容器 插入和删除
    map<int, int> m;
    // 插入：方式一
    m.insert(pair<int, int>(1, 10));
    // 插入：方式二
    m.insert(make_pair(2, 60));
    // 插入：方式三
    m.insert(map<int, int>::value_type(3, 30));
    // 插入：方式四
    m[4] = 40;
    // []不建议插入，可以用key访问到value
    // cout << m[5] << endl;   // 0 当map中没有键为5的对时，会自动创建一个
    printMap(m);    // (1,10) (2,60), (3,30) (4,40)

    // 删除
    m.erase(m.begin());
    printMap(m);    // (2,60) (3,30) (4,40)
    m.erase(3); // 按照key删除，没有也不会报错
    printMap(m);    // (2,60) (4,40)
    // m.erase(m.begin(), m.end());
    m.clear();  // 效果同上
}

void test04(){  // map查找和统计
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 5));
    m.insert(make_pair(3, 6));
    m.insert(make_pair(3, 60)); // 并没有插入进去
    map<int, int>::iterator pos = m.find(3);
    if(pos != m.end()){
        cout << "查到了元素 key = " << pos->first << " value = " << (*pos).second << endl;
        // 查到了元素 key = 3 value = 6
    }else{
        cout << "Not Found!" << endl;
    }

    // 统计
    // map不允许插入重复key元素，count结果要么为0，要么为1
    // multimap可能大于1
    int num = m.count(3);
    cout << "num = " << num << endl;    // 1
}

class MyCompare1{
public:
    bool operator()(const int &v1, const int &v2){
        return v1 > v2; // 按照值从大到小排序
    }
};

void test05(){  // map容器排序
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(5, 50));
    m.insert(make_pair(4, 40));
    printMap(m);
/*
key: 1 value: 10
key: 2 value: 20
key: 3 value: 30
key: 4 value: 40
key: 5 value: 50
*/

    map<int, int, MyCompare1> m2;
    m2.insert(make_pair(1, 10));
    m2.insert(make_pair(2, 20));
    m2.insert(make_pair(3, 30));
    m2.insert(make_pair(5, 50));
    m2.insert(make_pair(4, 40));
    for(auto it=m2.cbegin(); it!=m2.cend(); ++it){
        cout << "key: " << it->first << " value:" << (*it).second << endl;
    }
/*
key: 5 value:50
key: 4 value:40
key: 3 value:30
key: 2 value:20
key: 1 value:10
*/
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    return 0;
}
