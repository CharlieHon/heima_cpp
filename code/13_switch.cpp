#include<iostream>
using namespace std;

int main()
{
    //switch: 给电影打分
    int score;
    cout << "Enter your score: " << endl;
    cin >> score;
    cout << "You scored: " << score << endl;
    switch(score){
        case 5:
            cout << "Best" << endl;
            break;
        case 4:
            cout << "Good" << endl;
            break;
        case 3:
            cout << "OK" << endl;
            break;
        default:
            cout << "Low" << endl;
            break;
    }

    return 0;
}