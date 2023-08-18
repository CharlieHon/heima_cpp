#include <iostream>
using namespace std;

// 普通实现

// Java页面
class Java{
public:
    void header(){
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer(){
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left(){
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
    void content(){
        cout << "Java学习路线" << endl;
    }
};

// Python页面
class Python{
public:
    void header(){
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer(){
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left(){
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
    void content(){
        cout << "Python学习路线" << endl;
    }
};

// CPP页面
class Cpp{
public:
    void header(){
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer(){
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left(){
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
    void content(){
        cout << "Cpp学习路线" << endl;
    }
};

// 继承实现页面：减少重复代码
// 语法：class 子类 : 继承方式 父类

// 公共页面
class BasePage{
public:
    void header(){
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer(){
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left(){
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
};

// Java页面
class Java2 : public BasePage{
public:
    void content(){
        cout << "Java学习路线" << endl;
    }
};
// Python页面
class Python2 : public BasePage{
public:
    void content(){
        cout << "Python学习路线" << endl;
    }
};
// Cpp页面
class Cpp2 : public BasePage{
public:
    void content(){
        cout << "C++学习路线" << endl;
    }
};

void test01(){  // 
    cout << "---Java页面---" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "---Python页面---" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "---C++页面---" << endl;
    Cpp c;
    c.header();
    c.footer();
    c.left();
    c.content();
}

void test02(){  // 继承实现
    cout << "---Java页面---" << endl;
    Java2 ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "---Python页面---" << endl;
    Python2 py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "---C++页面---" << endl;
    Cpp2 c;
    c.header();
    c.footer();
    c.left();
    c.content();
}

int main()
{
    // test01();
    test02();
    return 0;
}