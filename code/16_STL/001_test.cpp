#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 案例-评委打分

class Person{
public:
    Person() = default;
    Person(const string &name) : Name(name) {}
    Person(const string &name, const int &s) : Name(name), Score(s) {}
    void getScore(const int &s){    // 评委打分
        this->Score.push_back(s);
    }
    void getAvg(){
        double avg = 0.0;
        int i;
        for(i=0; i<Score.size(); ++i){
            avg += double(Score[i]);
        }
        this->Avg_Price =  avg / i;
    }

    string Name;
    deque<int> Score;
    double Avg_Price;
};

bool compare(const Person &p1, const Person &p2){
    return p1.Avg_Price < p2.Avg_Price; // 按平均分从小到大排序
}

int main()
{
    // 1.创建五名选手
    Person p1("Tom"), p2("David"), p3("Yi"), p4("Charlie"), p5("Bruce");
    vector<Person> vecP = {p1, p2, p3, p4, p5};
    for(auto it=vecP.begin(); it!=vecP.end(); ++it){
        // 2.给五名选手打分
        for(int i=0; i<10; ++i){
            int x;
            cin >> x;
            it->getScore(x);
        }
        // 3.去除最高分、最低分，获取评分值
        sort(it->Score.begin(), it->Score.end());
        it->Score.pop_front();
        it->Score.pop_back();
        it->getAvg();
    }
    // 4.按照平均分排序vector数组
    sort(vecP.begin(), vecP.end(), compare);
    for(int i=0; i<vecP.size(); ++i){
        cout << "Name: " << vecP[i].Name
        << "\tAverage_Score: " << vecP[i].Avg_Price << endl;
    }
    return 0;
}