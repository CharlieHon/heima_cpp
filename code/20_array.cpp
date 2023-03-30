#include<iostream>
using namespace std;

int main()
{
    //数组
    /*
    1. `数据类型 数组名[数组长度]; `
    2. `数据类型 数组名[数组长度] = {值1, 值2 ...};`
    3. `数据类型 数组名[] = {值1, 值2, ...};`
    */
    int arr[3];
    //给数组中的元素进行赋值
    arr[0] = 1, arr[1] = 2, arr[2] = 3;
    //访问数据元素
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;

    int arr2[5] = {9, 8, 5};
    //利用循环 输出数组中的元素
    //如果在初始化数据时，没有全部填写完，会用0来填补剩余数据
    for(int i=0; i<5; ++i){
        cout << arr2[i] << endl;
    }

    //定义数组时，必须有初始长度
    int arr3[] = {2, 0, 2, 3, 0, 3, 2, 7};
    for(int i=0; i<8; ++i){
        cout << arr3[i] << endl;
    }

    return 0;
}