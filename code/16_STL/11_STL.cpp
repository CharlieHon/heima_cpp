#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 仿函数 返回类型是bool数据类型，称为谓词
/*
1.一元谓词，operator()接受一个参数
2.二元谓词，operator()接受两个参数
*/

class GreaterFive{  // 一元谓词
public:
    bool operator()(int val){   // 返回bool类型的仿函数角坐谓词
        return val > 5;
    }
};

class Compare{  // 二元谓词
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void test01(){
    vector<int> v;
    for(int i=0; i<10; ++i){
        v.push_back(i);
    }
    // 查找容器中 有没有大于5的数字
    // GreaterFive() 匿名函数对象
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if(pos == v.end()){
        cout << "未找到" << endl;
    }else{
        cout << "找到了大于5的数字为：" << *pos << endl;    // 6
    }
}

void test02(){
    vector<int> v = {10, 40, 20, 30, 50};
    sort(v.begin(), v.end());
    for(auto it=v.cbegin(); it!=v.cend(); ++it){
        cout << *it << " "; // 10 20 30 40 50
    }
    cout << endl;
    cout << "----" << endl;

    // 使用函数对象，改变算法策略，将排序规则变为从大到小
    sort(v.begin(), v.end(), Compare());    // Compare() 函数对象
    for(auto it=v.cbegin(); it!=v.cend(); ++it){
        cout << *it << " "; // 50 40 30 20 10
    }
    cout << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}