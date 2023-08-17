#include <iostream>
using namespace std;

// 递增运算符重载

class MyInteger{    // 自定义整型变量
    friend ostream& operator<<(ostream&, const MyInteger&);
public:
    MyInteger() : Num(0) {}

    // 重载前置++运算符
    MyInteger& operator++(){    // 前置递增返回引用是为了一直对一个对象进行操作
        ++Num;          // 先进行加运算
        return *this;   // 再将自身返回
    }
    // 重载后置++运算符
    MyInteger operator++(int){ // int代表占位参数，可以用于区分前置和后置递增
        // 先记录当时结果
        MyInteger tmp = *this;
        // 后递增
        Num++;
        return tmp; // 后置递增返回值(不能返回局部对象的引用)
    }

    // 重载前置递减运算符--
    MyInteger& operator--(){
        --Num;
        return *this;
    }
    // 重载后置递减运算符
    MyInteger operator--(int){
        MyInteger tmp = *this;
        Num--;
        return tmp;
    }

private:
    int Num;
};

// 重载左移运算符
ostream& operator<<(ostream &os, const MyInteger &m){
    os << m.Num;
    return os;
}

void test01(){  // 前置递增
    MyInteger a, b;
    cout << "++(++a): " << ++(++a) << endl;
    cout << "--(--b): " << --(--b) << endl;
}

void test02(){  // 后置递增
    MyInteger a, b;
    cout << "a++: " << a++ << endl;
    cout << "b--: " << b-- << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}