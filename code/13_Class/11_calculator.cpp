#include <iostream>
#include <string>
using namespace std;

// 计算器类

class Calculator{   // 普通函数实现
public:
    Calculator(const int &n1, const int n2) : Num1(n1), Num2(n2) {}
    int getRes(const string &op){
        if(op == "+"){
            return Num1 + Num2;
        }else if(op == "-"){
            return Num1 - Num2;
        }else if(op == "*"){
            return Num1 * Num2;
        }else if(op == "/"){
            return Num1 / Num2;
        }else{
            cout << "Invalid operator!" << endl;
            return -1;
        }
        // 如果想扩展新的功能，需要修改源码
        // 在真实开发中提倡 开闭原则
        // 开闭原则：对拓展进行开放，对修改进行关闭
    }
    int Num1;
    int Num2;
};

// 利用多态实现计算器
// 优点：
// 1.组织结构清晰
// 2.可读性强
// 3.扩展性高，方便维护
class AbstractCalculator{
public:
    virtual int getRes(){
        return 0;
    }
    int Num1;
    int Num2;
};

// 加法计算器类
class Add : public AbstractCalculator{
public:
    int getRes(){
        return Num1 + Num2;
    }
};
// 减法计算器类
class Sub : public AbstractCalculator{
public:
    int getRes(){
        return Num1 - Num2;
    }
};
// 乘法计算器类
class Multi : public AbstractCalculator{
public:
    int getRes(){
        return Num1 * Num2;
    }
};
// 除法计算器类
class Divide : public AbstractCalculator{
public:
    int getRes(){
        return Num1 / Num2;
    }
};

void test01(){  // 测试 普通函数实现的计算器
    Calculator c(10, 5);
    cout << c.Num1 << " + " << c.Num2 << " = " << c.getRes("+") << endl;
    cout << c.Num1 << " - " << c.Num2 << " = " << c.getRes("-") << endl;
    cout << c.Num1 << " * " << c.Num2 << " = " << c.getRes("*") << endl;
    cout << c.Num1 << " / " << c.Num2 << " = " << c.getRes("/") << endl;
}

void test02(){  // 测试 多态实现的计算器
    // 多态使用条件
    // 父类指针或引用指向子类对象
    // 加法计算
    AbstractCalculator *abc = new Add;  // 指向
    abc->Num1 = 10;
    abc->Num2 = 5;
    cout << abc->Num1 << " + " << abc->Num2 << " = " << abc->getRes() << endl;
    // 用完后销毁
    delete abc;
    // 减法运算
    abc = new Sub;
    abc->Num1 = 10;
    abc->Num2 = 5;
    cout << abc->Num1 << " - " << abc->Num2 << " = " << abc->getRes() << endl;
    delete abc;
    // 乘法运算
    abc = new Multi;
    abc->Num1 = 10;
    abc->Num2 = 5;
    cout << abc->Num1 << " * " << abc->Num2 << " = " << abc->getRes() << endl;
    delete abc;
    // 除法运算
    abc = new Divide;
    abc->Num1 = 10;
    abc->Num2 = 5;
    cout << abc->Num1 << " / " << abc->Num2 << " = " << abc->getRes() << endl;
    delete abc;
}

int main()
{
    // test01();
    test02();
    return 0;
}
