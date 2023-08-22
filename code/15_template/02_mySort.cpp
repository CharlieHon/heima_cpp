#include <iostream>
using namespace std;

// 函数模板案例：实现通用对数组进行排序的函数
// 规则：从大到小

template<class T>
void mySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void mySort(T *a, const int n){ // 选择排序
    for(int i=0; i<n-1; ++i){
        int tmp = i;
        for(int j=i+1; j<n; ++j){
            if(a[j] > a[tmp])
                tmp = j;
        }
        mySwap(a[i], a[tmp]);
    }
}

template<typename T>
void printArr(T *a, const int n){   // 通用数组打印函数
    for(int i=0; i<n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    // char a[] = {'c', 'h', 'i', 'n', 'a'};
    char a[] = "china";
    int lena = sizeof(a)/sizeof(*a);
    int b[] = {1, 9, 4, 9, 2, 0, 2, 3};
    int lenb = sizeof(b)/sizeof(*b);

    printArr(a, lena);
    printArr(b, lenb);

    mySort(a, lena);
    mySort(b, lenb);

    printArr(a, lena);
    printArr(b, lenb);

    return 0;
}