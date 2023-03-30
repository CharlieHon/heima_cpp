#include<iostream>
using namespace std;

//打印输出数组a,长度为n
void print_array(int *a, const int n){
    for(int i=0; i<n; ++i){
        cout << a[i];
        if(i < n-1)
            cout << " ";
    }
    cout << endl;
}

void bubble_sort(int *a, const int n){
    for(int i=0; i<n-1; ++i){   //总共排序轮数为 元素个数-1
        for(int j=0; j<n-1-i; ++j){ //内层循环对次数 元素个数-排序轮数-1
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int n = sizeof(a)/sizeof(a[0]); //数组大小

    print_array(a, n);  //4 2 8 0 5 7 1 3 9
    bubble_sort(a, n);
    print_array(a, n);  //0 1 2 3 4 5 7 8 9

    return 0;
}