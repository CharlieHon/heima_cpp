#include <iostream>
#include <string>

using namespace std;

// 函数对象(仿函数)
/*
1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
2.函数对象超出普通函数的概念，函数对象可以有自己的状态
3.函数对象可以作为参数传递
*/
class MyAdd{
public:
    int operator()(int v1, int v2){
        return v1 + v2;
    }
};

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01(){
    MyAdd myadd;
    cout << myadd(10, 10) << endl;  // 20
}

// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{
public:
    MyPrint() : count(0) {}
    void operator()(string test){
        cout << test << endl;
        ++count;
    }
    int count;  // 内部自己状态
};

void test02(){
    MyPrint myprint;
    myprint("Hello, world");    // Hello, world
    myprint("Hello, world");
    myprint("Hello, world");
    cout << "myprint调用次数：" << myprint.count << endl;
}

// 3.函数对象可以作为参数传递
void doPrint(MyPrint &mp, const string &s){
    mp(s);
}
void test03(){
    MyPrint myPrint;
    doPrint(myPrint, "Hello, C++");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}