#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void print01(int val){
    cout << val << " ";
}

class print02{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

class Transform{
public:
    int operator()(int val){
        return val*val;
    }
};

class Person{
public:
    Person() = default;
    Person(const string &name, const int &age) : Name(name), Age(age) {}
    bool operator==(const Person &rhs) const{
        // return this->Name==rhs.Name && this->Age==rhs.Age;  // 使用find查找，需要重载==
        return this->Age == rhs.Age;    // count统计年龄相同的人员个数
    }
    string Name;
    int Age;
};

class GreaterFive{
public:
    bool operator()(int val){   // 返回大于5的值
        return val > 5;
    }
};

class Greater30{
public:
    bool operator()(Person &p){   // 年龄大于30
        return p.Age > 30;
    }
};

template<class T>
void printVec(const vector<T> &v){  // 打印输出vector容器
    for(auto it=v.cbegin(); it!=v.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){  // 遍历算法 for_each
    vector<int> v;
    for(int i=0; i<10; ++i){
        v.push_back(i);
    }
    // for_each(v.begin(), v.end(), print01);   // 0 1 2 3 4 5 6 7 8 9
    for_each(v.begin(), v.end(), print02());    // 同上
}

void test02(){  // 遍历算法 transform
    vector<int> v{0,1,2,3};
    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), print01);    // 0 1 4 9
}

void test03(){  // 查找算法：find
    // 查找内置数据类型
    vector<int> v{0,1,2,3,4,5,6,7,8,9,10};
    int val = 5;
    auto pos1 = find(v.begin(), v.end(), val);
    if(pos1 == v.end()){
        cout << "Not Found!" << endl;
    }else{
        cout << "Find: " << *pos1 << endl;  // 5
    }
    
    // 查找自定义数据类型
    Person p1("Tom", 21), p2("Jeff", 28), p3("Bruce", 30), p4("Charlie", 23);
    vector<Person> v3{p1, p2, p3, p4};
    Person pp("Jeff", 28);
    auto pos2 = find(v3.begin(), v3.end(), pp);
    if(pos2 == v3.end()){
        cout << "Not Found!" << endl;
    }else{
        cout << "Find: " << pos2->Name << " " << pos2->Age << endl; // Jeff 28
    }
}

void test04(){  // 查找 find_if
    // 1.查找内置数据类型
    vector<int> v{0,1,2,3,4,5,6};
    auto pos1 = find_if(v.begin(), v.end(), GreaterFive());
    if(pos1 == v.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Find " << *pos1 << " > 5." << endl;    // 6
    }

    // 2.查找自定义数据类型
    Person p1("Tom", 21), p2("Jeff", 28), p3("Bruce", 31), p4("Charlie", 23);
    vector<Person> v2{p1, p2, p3, p4};
    // 找年龄大于30的人
    auto pos2 = find_if(v2.begin(), v2.end(), Greater30());
    if(pos2 == v2.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Find " << pos2->Name << " > 30." << endl;  // Bruce
    }
}

void test05(){  // 查找相邻重复元素 adjacent_find
    vector<int> v{4,7,6,4,1,1};
    auto pos = adjacent_find(v.begin(), v.end());
    if(pos != v.end()){
        cout << "找到相邻重复元素：" << *pos << endl;   // 1
    }else{
        cout << "Not Found!" << endl;
    }
}

void test06(){  // binary_search
    vector<int> v{1,8,9,5,2,0,2,3};
    sort(v.begin(), v.end());   // 容器必须是有序序列，否则结果不可靠
    bool flag = binary_search(v.begin(), v.end(), 5);
    if(flag){
        cout << "Found!" << endl;
    }else{
        cout << "Not Found!" << endl;
    }
}

void test07(){  // count
    // 1.统计内置数据类型
    vector<int> v{4,7,6,4,1,1,0,0};
    int num1 = count(v.begin(), v.end(), 7);
    cout << "7的元素个数是：" << num1 << endl;  // 1
    // 2.统计自定义数据类型
    Person p1("Tom", 21), p2("Charlie", 23), p3("Bruce", 30), p4("Jeff", 23);
    vector<Person> v2{p1, p2, p3, p4};
    Person pp("Lee", 23);
    auto num2 = count(v2.begin(), v2.end(), pp);    // 统计与pp年龄相同的人员个数
    cout << "与 " << pp.Name << " 年龄相同的人数有 " << num2 << endl;   // 2
}

