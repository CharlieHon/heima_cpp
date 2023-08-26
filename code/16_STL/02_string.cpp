#include <iostream>
#include <string>

using namespace std;

// string

void test01(){  // string的构造函数
    string s1;  // 空字符串
    const char *str = "hello";
    string s2(str); // 使用C风格字符串构造
    cout << "s2 = " << s2 << endl;  // hello
    string s3(s2);  // 拷贝构造
    string s4(5, 'h');  // 初始化为5个h
    cout << "s4 = " << s4 << endl;  // hhhhh
}

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

void test08(){  // string子串
    string str = "abcdef";
    string subStr = str.substr(0, 3);   // 从0开始的3个字符
    cout << subStr << endl; // abc

    // 从邮件地址中获取信息
    string address = "2295509496@qq.com";
    string qq = address.substr(0, address.find('@'));
    cout << "qq = " << qq << endl;  // 2295509496
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();
    return 0;
}