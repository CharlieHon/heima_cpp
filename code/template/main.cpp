#include "MyArray.hpp"
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;

// 1.测试构造函数
void test01(){
    MyArray<int> arr1(5);   // 有参构造

    MyArray<int> arr2(arr1);    // 拷贝构造
    
    MyArray<int> arr3(100);
    arr3 = arr1;    // operator=
/*
MyArray(int)
MyArray(const MyArray&)
MyArray(int)
operator=
~MyArray()
~MyArray()
~MyArray()
*/
}

// 打印输出
template<class T>
void printArr(const MyArray<T> &arr){
    for(int i=0; i<arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 2.测试容器操作
void test02(){
    MyArray<int> arr1(5);
    
    for(int i=0; i<5; ++i){
        arr1.push_back(i);  // 尾插
    }
    cout << "打印输出：" << endl;
    printArr(arr1); // 0 1 2 3 4
    
    arr1[0] = 6;
    printArr(arr1); // 6 1 2 3 4
    
    cout << "arr1.capacity = " << arr1.capacity() << endl;  // 5
    cout << "arr1.size = " << arr1.size() << endl;  // 5
    
    cout << "arr1.pop_back():" << endl;
    arr1.pop_back();    // 尾删
    cout << "arr1.capacity = " << arr1.capacity() << endl;  // 5
    cout << "arr1.size = " << arr1.size() << endl;  // 4
}

// 3.测试自定义数据类型
void test03(){
    Person p1("Tom", 23), p2("Charlie", 18), p3("Bruce", 37), p4 = p1;
    MyArray<Person> arr(5);
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    cout << "arr.capacity: " << arr.capacity() << endl; // 5
    cout << "arr.size: " << arr.size() << endl; // 4
    for(int i=0; i<arr.size(); ++i){
        cout << arr[i] << endl;
    }
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}