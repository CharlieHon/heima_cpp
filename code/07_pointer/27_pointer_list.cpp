#include<iostream>
using namespace std;

void swap1(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *a, const int n){
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-i-1; ++j){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void print_arr(const int * const a, const int n){
    for(int i=0; i<n; ++i){
        cout << a[i];
        if(i != n-1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;   //指向数组首地址的指针

    cout << "第一个元素：" << arr[0] << endl;       //1
    cout << "指针访问第一个元素：" << *p << endl;   //1

    //1.使用指针遍历数组
    for(int i=0; i<10; ++i){
        cout << *p << endl;
        p++;
    }

    //2.指针和函数
    //值传递
    int a = 10, b = 20;
    cout << "a = " << a
        << " b = " << b << endl;    //a = 10 b = 20
    swap1(a, b);
    cout << "a = " << a
        << " b = " << b << endl;    //a = 10 b = 20
    //地址传递
    swap2(&a, &b);
    cout << "a = " << a
        << " b = " << b << endl;    //a = 20 b = 10


    int arr1[] = {4,3,6,9,1,2,10,8,7,5};
    const int n = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr1, n); //4 3 6 9 1 2 10 8 7 5
    bubbleSort(arr1, n);
    print_arr(arr1, n); //1 2 3 4 5 6 7 8 9 10

    return 0;
}