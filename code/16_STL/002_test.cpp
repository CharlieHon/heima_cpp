#include <iostream>
#include <string>
#include <list>

using namespace std;

// list排序案例

class Person{
    friend ostream& operator<<(ostream&, const Person&);
    friend bool compare(const Person&, const Person&);
public:
    Person() = default;
    Person(const string &name) : Name(name) {
        this->Age = 18;
        this->Height = 180;
    }
    Person(const string &name, const int &age, const int &height) : Name(name), Age(age), Height(height) {}
    Person(const Person &p){
        this->Age = p.Age;
        this->Height = p.Height;
    }

    Person& operator=(const Person &p){
        this->Age = p.Age;
        this->Height = p.Height;
        return *this;
    }

private:
    string Name;
    int Age;
    int Height;
};

ostream& operator<<(ostream &os, const Person &p){
    os << "name: " << p.Name << " age: " << p.Age << " height: " << p.Height;
    return os;
}

bool compare(const Person &p1, const Person &p2){
    // if(p1.Age == p2.Age){
    //     return p1.Height > p2.Height;
    // }else{
    //     return p1.Age > p2.Age;
    // }
    return (p1.Age!=p2.Age) ? p1.Age<p2.Age : p1.Height>p2.Height;
}

template<class T>
void printList(const list<T> &lst){
    for(auto it=lst.cbegin(); it!=lst.cend(); ++it){
        cout << *it << endl;
    }
}

int main()
{
    Person p1("Tom", 18, 175), p2("Charlie", 22, 180), p3("Bruce", 18, 170), p4("David", 30, 185), p5("Lee", 37, 172);
    list<Person> lst;
    lst.push_front(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);
    lst.push_back(p5);

    cout << "排序前：" << endl;
    printList(lst);
    lst.sort(compare);
    cout << "排序后：" << endl;
    printList(lst);

    return 0;
}