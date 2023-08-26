# 2.STL初始

## 2.1 STL的诞生

- 长久以来，软件界一直希望建立一种可重复利用的东西
- C++的**面向对象**和**泛型编程**思想，目的就是复用性的提升
- 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
- 为了建立数据结构和算法的一套标准，诞生了STL

## 2.2 STL基本概念

- STL(Standard Template Library，**标准模板库**)
- STL从广义上分为：**容器(container)、算法(algorithm)、迭代器(iterator)**
- **容器**和**算法**之间通过**迭代器**进行无缝连接
- STL几乎所有的代码都采用了模板类或者模板函数

## 2.3 STL六大组件

STL大体分为六大部件，分别是**容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器**

1. 容器：各种数据结构，如vector,list,deque,set,map等，用来存放数据
2. 算法：各种常用的算法，如sort,find,copy,for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
6. 空间配置器：负责空间的配置与管理

## 2.4 STL中容器、算法、迭代器

**容器：置物之所也**

STL容器就是将运用**最广泛的一些数据结构**实现出来

常用的数据结构：数组，链表，树，队列，集合，映射表等

这些容器分为**序列式容器**和**关联式容器**两种：

> **序列容器**：强调值得排序，序列容器中的每个元素均有固定的位置
>
> **关联容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系

**算法：问题之解法也**

有限的步骤，解决逻辑或数学上的问题，这一门学科就做算法(Algorithm)

算法分为：**质变算法**和**非质变算法**

质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝、替换、删除等等

非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

**迭代器：容器和算法之间的粘合剂**

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方法。

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针

迭代器种类：

| 种类           | 功能                                                           | 支持运算                                             |
| -------------- | -------------------------------------------------------------- | ---------------------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                               | 只读。支持 `++, ==, !=`                            |
| 输出迭代器     | 对数据的只写访问                                               | 只写，支持 `++`                                    |
| 前向迭代器     | 读写操作，并能向前推进迭代器                                   | 读写，支持 `++, ==, !=`                            |
| 双向迭代器     | 读写操作，并能向前和向后操作                                   | 读写，支持 `++, --`                                |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，<br />功能更强的迭代器 | 读写，支持 `++, --, [n]`<br />`-n, <, <=, >, >=` |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器

## 2.5 容器算法迭代器初识

STL中最常用的容器为 `vector`，可以了解为数组

## 2.5.1 vector存放数据

容器：`vector`

算法：`for_each`

迭代器：`vector<int>::iterator`

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector容器

class Person{
public:
    Person() = default;
    Person(const string &name, const int &age) : Name(name), Age(age) {}

    string Name;
    int Age;
};

void test01(){
    vector<Person> v;
    Person p1("A", 20), p2("B", 26), p3("C", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 遍历容器中的数据
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); ++it){
        cout << "姓名：" << it->Name << " 年龄：" << it->Age << endl;
    }
}

void printVec(int val){
    cout << val << endl;
}

int main()
{
    // 创建一个vector容器，数组
    vector<int> v1;

    // 向容器中插入数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    // 通过迭代器访问容器中的数据
    // vector<int>::iterator it = v1.begin();  // 起始迭代器，指向容器中第一个元素

    // 第一种遍历方式
    // while(it != v1.end()){  // v1.end()返回尾后迭代器，指向最后一个元素的下一个位置
    //     cout << *it << endl;
    //     ++it;
    // }

    // 第二种遍历
    // for(vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it){
    //     cout << *it << endl;
    // }

    // 第三种遍历方式，利用STL提供的遍历算法
    for_each(v1.begin(), v1.end(), printVec);

    // vector存放自定义数据类型
    test01();

    return 0;
}
```

### 2.5.2 Vector容器嵌套容器

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void test01(){
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1, v2, v3, v4, v5;
    for(int i=0; i<5; ++i){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
        v5.push_back(i+5);
    }
    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    // 通过大容器，把所有容器遍历一遍
    for(vector<vector<int>>::iterator it=v.begin(); it!=v.end(); ++it){
        auto it1 = it->begin(); // vector<int>::iterator
        while(it1 != it->end()){
            cout << *it1 << " ";
            ++it1;
        }
        cout << endl;
    }
}

int main()
{
    test01();
/*
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
*/
    return 0;
}
```

### 3.1 string容器

### 3.1.1 string基本概念

**本质：**

- `string`是C++风格的字符串，本质上是一个类

**`string`和 `char *`的区别：**

- `char *`是一个指针
- `string`是一个类，类内部封装了 `char *`，管理这个字符串，是一个 `char *`型的容器

