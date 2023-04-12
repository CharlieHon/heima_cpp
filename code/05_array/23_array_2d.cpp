#include<iostream>
using namespace std;

int main()
{
    //二维数组定义方式
    /*
    1. `数据类型 数组名[行数][列数];`
    2. `数据类型 数组名[行数][列数] = {{数据1, 数据2}, {数据3, 数据4}}；`
    3. `数据类型 数组名[行数][列数] = {数据1, 数据2, 数据3, 数据4}；`
    4. `数据类型 数组名[][列数] = {数据1, 数据2, 数据3, 数据4}；`
    */

    //二维数组数组名
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    for(int i=0; i<2; ++i){
        for(int j=0; j<3; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    //1.查看所占内存空间大小
    cout << "二维数组占用内存空间为：" << sizeof(arr) << endl;  //24
    cout << "二维数组第0行占用内存空间为: " << sizeof(arr[0]) << endl;  //12
    //2.查看二维数组的首地址
    cout << "二维数组首地址: " << arr << endl;              //0x61fe00
    cout << "二维数组第0行的首地址: " << arr[0] << endl;    //0x61fe00
    cout << "二维数组第一个元素的地址: " << &arr[0][0] << endl;    //0x61fe00
    cout << "二维数组第1行的首地址: " << arr[1] << endl;    //0x61fe0c  差12个字节
    
    int scores[][3] = {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };
    string names[3] = {"张三", "李四", "王五"};
    for(int i=0; i<3; ++i){
        int sum = 0;
        for(int j=0; j<3; ++j){
            sum += scores[i][j];
        }
        cout << names[i] << "的总分为：" << sum << endl;
    }
    
    return 0;
}