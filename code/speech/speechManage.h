#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <deque>
#include <map>
#include "speaker.h"

// 设计演讲比赛管理类
/*
- 提供菜单界面与用户交互
- 对演讲比赛流程进行控制
- 与文件的读写交互
*/
class SpeechManage {
public:
	
	// 构造函数
	SpeechManage();
	
	// 显示菜单
	void showMenu();
	
	// 1.开始比赛
	void startSpeech();
	
	// 抽签
	void speechDraw();
	
	// 比赛
	void speechContest();

	// 显示比赛分数
	void showScore();

	// 保存分数
	void saveRecord();

	// 2.读取记录
	void loadRecord();
	// 显示往届记录
	void showRecord();

	// 3.清空记录
	void clearRecord();
	
	// 0.退出系统
	void exitSystem();
	
	// 析构函数
	~SpeechManage();

	// 初始化容器和属性
	void initSpeech();

	// 创建12名选手
	void createSpeaker();


	// 成员属性
	// 保存第一轮比赛选手编号容器
	std::vector<int> v1;
	// 第一轮晋级选手编号容器
	std::vector<int> v2;
	// 胜出的前三名选手编号容器
	std::vector<int> vVictory;
	// 存放编号以及对应具体选手容器
	std::map<int, Speaker> m_Speaker;
	// 存放比赛轮数
	int m_Index;
	// 判断文件是否为空
	bool fileIsEmpty;
	// 存放往届记录的容器
	std::map<int, std::vector<std::string>> m_Record;
};