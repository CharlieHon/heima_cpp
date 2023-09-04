#include "speechManage.h"

using namespace std;

// ���캯��
SpeechManage::SpeechManage() {
	// ��ʼ������������
	initSpeech();

	// ����12��ѡ��
	createSpeaker();

	// ���������¼
	loadRecord();
}

// ��ʾ�˵�
void SpeechManage::showMenu() {
	cout << "**************************" << endl;
	cout << "*****��ӭ�μ��ݽ�����*****" << endl;
	cout << "***** 1.��ʼ�ݽ����� *****" << endl;
	cout << "***** 2.�鿴�����¼ *****" << endl;
	cout << "***** 3.��ձ�����¼ *****" << endl;
	cout << "***** 0.�˳��������� *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

// 0.�˳�ϵͳ
void SpeechManage::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

// 1.��ʼ����
void SpeechManage::startSpeech() {
	// ��һ�ֱ���
	// 1.��ǩ
	this->speechDraw();
	
	// 2.����
	this->speechContest();

	// 3.��ʾ����
	this->showScore();

	// �ڶ��ֱ���
	++this->m_Index;
	// 1.��ǩ
	this->speechDraw();
	// 2.����
	this->speechContest();
	// 3.��ʾ���ս��
	this->showScore();
	// 4.���������ļ���
	this->saveRecord();

	// ���ñ�������ȡ��¼
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

// ��ʼ������������
void SpeechManage::initSpeech() {
	// �������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	// ��ʼ����������
	this->m_Index = 1;

	// ����¼�������
	this->m_Record.clear();
}

// ����12��ѡ��
void SpeechManage::createSpeaker() {
	string nameSeed = "ABCDEFJHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i) {
		string name = string("ѡ��") + nameSeed[i];
		Speaker sp(name);
		
		// ����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->v1.push_back(i + 10001);

		// ѡ�ֱ���Լ���Ӧѡ�� ���뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

// ��ǩ
void SpeechManage::speechDraw() {
	cout << "�� (" << this->m_Index << ") ����ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1) {
		// ��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (auto it = v1.begin(); it != v1.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

	}
	else {
		// �ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (auto it = v2.begin(); it != v2.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
}

// ����
void SpeechManage::speechContest() {
	cout << "�� (" << this->m_Index << ") �ֱ�����ʽ��ʼ" << endl;
	
	// ׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;
	int num = 0;	// ��¼��Ա���� 6��һ��

	vector<int> v_Src;	// ����ѡ������
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	// ��������ѡ�ֽ��б���
	for (auto it = v_Src.begin(); it != v_Src.end(); ++it) {
		++num;
		// ��ί���
		deque<double> d;
		for (int i = 0; i < 10; ++i) {
			double score = (rand() % 401 + 600) / 10.f;
			// cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());	// ��������
		d.pop_front();	// ȥ����߷�
		d.pop_back();	// ȥ����ͷ�
		
		double sum = accumulate(d.begin(), d.end(), 0.f);	// �ܷ�
		double avg = sum / double(d.size());	// ƽ����
		
		/*
		// ��ӡƽ����
		cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].Name
			<< " ƽ���֣�" << avg << endl;
		*/

		// ��ƽ���ַ��뵽map������
		this->m_Speaker[*it].Score[this->m_Index-1] = avg;
	
		// ��������ݷ��뵽С��������
		groupScore.insert(make_pair(avg, *it));	// (�÷֣�ѡ�ֱ��)
		// ÿ����ȡ��ǰ����
		if (num % 6 == 0) {
			cout << "�� " << num / 6 << " С���������" << endl;
			for (auto iter = groupScore.begin(); iter != groupScore.end(); ++iter) {
				cout << "��ţ�" << iter->second << " ������" << this->m_Speaker[iter->second].Name
					<< " �ɼ���" << this->m_Speaker[iter->second].Score[this->m_Index - 1] << endl;
			}

			// ȡ��ǰ����
			int count = 0;
			for (auto iter = groupScore.begin(); iter != groupScore.end() && count<3; ++iter, ++count) {
				if (this->m_Index == 1) {
					v2.push_back(iter->second);
				}
				else {
					vVictory.push_back(iter->second);
				}
			}
			groupScore.clear();	// С���������
			cout << endl;
		}
	}
	cout << "---------�� (" << this->m_Index << ") �ֱ�����ϣ�---------" << endl;
	system("pause");
}

// ��ʾ��������
void SpeechManage::showScore() {
	cout << "---------�� (" << this->m_Index << ") �ֽ���ѡ����Ϣ���£�---------" << endl;
	vector<int> v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->m_Speaker[*it].Name
			<< " �÷֣�" << this->m_Speaker[*it].Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

// �������
void SpeechManage::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	// ��׷�ӵķ�ʽд�ļ�
	
	// ��ÿ��ѡ�ֵ�����д�뵽�ļ���
	for (auto it = vVictory.begin(); it != vVictory.end(); ++it) {
		ofs << *it << "," << this->m_Speaker[*it].Score[1] << ",";
	}
	ofs << endl;

	// �ر�
	ofs.close();
	cout << "��¼�ѱ���" << endl;
	// �����ļ���Ϊ��״̬
	this->fileIsEmpty = false;
}

// ��ȡ��¼
void SpeechManage::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		// cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	// �ļ����
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);	// �������ȡ�ĵ����ַ��ٷŻ���

	string data;
	int ix = 0;
	while (ifs >> data) {
		vector<string> v;	// ���6��string�ַ���
		int pos = -1;	// ���ҡ�,��λ�õı���
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				// û���ҵ�
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(ix, v));
		++ix;
	}
	ifs.close();
	/*
	for (auto it = this->m_Record.begin(); it != this->m_Record.end(); ++it) {
		cout << "��" << it->first+1 << "��" << "�ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
	}
	*/
}

// ��ʾ�����¼
void SpeechManage::showRecord() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); ++i) {
		cout << "��" << i + 1 << "��"
			<< " �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			<< "\t�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			<< "\t������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

// 3.��ռ�¼
void SpeechManage::clearRecord() {
	cout << "�Ƿ�������ݣ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		// ��ģʽ ios::trunc ������ڣ�ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// ��ʼ������
		this->initSpeech();
		// ����ѡ��
		this->createSpeaker();
		// ��ȡ�����¼
		this->loadRecord();

		cout << "��ճɹ�" << endl;
	}

	system("pause");
	system("cls");
}

// ��������
SpeechManage::~SpeechManage() {

}