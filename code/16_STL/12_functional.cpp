#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// 内建函数对象

void test01(){  // 算术仿函数
    // negate 一元仿函数 取反仿函数
    negate<int> n;
    cout << n(50) << endl;  // -50
    // plus 二元仿函数 加法
    plus<int> add;
    cout << add(12, 9) << endl; // 21
}

void test02(){  // 关系仿函数 greater大于
    vector<int> v{4,7,6,4,1,1};
    // greater<int> g;
    // sort(v.begin(), v.end(), g);    // 从大到小排序
    sort(v.begin(), v.end(), greater<int>());
    for(auto it=v.cbegin(); it!=v.cend(); ++it){
        cout << *it << " "; // 7 6 4 4 1 1
    }
    cout << endl;
}

void test03(){  // 逻辑仿函数
    vector<bool> v{true, false, true, false};
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout << *it << " "; // 1 0 1 0
    }
    cout << endl;
    // 利用逻辑非，将容器 v 搬运到 容器 v2 中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());    // 需要先开辟空间再搬运
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    cout << "------" << endl;
    for(auto it=v2.begin(); it!=v2.end(); ++it){
        cout << *it << " "; // 0 1 0 1
    }
    cout << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}