void test08(){  // count_if
    // 1.内置数据类型
    vector<int> v{4,7,6,4,1,1};
    auto num1 = count_if(v.begin(), v.end(), GreaterFive());    // 统计大于5的个数
    cout << "大于5的个数有：" << num1 << endl;  // 2
    // 2.自定义数据类型
    Person p1("Tom", 21), p2("Charlie", 66), p3("Bruce", 30), p4("Jeff", 23);
    vector<Person> v2{p1, p2, p3, p4};
    auto num2 = count_if(v2.begin(), v2.end(), Greater30());    // 年龄大于30的人员个数
    cout << "30多岁的人有：" << num2 << endl;   // 1
}

void test09(){
    // sort
    vector<int> v1{1,3,5,7,6,2,0};
    sort(v1.begin(), v1.end());
    printVec(v1);   // 0 1 2 3 5 6 7
    // sort降序排序
    sort(v1.begin(), v1.end(), greater<int>());
    printVec(v1);   // 7 6 5 3 2 1 0

    // random_shuffle
    vector<int> v2{0,1,2,3,4,5,6,7,8,9};
    srand((unsigned)time(NULL));
    random_shuffle(v2.begin(), v2.end());
    printVec(v2);   // 8 1 9 2 0 5 7 3 4 6

    // merge    两个容器必须是有序的，合并后仍有序
    vector<int> v3{1,2,3}, v4{7,8,9}, dest;
    // 目标容器需要提前开辟空间
    dest.resize(v3.size()+v4.size());
    merge(v3.begin(), v3.end(), v4.begin(), v4.end(), dest.begin());
    for_each(dest.begin(), dest.end(), print01);    // 1 2 3 7 8 9
    cout << endl;

    // reverse
    vector<int> v5{1,8,9,5,2,0,2,3};
    reverse(v5.begin(), v5.end());
    printVec(v5);   // 3 2 0 2 5 9 8 1
}

void test10(){  // 常用拷贝和替换算法
    // copy
    vector<int> v1(3,6), dest;
    dest.resize(v1.size());
    copy(v1.begin(), v1.end(), dest.begin());
    printVec(dest); // 6 6 6

    // replace
    vector<int> v2{3,2,1,5,7,9,5,6};
    replace(v2.begin(), v2.end(), 5, 50);    // 将所有5替换为6
    printVec(v2);   // 3 2 1 50 7 9 50 6

    // replace_if
    vector<int> v3{2,5,8,3,6,1,3};
    replace_if(v3.begin(), v3.end(), GreaterFive(), 0); // 将大于5的数替换为0
    printVec(v3);   // 2 5 0 3 0 1 3

    // swap
    vector<int> v4{1,8,9,5}, v5{2,0,0,1,1,2,2,0};
    swap(v4, v5);
    printVec(v4);   // 2 0 0 1 1 2 2 0
    printVec(v5);   // 1 8 9 5
}

void test11(){  // 算术生成算法
    // accumulate
    vector<int> v1;
    for(int i=1; i<=100; ++i){
        v1.push_back(i);
    }
    cout << "Sum from 1 to 100 is " << accumulate(v1.begin(), v1.end(), 0) << endl; // 5050

    // fill
    vector<int> v2{0,1,2,3,4,5,6,7};
    fill(v2.begin(), v2.end(), 1);  // 1 1 1 1 1 1 1 1
    printVec(v2);
}

void test12(){  // 常用集合算法
    vector<int> v1{1,2,3,4,5}, v2{3,4,5,6,7};
    vector<int> dest1, dest2, dest3;    // 求交/并/差集的目标容器
    // set_intersection 交集
    dest1.resize(min(v1.size(), v2.size()));    // 取交集的特殊情况是其中一个完全包含于另一个
    // 返回最后交集结束的位置迭代器
    auto pos1 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), dest1.begin());
    // pos1为目标容器中指向交集尾后的迭代器
    for_each(dest1.begin(), pos1, print01); // 3 4 5 开始开辟的空间可能过大，导致容器中产生多余的0
    cout << endl;
    // printVec(dest1);    // 3 4 5 0 0

    // set_union    并集
    dest2.resize(v1.size()+v2.size());
    auto pos2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), dest2.begin());
    for_each(dest2.begin(), pos2, print01); // 1 2 3 4 5 6 7
    cout << endl;
    // printVec(dest2);    // 1 2 3 4 5 6 7 0 0 0

    // set_difference   差集
    // v1和v2的差集是v1中不在v2中的元素
    // v2和v1的差集是v2中不在v1中的元素
    dest3.resize(max(v1.size(), v2.size()));
    auto pos3 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), dest3.begin());
    for_each(dest3.begin(), pos3, print02());   // 1 2
    cout << endl;
    // printVec(dest3);    // 1 2 0 0 0
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    // test09();
    // test10();
    // test11();
    test12();
    return 0;
}