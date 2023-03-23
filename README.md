# heima_cpp

[黑马程序员|C++教程从0到1入门编程](https://www.bilibili.com/video/BV1et411b73Z/?spm_id_from=333.999.0.0&vd_source=e4a60aec69011298c6689621c8498cb6)

## 1 C++初识

### 1.1 第一个C++程序

### 1.2 注释

作用：在代码中加一些说明和解释，方便自己或其他程序员阅读代码

两种格式：

1. 单行注释：`//描述信息`
   - 通常放在一行代码的上方，或者一条语句的末尾，==对该行代码说明==
2. 多行注释：`/*描述信息*/`
   - 通常放在一段代码的上方，==对该段代码整体说明==

> 编辑器在编译代码时，会忽略注释的内容

```cpp
#include<iostream>
using namespace std;

//单行注释
/*
	main是一个程序的入口
	每个程序都必须有这么一个函数
	有且仅有一个
*/
int main()
{
	//在屏幕中输出hello world
	cout << "Hello world" << endl;
	system("pause");
	return 0;
}

```

### 1.3 变量

**作用**： 给一段指定的内存空间起名，方便操作这段内存

**语法**： `数据类型 变量名 = 初始值;`

```cpp
#include<iostream>
using namespace std;

int main()
{
	//变量的定义
	//语法：数据类型 变量名 = 初始值
	int a = 10;
	cout << "a = " << a << endl;
	system("pause");
	return 0;
}
```

### 1.4 常量

**作用**：用于记录程序中不可更改的数据

C++定义常量两种方式：

1. **`#define`宏定义常量**：`#define 常量名 常量值`
   - ==通常在文件上方定义==，表示一个常量
2. **`const`修饰的变量**：`const 数据类型 常量名 = 常量值`
   - ==通常在变量定义前加上关键字const==，修饰该变量为常量，不可修改

```cpp
//1.宏定义
#define week_day 7

int main()
{
	//week_day = 14; //错误，常量值不可修改
	cout << "一周里总共有：" << week_day << "天" << endl;
	//2.const修饰的变量
	const int month = 12;
	//month = 24; //错误，const修饰的变量也成为常量
	cout << "一年总共有 " << month << "月" << endl;
	return 0;
}
```

### 1.5 关键字

**作用**：关键字是C++中预先保留的单词(标识符)
	- 在定义变量或者常量时，不要用关键字

C++关键字如下：

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | unsiged  |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

> 在给变量或者常量起名时，不要使用C++的关键字，否则会产生歧义

### 1.6 标识符命名规则

**作用**：C++规定给标识符(变量、常量)命名时，有一套自己的规则

- 标识符不能是关键字
- **标识符只能由字母、数字、下划线组成**
- 第一个字符必须为**字母或下划线**
- 标识符中字母区分大小写

> 给标识符命名时，争取做到见名知意的效果，方便自己和他人的阅读

```cpp
#include<iostream>
using namespace std;

int main()
{
	int num1 = 10, num2 = 20;
	cout << "sum = " << num1 + num2 << endl;
	return 0;
}

```

## 2 数据类型

C++规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配内存。

### 2.1 整型

**作用**：整型变量表示的是==整数类型==的数据

C++中能够表示整型的类型有以下几种方式，**区别在于所占内存空间不同**：

| 数据类型            | 占用空间                                        | 取值范围       |
| ------------------- | ----------------------------------------------- | -------------- |
| short(短整型)       | 2字节                                           | (-2^15~2^15-1) |
| int(整型)           | 4字节                                           | (-2^31~2^31-1) |
| long(长整型)        | Windows为4字节，Linux为4字节(32位)，8字节(64位) | (-2^31~2^31-1) |
| long long(长长整型) | 8字节                                           | (-2^63~2^63-1) |

```cpp
#include<iostream>
using namespace std;

int main()
{
	//整数
	//1.短整型 (-32768~32767)
	short num1 = 32768; //输出为-1
	//2.整型
	int num2 = 10;
	//3.长整型
	long num3 = 10;
	//4.长长整型
	long long num4 = 10;
	return 0;
}
```

### 2.2 sizeof关键字

**作用**：利用 `sizeof`关键字可以==统计数据类型所占内存大小==

语法：`sizoef(数据类型/变量)`

```cpp
#include<iostream>
using namespace std;

int main()
{
	cout << "short 类型所占内存空间为：" << sizeof(short) << endl;
	cout << "int 类型所占内存空间为：" << sizeof(int) << endl;
	cout << "long 类型所占内存空间为：" << sizeof(long) << endl;
	cout << "long long 类型所占内存空间为：" << sizeof(int) << endl;
	system("pause");
	return 0;
}
```

> 整型数据大小比较：==short < int <= long <= long long==.

### 2.3 实型(浮点型)

**作用**：用于表示==小数==

浮点型变量分为两种：

1. 单精度float
2. 双精度double

两者的区别在于表示的有效数字范围不同。

| 数据类型 | 占用空间 | 有效数字范围    |
| -------- | -------- | --------------- |
| float    | 4字节    | 7位有效数字     |
| double   | 8字节    | 15~16位有效数字 |

```cpp
int main()
{
    //1.单精度 float
    //2.双精度 double
    //默认情况下，输出一个小数，会显示出6位有效数字
    float f1 = 3.1415926f;   //编辑器会将小数默认为double型，在末尾加上f则表示其为float型
    cout << "f1 = " << f1 << endl;

    double d1 = 3.1415926;
    cout << "d1 = " << d1 << endl;

    //统计float和都变了占用内存空间
    cout << "float占用内存空间: " << sizeof(float) << endl;
    cout << "double占用内存空间: " << sizeof(double) << endl;

    //科学计数法
    float f2 = 3e2;
    cout << "f2 = " << f2 << endl;  //300

    float f3 = 3e-2;
    cout << "f3 = " << f3 << endl;  //0.03

    return 0;
}
```

### 2.4 字符型

**字符型**：字符型变量用于显示单个字符

**语法**：`char ch = 'a'`

> 注意1：在显示字符型变量时，用单引号将字符括起来，不要用双引号
>
> 注意2：单引号内智能有一个字符，不可以是字符串

- C/C++中字符型变量只占==1个字节==
- 字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元

```cpp
int main()
{
    //1、字符型变量创建方式
    char ch = 'a';
    cout << ch << endl;
    //2、字符型变量所占内存大小
    cout << "char字符型变量所占内存: " << sizeof(char) << endl;
    //3、字符型变量常见错误
    // char ch2 = "b";  //创建字符型变量时，要用单引号
    // char ch3 = 'abcd';  //单引号内只能有一个字符
    //4、字符型变量对应ASCII编码
    // a-97 A-65
    cout << (int)ch << endl;    //97为字符a对应的ASCII值
    return 0;
}
```

![ASCII表](imgs/01_ASCII.png)

ASCII码大致由以下**两部分**组成：

- ASCII非打印控制字符：ASCII表上的数字**0-31**分配给了 `控制字符`，用于控制像打印机等一些外部设备。
- ASCII打印字符：数字**32-126**分配给了能在键盘上找到的字符，当查看或打印文档时就会出现。

### 2.5 转义字符

**作用**：用于表示一些==不能显示出来的ASCII字符==。常用的转移字符有：`\n \\ \t`

![转义字符](imgs/02_zhuanyizifu.png)

```cpp
int main()
{
    //转义字符
    //换行符    \n
    cout << "hello world\n";

    //反斜杠    "\\"
    cout << "\\" << endl;

    //水平制表符    \t 可以整齐地输出数据
    cout << "aa\thello world" << endl;
    cout << "aaa\thello world" << endl;

    return 0;
}
```

### 2.6 字符串

**作用**：用于表示一串字符

**两种风格**

1. C风格字符串：`char 变量名[] = "字符串值";`
2. C++风格字符串：`string 变量名 = "字符串值";`

```cpp
int main()
{
    //1、C风格字符串
    //char 字符串 []
    //等号后面要用双引号包含起来字符串
    char str1[] = "hello world";
    cout << str1 << endl;

    //2、C++风格字符串
    //包含头文件 #include<string>
    string str2 = "hello world";
    cout << str2 << endl;

    return 0;
}
```

### 2.7 布尔类型 bool

**作用**：布尔数据类型代表真或假的值

bool类型只有两个值：

- true: 真(本质为1)
- false: 假(本质为0)

**bool类型占==1个字节==大小**

```cpp
int main()
{
    //1、创建bool数据类型
    bool flag = true;   //true代表真
    cout << flag << endl;

    flag = false;       //false代表假
    cout << flag << endl;

    //2、查看bool类型所占空间
    cout << "bool类型所占内存空间: " << sizeof(bool) << endl;

    return 0;
}
```

### 2.8 数据的输入

**作用**：用于从键盘获取数据

**关键字**：`cin`

**语法**：`cin >> 变量;`

```cpp
int main()
{
    //1、整型
    int a;
    cout << "请给整型变量a赋值:" << endl;
    cin >> a;
    cout << "a = " << a << endl;

    //2、浮点型
    float f = 3.14f;
    cout << "请给浮点型变量f赋值:" << endl;
    cin >> f;
    cout << "f = " << f << endl;

    //3、字符型
    char ch = 'a';
    cout << "请给字符型变量ch赋值:" << endl;
    cin >> ch;
    cout << "ch = " << ch << endl;

    //4、字符串型
    string str = "hello";
    cout << "请给字符串str赋值:" << endl;
    cin >> str;
    cout << "str = " << str << endl;


    //5、bool型
    bool flag = true;
    cout << "请给布尔变量flag赋值:" << endl;
    cin >> flag;
    cout << "flag = " << flag << endl;

    system("pause");
    return 0;
}
```


## 3 运算符

**作用**：用于执行代码的运算

| 运算符类型 | 作用                                   |
| ---------- | -------------------------------------- |
| 算数运算符 | 用于处理四则运算                       |
| 赋值运算符 | 用于将表达式的值赋给变量               |
| 比较运算符 | 用于表达式的比较，并返回一个真值或假值 |
| 逻辑运算符 | 用于根据表达式的值返回真值或假值       |

### 3.1 算数运算符

**作用**：用于处理四则运算

算数运算符包括以下符号：

| 运算符 | 术语       | 示例       | 结果     |
| ------ | ---------- | ---------- | -------- |
| +      | 正号       | +3         | 3        |
| -      | 负号       | -3         | -3       |
| +      | 加         | 10+5       | 15       |
| -      | 减         | 10-5       | 5        |
| *      | 乘         | 10*5       | 50       |
| /      | 除         | 10/5       | 2        |
| %      | 取模(取余) | 10%3       | 1        |
| ++     | 前置递增   | a=2;b=++a  | a=3;b=3; |
| ++     | 后置递增   | a=2;b=a++; | a=3;b=2; |
| --     | 前置递减   | a=2;b=--a; | a=1;b=1; |
| --     | 后置递减   | a=2;b=a--; | a=1;b=2; |

```cpp
int main()
{
    //加减乘除
    int a1 = 10;
    int b1 = 3;

    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl;    //两个整数相除，结果仍是整数，将小数部分去除

    int a2 = 10;
    int b2 = 20;
    int c2 = 0;

    cout << a2 / b2 << endl;    //0
    // cout << a2 / c2 << endl;    //错误！两个数相除，除数不可以为0

    //两个小数相除
    double d1 = 0.5;
    double d2 = 0.22;
    cout << d1 / d2 << endl;    //2.27273

    return 0;
}
```

> 总结：在除法运算中，除数不能为0

```cpp
    //取模就是求余数
    int a3 = 10;
    int b3 = 3;
    int c3 = 20;
    int d3 = 0;

    cout << a3 % b3 << endl;    //1
    cout << a3 % c3 << endl;    //10
    // cout << a3 % d3 << endl;    //保存，两个数相除，除数不能为0，也不能取模

    //两个小数是不可以做取模运算的
```

> 只有整数变量可以进行取模运算

```cpp
    //1、前置递增
    int a = 10;
    ++a;
    cout << "a = " << a << endl;    //11

    //2、后置递增
    int b = 10;
    b++;
    cout << "b = " << b << endl;    //11

    //前置递增：先让变量+1，然后进行表达式运算
    int x1 = 10;
    int y1 = ++x1 * 10;
    cout << "x1 = " << x1 << endl;  //11
    cout << "y1 = " << y1 << endl;  //110
    //后置递增：先进行表达式运算，后让变量+1
    int x2 = 10;
    int y2 = x2++ * 10;
    cout << "x2 = " << x2 << endl;  //11
    cout << "y2 = " << y2 << endl;  //100
```

> 总结：前置递增先对变量进行++，再计算表达式，后置递增相反。

### 3.2 赋值运算符

作用：用于将表达式的值赋给变量

赋值运算符包含以下几个符号：

| 运算符 | 术语   | 示例       | 结果     |
| ------ | ------ | ---------- | -------- |
| =      | 赋值   | a=2;b=3;   | a=2;b=3; |
| +=     | 加等于 | a=0;a+=2;  | a=2;     |
| -=     | 减等于 | a=5;a-=2;  | a=3;     |
| *=     | 乘等于 | a=2;a*=3;  | a=6;     |
| /=     | 除等于 | a=10;a/=2; | a=5;     |
| %=     | 模等于 | a=3;a%=2;  | a=1;     |

### 3.3 比较运算符

**作用**：用于表达式的比较，并返回一个真值或假值

比较运算符有以下符号：

| 运算符 | 术语     | 示例 | 结果 |
| ------ | -------- | ---- | ---- |
| ==     | 相等于   | 4==3 | 0    |
| !=     | 不等于   | 4!=3 | 1    |
| <      | 小于     | 4<3  | 0    |
| >      | 多于     | 4>3  | 1    |
| <=     | 小于等于 | 4<=3 | 0    |
| >=     | 大于等于 | 4>=3 | 1    |

```cpp
    //比较运算符
    // ==
    int a = 10;
    int b = 20;
    cout << (a == b) << endl;   // 0
    cout << (a != b) << endl;   // 1

    // < >
    cout << (a < b) << endl;    // 1
    cout << (a > b) << endl;    // 0

    // <= >=
    cout << (a <= b) << endl;   // 1
    cout << (a >= b) << endl;   // 0
```

### 3.4 逻辑运算符

**作用**：用于根据表达式的值返回真值或假值

逻辑运算符有以下符号：

| 运算符 | 术语 | 示例     | 结果                                                     |
| ------ | ---- | -------- | -------------------------------------------------------- |
| !      | 非   | !a       | 如果a为假，则!a为真；如果a为真，则!a为假。               |
| &&     | 与   | a && b   | 如果a和b都为真，则结果为真，否则为假。                   |
| `\\` | 或   | `a\\b` | 如果a和b有一个为真，则结果为真，二者都为假时，结果为假。 |

> 表格中打不出 `|`符号，所以以 `\`代替之。
>
> 逻辑与 `&&`：同真为真，其余为假
>
> 逻辑或 `||`：桶假为假，其余为真

```cpp
int main()
{
    //逻辑运算符 --- 非 !：真变假，假变真
    int a = 10;
    cout << !a << endl;     //0
    cout << !!a << endl;    //1

    //逻辑运算符 --- 与 &&: 同真为真，其余为假
    int b = 10;
    cout << (a && b) << endl;   //1
    a = 0, b = 10;
    cout << (a && b) << endl;   //0
    a = 0, b = 0;
    cout << (a && b) << endl;   //0

    //逻辑运算符 --- 或 ||: 
    a = 10, b = 10;
    cout << (a || b) << endl;   //1
    a = 0, b = 10;
    cout << (a || b) << endl;   //1
    a = 0, b = 0;
    cout << (a || b) << endl;   //0
    return 0;
}
```
