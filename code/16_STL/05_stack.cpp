#include <iostream>
#include <stack>

using namespace std;

// stack

void test01(){
    // 特点：先进后出的数据结构
    stack<int> stk;
    // 入栈
    stk.push(10);
    stk.push(20);
    stk.push(30);
    // 只要栈不为空，查看栈顶，并且执行栈操作
    while(!stk.empty()){
        // 查看栈顶元素
        cout << "栈顶元素：" << stk.top() << endl;  // 30 20 10
        // 出栈
        stk.pop();
    }
    cout << "栈的大小：" << stk.size() << endl; // 0
}

int main()
{
    test01();
    return 0;
}