**特点：**

- `string`类内部封装了很多成员方法
- 例如：查找 `find`，拷贝 `copy`，删除 `delete`，替换 `replace`，插入 `insert`
- `string`管理 `char *`所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

### 3.1.2 string构造函数

| 构造函数原型                  |                                          |
| ----------------------------- | ---------------------------------------- |
| `string()`                  | 创建一个空的字符串，例如：string std;    |
| `string(const char *s)`     | 使用字符串s初始化                        |
| `string(const string &str)` | 使用一个string对象初始化另一个string对象 |
| `string(int n, char c)`     | 使用n个字符c初始化                       |

```cpp
void test01(){
    string s1;  // 空字符串
    const char *str = "hello";
    string s2(str); // 使用C风格字符串构造
    cout << "s2 = " << s2 << endl;  // hello
    string s3(s2);  // 拷贝构造
    string s4(5, 'h');  // 初始化为5个h
    cout << "s4 = " << s4 << endl;  // hhhhh
}
```

### 3.1.3 string赋值操作

| 赋值的函数原型                            |                                        |
| ----------------------------------------- | -------------------------------------- |
| `string& operator=(const char *s);`     | `char *`类型字符串赋值给当前的字符串 |
| `string& operator=(const string &s);`   | 把字符串s赋值给当前字符串              |
| `string& operator=(char c);`            | 字符赋值给当前字符串                   |
| `string& assign(const char *s);`        | 把字符串s赋值给当前的字符串            |
| `string& assign(const char *s, int n);` | 把字符串s的前n个字符赋值给当前的字符串 |
| `string& assign(const string &s);`      | 把字符串s赋值给当前字符串              |
| `string& assign(int n, char c);`        | 用n个字符c赋值给当前字符串             |

```cpp
void test02(){  // string赋值操作
  
    string str1, str2, str3, str4, str5, str6, str7;
  
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;  // hello world
  
    str2 = str1;
  
    str3 = 'a';
    cout << "str3 = " << str3 << endl;  // a
  
    str4.assign("hello C++");
    cout << "str4 = " << str4 << endl;  // hello C++
  
    str5.assign("hello C++", 2);
    cout << "str5 = " << str5 << endl;  // he
  
    str6.assign(str5);  // he
  
    str7.assign(3, 'w');
    cout << "str7 = " << str7 << endl;  // www
}
```

### 3.1.4 string字符串拼接

| 字符串拼接                                          | 实现在字符串末尾拼接字符串                  |
| --------------------------------------------------- | ------------------------------------------- |
| `string& operator+=(const char *str)`             | 重载 `+=`操作符                           |
| `string& operator+=(const char c)`                | 重载 `+=`操作符                           |
| `string& operator+=(const string &str)`           | 重载 `+=`操作符                           |
| `string& append(const char *s)`                   | 把字符串s连接到当前字符串结尾               |
| `string& append(char char *s, int n)`             | 把字符串s的前n个字符连接到当前字符串结尾    |
| `string& append(const string &s)`                 | 同 `operator+=(const string &s)`          |
| `string& append(const string &s, int pos, int n)` | 字符串s中从pos开始的n个字符连接到字符串结尾 |

```cpp
void test03(){  // 字符串拼接
  
    // +=
    string str1 = "hello", str2 = "Lee";
    str1 += ",world";
    cout << str1 << endl;   // hello,world
    str1 += '.';
    cout << str1 << endl;   // hello,world.
    str1 += str2;
    cout << str1 << endl;   // hello,world.Lee

    // append
    string str3 = "I", str4 = ",Hon";
    str3.append(" love ");
    cout << str3 << endl;   // I love
    str3.append("China,abd", 5);    // 拼接前5个字符
    cout << str3 << endl;   // I love China
    str3.append(str4);
    cout << str3 << endl;   // I love China,Hon
    str3.append(str4, 1,2); // 从位置1截取2个字符
    cout << str3 << endl;   // I love China,HonHo
}
```


### 3.1.5 string查找和替换

功能描述：

- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串

