#include <iostream>
#include <vector>

using namespace std;

// vector

template<class T>
void printVec(const vector<T> &vec){    // vector打印函数
    for(auto it=vec.begin(); it!=vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){  // vector容器构造

    vector<int> v1; // 默认构造函数
    for(int i=0; i<10; ++i){
        v1.push_back(i);
    }
    printVec(v1);   // 0 1 2 3 4 5 6 7 8 9

    vector<int> v2(v1.begin(), v1.end());   // 通过区间方式进行构造
    printVec(v2);

    vector<int> v3(3, 6);   // 通过n个elem方式构造
    printVec(v3);   // 666

    vector<int> v4(v3); // 拷贝构造
    printVec(v4);   // 666
}

void test02(){  // vector赋值操作

    vector<int> v1;
    for(int i=0; i<6; ++i){
        v1.push_back(i);
    }
    printVec(v1);   // 0 1 2 3 4 5

    vector<int> v2 = v1;    // =赋值
    printVec(v2);

    vector<int> v3, v4;
    v3.assign(v1.begin(), v1.end());
    printVec(v3);

    v4.assign(3, 6);
    printVec(v4);   // 666
}

void test03(){  // vector容量和大小
    vector<int> v1 = {1,9,4,9,2,0,2,3};
    printVec(v1);
    if(!v1.empty()){
        cout << "v1非空" << endl;
    }else{
        cout << "vector is empty!" << endl;
    }
    // vector的容量始终大于等于其大小
    cout << "vector的大小是: " << v1.size() << endl;    // 8
    cout << "vector的容量是: " << v1.capacity() << endl;    // 8
    // 重新指定大小
    v1.resize(4);   // 超出部分会被删除掉
    printVec(v1);   // 1 9 4 9
    v1.resize(8, 1);    // v1.resize(8);    // 1 9 4 9 0 0 0 0 (默认填充值为0)
    printVec(v1);   // 1 9 4 9 1 1 1 1
}

void test04(){  // vector插入和删除
    vector<int> v1{1,9,4,9,1,9,7};
    
    // 尾插
    v1.push_back(8);
    v1.push_back(6);
    printVec(v1);   // 1 9 4 9 1 9 7 8 6
    
    // 尾删
    v1.pop_back();  // 1 9 4 9 1 9 7 8
    
    // 插入
    v1.insert(v1.begin(), 100);
    printVec(v1);   // 100 1 9 4 9 1 9 7 8
    v1.insert(v1.begin(), 3, 6);
    printVec(v1);   // 6 6 6 100 1 9 4 9 1 9 7 8
    
    // 删除
    v1.erase(v1.begin());
    printVec(v1);   // 6 6 100 1 9 4 9 1 9 7 8
    v1.erase(v1.begin(), v1.begin()+3);
    printVec(v1);   // 1 9 4 9 1 9 7 8
    v1.clear(); // 清空
}

void test05(){  // vector容器的数据存取
    vector<int> v1{2,0,0,1};
    for(int i=0; i<v1.size(); ++i){
        // cout << v1[i] << " ";
        cout << v1.at(i) << " ";    // 2 0 0 1
    }
    cout << endl;
    cout << "v1.front() = " << v1.front() << endl;  // 2
    cout << "v1.back() = " << v1.back() << endl;    // 1
}

void test06(){  // vector互换容器
    vector<int> v1{2,0,1,9}, v2{2,0,2,3};
    v1.swap(v2);    // 将两个容器中的元素互换，即v1和v2中元素互换
    printVec(v1);   // 2 0 2 3
    printVec(v2);   // 2 0 1 9

    // 巧用swap可以收缩内存空间
    vector<int> v3;
    for(int i=0; i<1000; ++i){
        v3.push_back(i);
    }
    cout << "v3.capacity() = " << v3.capacity() << endl;    // 1024
    cout << "v3.size() = " << v3.size() << endl;    // 1000
    v3.resize(6);
    cout << "v3.capacity() = " << v3.capacity() << endl;    // 1024
    cout << "v3.size() = " << v3.size() << endl;    // 6
    // 
    cout << "使用swap收缩内存空间: " << endl;
    vector<int>(v3).swap(v3);   // vector<int>(v3); // 匿名对象
    cout << "v3.capacity() = " << v3.capacity() << endl;    // 6
    cout << "v3.size() = " << v3.size() << endl;    // 6
}

void test07(){  // vector预留空间
    vector<int> v;
    int num = 0;    // 统计开辟次数
    int *p = 0;
    v.reserve(100000); // 预留空间 -> 1
    for(int i=0; i<100000; ++i){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];  // 当开辟新内存空间时，容器首地址也会发生改变
            ++num;
        }
    }
    cout << "一共开辟了 " << num << " 次内存空间！" << endl;    // 1    不预留空间 -> 18
    
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