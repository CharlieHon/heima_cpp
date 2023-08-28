#include <iostream>
#include <list>

using namespace std;

// list

template<class T>
void printList(const list<T> &lst){ // 打印list容器
    for(auto it = lst.cbegin(); it != lst.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

bool compare(int a, int b){ // 排序规则
    // 降序，就让第一个数 > 第二个数
    return a > b;
}

void test01(){  // list构造
    list<int> l1;   // 默认构造
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);  // 10 20 30 40
    list<int> l2(l1.begin(), l1.end()); // 区间构造
    list<int> l3(l2);   // 拷贝构造
    list<int> l4(3, 6); // 6 6 6
    printList(l4);
}

void test02(){  // list赋值和交换
    // 赋值
    list<int> l1 = {2, 0, 2, 3}, l2, l3, l4, l5;
    printList(l1);  // 2 0 2 3
    
    l2 = l1;
    printList(l2);  // 2 0 2 3
    
    l3.assign(l2.begin(), l2.end());
    printList(l3);  // 2 0 2 3

    l4.assign(3, 6);
    printList(l4);  // 6 6 6

    // 交换
    l3.swap(l4);
    printList(l3);  // 6 6 6
    printList(l4);  // 2 0 2 3
}

void test03(){  // list大小操作
    list<int> l1 = {1,9,7,8};
    printList(l1);  // 1 9 7 8
    if(l1.empty()){
        cout << "l1 is empty!" << endl;
    }else{
        cout << "l1.size() = " << l1.size() << endl;
    }
    l1.resize(6, 3);    // 重新指定大小，链表长度增加时以3填充
    printList(l1);  // 1 9 7 8 3 3
    l1.resize(2);   // 链表长度缩小，超出范围的元素删除
    printList(l1);  // 1 9
}

void test04(){  // list插入和删除
    list<int> l;
    l.push_back(9); // 尾插
    l.push_back(8);
    l.push_back(5);
    l.push_front(6);    // 头插
    printList(l);   // 6 9 8 5

    l.pop_back();   // 尾删
    l.pop_front();  // 头删
    printList(l);   // 9 8

    auto it = l.begin();
    it = l.insert(++it, 10); // 返回新元素的位置
    printList(l);   // 9 10 8
    l.erase(++it);  // 删除8，返回下一个元素(end())的位置
    printList(l);   // 9 10

    list<int> l2 = {2,0,1,9};
    l2.insert(l2.begin(), l.begin(), l.end());
    printList(l2);  // 9 10 2 0 1 9

    // 按值移除
    l2.remove(9);
    printList(l2);  // 10 2 0 1

    // 清空
    l2.clear();
    // l2.erase(l2.begin(), l2.end());  // 效果同上
}

void test05(){  // list数据存取
    list<int> l = {6, 7, 8};
    // 不可以使用[]和at方式访问list容器中的元素
    // list本质是链表，不是用连续线性空间存储数据，迭代器也是支持随机访问的
    cout << "l.front() = " << l.front() << endl;    // 6
    cout << "l.back() = " << l.back() << endl;  // 8

    // 迭代器是不支持随机访问的
    auto it = l.begin();
    ++it;   // 正确：支持递增/减
    --it;   // 支持双向
    // it = it + 1;    // 错误：不支持随机访问
}

void test06(){  // list反转和排序
    list<int> l1 = {4,7,6,9,2,3,5};
    printList(l1);  // 4 7 6 9 2 3 5
    l1.reverse();   // 反转
    printList(l1);  // 5 3 2 9 6 7 4
    // 所有不支持随机访问迭代器的容器，不支持标准算法
    // sort(l1.begin(), l2.end());  // 错误：不支持
    l1.sort();  // 成员函数，排序 默认规则从小到大
    printList(l1);  // 2 3 4 5 6 7 9
    l1.sort(compare);   // 降序排序
    printList(l1);  // 9 7 6 5 4 3 2
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