| 查找和替换                                              | 功能描述                             |
| ------------------------------------------------------- | ------------------------------------ |
| `int find(const string &str, int pos = 0) const;`     | 查找str第一次出现位置，从pos开始查找 |
| `int find(const char *s, int pos = 0) const;`         | 查找s第一次出现位置，从pos开始查找   |
| `int find(const char *s, int pos, int n) const;`      | 从pos位置查找s的前n个字符第一次位置  |
| `int find(const char c, int pos = 0) const;`          | 查找字符c第一次出现位置              |
| `int rfind(const string &str, int pos = npos) const;` | 查找str最后一次位置，从pos开始查找   |
| `int rfind(const char *s, int pos = npos) const;`     | 查找s最后一次位置，从pos开始查找     |
| `int rfind(const char *s, int pos, int n) const;`     | 从pos查找s的前n个字符最后一次位置    |
| `int rfind(const char c, int pos = 0) const;`         | 查找字符c最后一次出现位置            |
| `string& replace(int pos, int n, const string &str);` | 替换从pos开始n个字符为字符串str      |
| `string& replace(int pos, int n, const char *s);`     | 替换从pos开始n个字符为字符串st       |

```cpp
void test04(){  // string查找和替换
    // find
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if(pos == -1){
        cout << "Not Found!" << endl;
    }else{
        cout << "pos = " << pos << endl;    // 3
    }
  
    // rfind：从右往左查找，find从左往右查找
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;    // 7

    // replace
    string str2 = "hello, world";
    str2.replace(1, 3, "Test"); // 从下标1开始将3个字符替换为 Test
    cout << str2 << endl;   // hTesto, world
}
```

总结：

- find查找从左往右，rfind从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置开始，多少个字符，替换成什么样的字符串

### 3.1.6 string字符串比较

字符串之间的比较是按照字符的ASCII码进行对比

- `==`返回 0
- `>`返回 1
- `<`返回 -1

| 字符串比较                              |               |
| --------------------------------------- | ------------- |
| `int compare(const string &s) const;` | 与字符串s比较 |
| `int compare(const char *s) const;`   | 与字符串s比较 |

```cpp
void test05(){  // 字符串比较
    string str1 = "hello", str2 = "hello";
    if(str1.compare(str2) == 0){
        cout << "str1 == str2" << endl;
    }else if(str1.compare(str2) > 0){
        cout << "str1 > str2" << endl;
    }else{
        cout << "str1 < str2" << endl;
    }
}
```

总结：字符串对比主要是用于比较两个字符串是否相等，判断谁打谁小的意义并不是很大

### 3.1.7 string字符存取

`string`中单个字符存取方式有两种：

- `char& operator[](int n);`	// 通过[]方式取字符
- `char& at(int n);`	// 通过at方式获取字符

```cpp
void test06(){  // string字符存取
    string str = "hello";
    // 通过[]访问单个字符
    for(int i=0; i<str.size(); ++i){
        cout << str[i];
    }
    cout << endl;
    // 通过at方式访问单个字符
    for(int i=0; i<str.size(); ++i){
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'w';
    str.at(1) = 'i';
    cout << str << endl;    // willo
}
```

总结：string字符串中单个字符存取有两种方式，利用 `[]`或 `at`

### 3.1.8 string的插入和删除

| 插入和删除                                      | 对string字符串进行插入和删除字符操作 |
| ----------------------------------------------- | ------------------------------------ |
| `string& insert(int pos, const char *s);`     | 插入字符串                           |
| `string& insert(int pos, const string &str);` | 插入字符串                           |
| `string& insert(int pos, int n, char c);`     | 在指定位置插入n个字符 `c`          |
| `string& erase(int pos, int n = pos);`        | 删除从Pos开始的n个字符               |

```cpp
void test07(){  // 字符串插入和删除
    string str = "hello";
    // 插入
    str.insert(1, "111");
    cout << str << endl;    // h111ello
    str.insert(1, 2, 'c');
    cout << str << endl;    // hcc111ello
    // 删除
    str.erase(1, 5);    // hello
    cout << str << endl;
}
```

总结：插入和删除的起始下标都是从0开始的

### 3.1.9 string子串

| 函数原型                                        | 从字符串中获取想要的子串           |
| ----------------------------------------------- | ---------------------------------- |
| `string substr(int pos=0, int n=npos) const;` | 返回由pos开始的n个字符组成的字符串 |

```cpp
void test08(){  // string子串
    string str = "abcdef";
    string subStr = str.substr(0, 3);   // 从0开始的3个字符
    cout << subStr << endl; // abc

    // 从邮件地址中获取信息
    string address = "2295509496@qq.com";
    string qq = address.substr(0, address.find('@'));
    cout << "qq = " << qq << endl;  // 2295509496
}
```

总结：灵活地运用求子串功能，可以在实际开发中获取有效的信息

## 3.2 vector容器

## 3.3 deque容器

## 3.4 案例-评委打分

## 3.5 stack容器

## 3.6 deque容器

## 3.7 list容器

## 3.8 set/multiset容器

## 3.9 map/multimap容器

## END
