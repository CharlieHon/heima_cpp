#include<iostream>
using namespace std;

int main()
{
    //goto语句
    cout << "1.xxxx" << endl;
    cout << "2.xxxx" << endl;
    goto FLAG;
    cout << "3.xxxx" << endl;
    FLAG:
    cout << "4.xxxx" << endl;
    return 0;
}