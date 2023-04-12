#include<iostream>
using namespace std;

void print_array(int *a, const int n){
    for(int i=0; i<n; ++i){
        cout << a[i];
        if(i != n-1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    //一维数组名称用途
    /*
    1. 可以统计整个**数组在内存中的长度**
    2. 可以获取数组在**内存中的首地址**
     */

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;  //40=4*10
    cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;   //4
    cout << "数组中元素个数：" << sizeof(arr)/sizeof(arr[0]) << endl;   //10

    cout << "数组的首地址：" << arr << endl;    //0x61fdf0
    cout << "数组中第一个元素的地址：" << &arr[0] << endl;  //0x61fdf0
    cout << "数组中第二个元素的地址：" << &arr[1] << endl;  //0x61fdf4 相差4个字节

    //数组名是常量，不可以进行赋值操作

    int arr1[5];
    for(int i=0; i<5; ++i){
        cin >> arr1[i];
    }
    //寻找最大值
    int max = -1;
    for(int i=0; i<5; ++i){
        if(arr1[i] > max)
            max = arr1[i];
    }

    cout << "最大值为：" << max << endl;

    int length = sizeof(arr1)/sizeof(arr1[0]);
    cout << "原始数组为：" << endl;
    print_array(arr1, length);

    //two pointer
    int start = 0, end = length-1;
    for(int i=0, j=end; i<j; ++i,--j){
        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }
    cout << "逆置后数组为：" << endl;
    print_array(arr1, length);

    return 0;
}