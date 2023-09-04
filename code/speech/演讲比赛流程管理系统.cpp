#include <iostream>
#include <ctime>
#include "speechManage.h"

using namespace std;

int main()
{
	// 随机数种子
	srand((unsigned)time(NULL));

	SpeechManage sm;	// 创建演讲比赛管理类

	// 测试创建12名选手
	/*
	for (auto it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); ++it) {
		cout << "编号：" << it->first
			<< " 姓名：" << it->second.getName()
			<< " 第一轮分数：" << it->second.getScore1()
			<< " 第二轮分数：" << it->second.getScore2()
			<< endl;
	}
	*/

	int choice = 0;
	while (true) {
		sm.showMenu();	// 显示菜单
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1:	// 开始比赛
			sm.startSpeech();
			break;
		case 2:	// 查看记录
			sm.showRecord();
			break;
		case 3:	// 清空记录
			sm.clearRecord();
			break;
		case 0:	// 退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");	// 清屏
			break;
		}
	}
	return 0;
}