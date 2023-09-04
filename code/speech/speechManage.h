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

// ����ݽ�����������
/*
- �ṩ�˵��������û�����
- ���ݽ��������̽��п���
- ���ļ��Ķ�д����
*/
class SpeechManage {
public:
	
	// ���캯��
	SpeechManage();
	
	// ��ʾ�˵�
	void showMenu();
	
	// 1.��ʼ����
	void startSpeech();
	
	// ��ǩ
	void speechDraw();
	
	// ����
	void speechContest();

	// ��ʾ��������
	void showScore();

	// �������
	void saveRecord();

	// 2.��ȡ��¼
	void loadRecord();
	// ��ʾ�����¼
	void showRecord();

	// 3.��ռ�¼
	void clearRecord();
	
	// 0.�˳�ϵͳ
	void exitSystem();
	
	// ��������
	~SpeechManage();

	// ��ʼ������������
	void initSpeech();

	// ����12��ѡ��
	void createSpeaker();


	// ��Ա����
	// �����һ�ֱ���ѡ�ֱ������
	std::vector<int> v1;
	// ��һ�ֽ���ѡ�ֱ������
	std::vector<int> v2;
	// ʤ����ǰ����ѡ�ֱ������
	std::vector<int> vVictory;
	// ��ű���Լ���Ӧ����ѡ������
	std::map<int, Speaker> m_Speaker;
	// ��ű�������
	int m_Index;
	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	// ��������¼������
	std::map<int, std::vector<std::string>> m_Record;
};