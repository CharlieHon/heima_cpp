#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// deque

template<class T>
void printDeq(const deque<T> &deq){
    for(auto it=deq.cbegin(); it!=deq.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){  // deque容器构造

    deque<int> d1;
    for(int i=0; i<7; ++i){
        d1.push_back(i);
    }
    printDeq(d1);

    deque<int> d2(d1.begin(), d1.end());
    deque<int> d3(3, 6);    // 6 6 6
    deque<int> d4(d3);  // 拷贝构造
}

void test02(){  // deque赋值操作
    deque<int> d1;
    for(int i=0; i<7; ++i){
        d1.push_back(i);
    }

    // operator= 赋值
    deque<int> d2;
    d2 = d1;    // 0 1 2 3 4 5 6
    
    // assign 赋值
    deque<int> d3;
    d3.assign(d2.begin(), d2.end());    // 0 1 2 3 4 5 6
    
    deque<int> d4;
    d4.assign(3, 6);    // 6 6 6
}

void test03(){  // deque大小操作 
    deque<int> d1 = {2,0,2,3,2,4,6,0,3,3};
    printDeq(d1);
    if(d1.empty()){
        cout << "d1 is empty!" << endl;
    }else{
        cout << "Not empty." << endl;
    }
    cout << "d1.size() = " << d1.size() << endl;    // 10
    d1.resize(4);
    printDeq(d1);   // 2 0 2 3
    d1.resize(6, 3);    
    printDeq(d1);   // 2 0 2 3 3 3
}

void test04(){  // deque容器插入和删除操作
    
    // 在头尾插入和删除元素
    deque<int> d1;
    // 尾插
    d1.push_back(6);
    d1.push_back(7);
    printDeq(d1);   // 6 7
    // 头插
    d1.push_front(5);
    d1.push_front(3);
    printDeq(d1);   // 3 5 6 7
    // 尾删
    d1.pop_back();
    // 头删
    d1.pop_front();
    printDeq(d1);   // 5 6

    // 在指定位置删除元素
    deque<int> d2 = {4,7,6,4,1,1};
    auto it = d2.begin();
    it = d2.erase(it+1);    // 返回删除元素后面的一个元素
    printDeq(d2);   // 4 (7) 6 4 1 1
    d2.erase(it, d2.end());
    printDeq(d2);   // 4

    // 插入
    deque<int> d3 = {4,3};
    d3.insert(d3.end(), 2, 9);  // 在d3.end()前插入2个9
    printDeq(d3);   // 4 3 9 9
    d3.insert(d3.begin(), d1.begin(), d1.end());    // 按照区间进行插入
    printDeq(d3);   // 5 6 4 3 9 9

    d3.clear(); // 清空
}

void test05(){  // deque数据存取
    deque<int> d = {2,0,2,4,2,7};
    for(int i=0; i<d.size(); ++i){
        // cout << d.at(i) << " "; // 2 0 2 4 2 7
        cout << d[i] << " ";    // 同上
    }
    cout << endl;
    cout << "d.front() = " << d.front() << endl;    // 2
    cout << "d.back() = " << d.back() << endl;  // 7
}

void test06(){  // deque排序
    deque<int> d = {0,1,2,3,50,6,4};
    d.push_back(3);
    d.push_front(12);
    printDeq(d);    // 12 0 1 2 3 50 6 4 3
    // 对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    sort(d.begin(), d.end());   // 排序：默认排序规则，从小到大升序
    printDeq(d);    // 0 1 2 3 3 4 6 12 50
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    return 0;
}