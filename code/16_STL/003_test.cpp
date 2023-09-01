#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

#define CEHUA 1
#define MEISHU 2
#define YANFA 3

// 员工分组案例
class Worker{
public:
    Worker() = default;
    Worker(const string &name, const int &salary) : Name(name), Salary(salary) {}
    string Name;
    int Salary;
};

// 创建员工数组
void createWorker(vector<Worker> &vW){
    string nameSeed = "ABCDEFGHIJK";
    for(int i=0; i<10; ++i){
        Worker w;
        w.Name = string("员工") + nameSeed[i];
        w.Salary = rand()%10001 + 10000;
        // 将员工放到容器中
        vW.push_back(w);
    }
}

// 员工分组
void setGroup(const vector<Worker> &vW, multimap<int, Worker> &mp){
    for(auto it=vW.cbegin(); it!=vW.cend(); ++it){
        // 产生随机部门编号
        int deptId = rand()%3 + 1;
        // 将员工擦汗如到分组中
        // key为部门编号，value为worker
        mp.insert(make_pair(deptId, *it));
    }
}

// 分组显示员工
void showWorkerByGroup(const multimap<int, Worker> &m){
    cout << "策划部门：" << endl;
    multimap<int, Worker>::const_iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for(; index<count && pos!=m.cend(); ++pos, ++index){
        cout << "姓名：" << pos->second.Name << " 工资：" << pos->second.Salary << endl;
    }
    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for(; index<count && pos!=m.cend(); ++pos, ++index){
        cout << "姓名：" << pos->second.Name << " 工资：" << pos->second.Salary << endl;
    }
    cout << "研发部门：" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for(; index<count && pos!=m.cend(); ++pos, ++index){
        cout << "姓名：" << pos->second.Name << " 工资：" << pos->second.Salary << endl;
    }
}

void printWorker(vector<Worker> &vW){   // 打印输出vector中员工信息
    for(auto it=vW.cbegin(); it!=vW.cend(); ++it){
        cout << "姓名：" << it->Name << " 年龄：" << (*it).Salary << endl;
    }
    cout << endl;
}

int main()
{
    srand((unsigned int)time(NULL));
    // 1.创建员工
    vector<Worker> w;
    createWorker(w);    // 创建员工
    // printWorker(w); // 打印员工信息

    // 2.员工分组
    multimap<int, Worker> mp;
    setGroup(w, mp);

    // 3.分组显示成员
    showWorkerByGroup(mp);

    return 0;
}