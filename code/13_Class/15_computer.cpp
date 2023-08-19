#include <iostream>
#include <string>
using namespace std;

// 多态案例三-电脑组装
// 抽象CPU类
class CPU{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象显卡
class VideoCard{
public:
    // 抽象的计算函数
    virtual void display() = 0;
};

// 抽象内存
class Memory{
public:
    // 抽象的计算函数
    virtual void storage() = 0;
};

// 电脑类
class Computer{
public:
    Computer(CPU *c, VideoCard *v, Memory *m){
        cpu = c;
        vc = v;
        mem = m;
    }
    // 提供工作的函数
    void work(){
        // 让零件工作起来
        cpu->calculate();
        vc->display();
        mem->storage();
    }
    // 提供析构函数，释放3个电脑零件
    ~Computer(){
        if(cpu){
            delete cpu;
            cpu = 0;
        }
        if(vc){
            delete vc;
            vc = 0;
        }
        if(mem){
            delete mem;
            mem = 0;
        }
    }
private:
    CPU *cpu;       // CPU零件指针
    VideoCard *vc;  // 显卡零件指针
    Memory *mem;  // 内存条零件指针
};

// Intel厂商
class IntelCPU : public CPU{
public:
    virtual void calculate(){
        cout << "Intel CPU计算" << endl;
    }
};
class IntelVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "Intel 显卡显示" << endl;
    }
};
class IntelMemory : public Memory{
public:
    virtual void storage(){
        cout << "Intel Memory存储" << endl;
    }
};
// Lenovo厂商
class LenovoCPU : public CPU{
public:
    virtual void calculate(){
        cout << "Lenovo CPU计算" << endl;
    }
};
class LenovoVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "Lenovo 显卡显示" << endl;
    }
};
class LenovoMemory : public Memory{
public:
    virtual void storage(){
        cout << "Lenovo Memory存储" << endl;
    }
};

void test01(){
    // 第一台电脑零件
    CPU *intelC = new IntelCPU;
    VideoCard *intelV = new IntelVideoCard;
    Memory *intelM = new IntelMemory;
    
    // 创建第一台电脑
    Computer *c1 = new Computer(intelC, intelV, intelM);
    c1->work();
    delete c1;

    // 第二台电脑
    Computer *c2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    c2->work();
    delete c2;

    // 第二台电脑
    Computer *c3 = new Computer(new IntelCPU, new LenovoVideoCard, new IntelMemory);
    c3->work();
    delete c3;
}

int main()
{
    test01();
    return 0;
}