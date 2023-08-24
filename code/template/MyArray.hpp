// 自定义通用数组类
#pragma once
#include <iostream>

template<class T>
class MyArray{
public:
    // 构造函数
    MyArray(int capacity){
        // std::cout << "MyArray(int)" << std::endl;
        this->Capacity = capacity;
        this->Size = 0;
        this->pAddress = new T[this->Capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr){
        // std::cout << "MyArray(const MyArray&)" << std::endl;
        this->Capacity = arr.Capacity;
        this->Size = arr.Size;
        // this->pAddress = arr.pAddress;   // 浅拷贝
        // 深拷贝
        this->pAddress = new T[arr.Capacity];
        // 将arr中的数据都拷贝过来
        for(int i=0; i<this->Size; ++i){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    // operator= 防止浅拷贝问题 a = b = c
    MyArray& operator=(const MyArray &arr){
        // std::cout << "operator=" << std::endl;
        // 先判断原来堆区是否有数据
        if(this->pAddress){
            delete[] this->pAddress;
            this->pAddress = 0;
            this->Capacity = 0;
            this->Size = 0;
        }
        // 深拷贝
        this->Capacity = arr.Capacity;
        this->Size = arr.Size;
        this->pAddress = new T[arr.Capacity];
        for(int i=0; i<arr.Size; ++i){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void push_back(const T &elem){
        // 判断容量是否等于大小
        if(this->Capacity == this->Size){
            return;
        }
        this->pAddress[this->Size++] = elem;    // 在数组末尾插入数据，并更新数组大小
    }

    // 尾删法
    void pop_back(){
        // 让用户访问不到最后一个元素，即尾删
        if(this->Size == 0){
            return;
        }
        --this->Size;
    }

    // 利用下标方式访问数组中的元素
    T operator[](int ix) const{
        // if(ix >= this->Size){
        // }
        return this->pAddress[ix];
    }

    T& operator[](int ix){  // 可以根据对象是否是const进行函数重载
        // if(ix >= this->Size){
        // }
        return this->pAddress[ix];
    }

    // 获取数组的容量
    int capacity() const{
        return this->Capacity;
    }

    // 获取数组的大小
    int size() const{
        return this->Size;
    }

    // 析构函数
    ~MyArray(){
        if(this->pAddress){
            // std::cout << "~MyArray()" << std::endl;
            delete[] this->pAddress;
            this->pAddress = 0;
        }
    }

private:
    // 数组
    T *pAddress;    // 指针指向堆区开辟的真实数组
    // 容量
    int Capacity;
    // 大小
    int Size;
};