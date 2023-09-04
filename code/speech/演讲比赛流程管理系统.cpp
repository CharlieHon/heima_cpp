#include <iostream>
#include <ctime>
#include "speechManage.h"

using namespace std;

int main()
{
	// ���������
	srand((unsigned)time(NULL));

	SpeechManage sm;	// �����ݽ�����������

	// ���Դ���12��ѡ��
	/*
	for (auto it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); ++it) {
		cout << "��ţ�" << it->first
			<< " ������" << it->second.getName()
			<< " ��һ�ַ�����" << it->second.getScore1()
			<< " �ڶ��ַ�����" << it->second.getScore2()
			<< endl;
	}
	*/

	int choice = 0;
	while (true) {
		sm.showMenu();	// ��ʾ�˵�
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1:	// ��ʼ����
			sm.startSpeech();
			break;
		case 2:	// �鿴��¼
			sm.showRecord();
			break;
		case 3:	// ��ռ�¼
			sm.clearRecord();
			break;
		case 0:	// �˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");	// ����
			break;
		}
	}
	return 0;
}